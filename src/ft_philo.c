/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:35:16 by ehakam            #+#    #+#             */
/*   Updated: 2021/12/16 22:33:37 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_philo.h"

/*
** Initialize all Arguments and check for agrs errors
*/
t_params	*init_params(int count, char **args)
{
	t_params	*params;

	if (count > 6 || count < 3 || !m_is_number(args[1])
	|| !m_is_number(args[2]) || !m_is_number(args[3])
	|| !m_is_number(args[4]) || (count == 6 && !m_is_number(args[5])))
	{
		m_errno(EARGS);
		return (NULL);
	}
	params = (t_params *)malloc(sizeof(t_params));
	if (!params || pthread_mutex_init(&params->pmtx, NULL) != 0)
	{
		if (params)
			free(params);
		m_errno(ENOMEM);
		return (NULL);
	}
	params->must_eat = count == 6;
	params->n_philos = m_aton(args[1]);
	params->t_die = m_aton(args[2]) * 1000;
	params->t_eat = m_aton(args[3])  * 1000;
	params->t_sleep = m_aton(args[4]) * 1000;
	params->n_eat = -1;
	if (params->must_eat)
		params->n_eat = m_aton(args[5]);
	return (params);
}

/*
** Destory a list fork objects
*/
void		destroy_forks(t_fork *forks, int last_index)
{
	size_t		i;

	i = 0;
	while (i < last_index)
		pthread_mutex_destroy(&forks[i++].mtx);
	free(forks);
}

/*
** Initialize a list fork objects
*/
t_fork		*init_forks(size_t count)
{
	size_t	i;
	t_fork	*forks;

	forks = (t_fork *)malloc(sizeof(t_fork) * (count));
	if (!forks)
	{
		m_errno(ENOMEM);
		return (NULL);
	}
	i = 0;
	while (i < count)
	{
		forks[i].id = i;
		if (pthread_mutex_init(&forks[i].mtx, NULL) != 0)
		{
			m_errno(ENOMEM);
			destroy_forks(forks, i);
			return (NULL);
		}
		i++;
	}
	return (forks);
}

/*
** Destory everything except threads
*/
int			destroy_all(t_params *params, t_fork *forks)
{
	int		i;
	size_t	count;
	
	i = 0;
	count = 0;
	if (params)
	{
		count = params->n_philos;
		pthread_mutex_destroy(&params->pmtx);
		free(params);
	}
	if (forks)
		destroy_forks(forks, count);
	return (0);
}

/*
** Initialize a list state object for each philo
*/
t_state		*init_state(t_params *params, t_fork *forks)
{
	int			total_meals;
	size_t		i;
	t_state		*state;
	useconds_t	start_time;
	
	state = (t_state *)malloc(sizeof(t_state) * params->n_philos);
	if (!state)
	{
		destroy_all(params, forks);
		m_errno(ENOMEM);
		return (NULL);
	}
	i = 0;
	start_time = get_current_time();
	total_meals = 0;
	while (i < params->n_philos)
	{
		state[i].id = i;
		state[i].last_meal_time = get_current_time();
		state[i].params = params;
		state[i].forks = forks;
		state[i].init_time = start_time;
		state[i].total_finished_meals = &total_meals;
		++i;
	}
	return (state);
}

/*
** Start threading...
*/
int			start_threads(t_state *state)
{
	size_t			i;
	pthread_t		supervisor;
	const size_t	count = state->params->n_philos;

	i = 0;
	while (i < count)
		pthread_create(&state->philo_thread, NULL, &routine, &state[i++]);
	pthread_create(&supervisor, NULL, &super_routine, state);
	pthread_join(supervisor, NULL);
	return 0;
}


int			main(int ac, char **av)
{
	t_fork		*forks;
	t_params	*params;
	t_state		*state;

	m_errno(ENOERROR);
	params = init_params(ac, av);
	if (m_is_error())
		return (m_put_error());
	forks = init_forks(params->n_philos);
	if (m_is_error())
		return (m_put_error());
	state = init_state(params, forks);
	if (m_is_error())
		return (m_put_error());
	start_threads(state);
	if (m_is_error())
		return (m_put_error());
	return (0);
}
