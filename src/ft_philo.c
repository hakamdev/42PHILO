/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:35:16 by ehakam            #+#    #+#             */
/*   Updated: 2021/12/14 23:25:48 by ehakam           ###   ########.fr       */
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
	params->t_die = m_aton(args[2]);
	params->t_eat = m_aton(args[3]);
	params->t_sleep = m_aton(args[4]);
	if (params->must_eat)
		params->n_eat = m_aton(args[5]);
	return (params);
}

/*
** Initialize a list philo objects
*/
t_philo		*init_philos(size_t count)
{
	size_t	i;
	t_philo	*philos;

	philos = (t_philo *)malloc(sizeof(t_philo) * (count));
	if (!philos)
	{
		m_errno(ENOMEM);
		return (NULL);
	}
	i = 0;
	while (i < count)
	{
		philos[i].id = i;
		i++;
	}
	return (philos);
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
int			destroy_all(t_params *params, t_philo *philos, t_fork *forks)
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
	if (philos)
		free(philos);
	if (forks)
		destroy_forks(forks, count);
	return (0);
}

/*
** Initialize a list state object for each philo
*/
t_state		*init_state(t_params *params, t_philo *philos, t_fork *forks)
{
	size_t		i;
	t_state		*state;
	
	state = (t_state *)malloc(sizeof(t_state) * params->n_philos);
	if (!state)
	{
		destroy_all(params, philos, forks);
		m_errno(ENOMEM);
		return (NULL);
	}
	i = 0;
	while (i < params->n_philos)
	{
		state[i].id = i;
		state[i].args = params;
		state[i].philos = philos;
		state[i].forks = forks;
		++i;
	}
	return (state);
}

/*
** Start threading...
*/
int			start_threads(t_philo *philos)
{
	return 0;
}

/*
** Start listening on the threads using a supervisor thread...
*/
int			start_supervisor(t_state *state)
{
	return 0;
}

/*
** Start the Philo Machine...
*/
int			start_philo_machine(t_state *state)
{
	dprintf(2, "Starting state machine");
	t_params *p = state->args;
	t_philo *ph = state->philos;
	t_fork *f = state->forks;
	dprintf(2, "RAPAM:\nn_philos\t\t%zu\nt_die\t\t%zu\nt_eat\t\t%zu\nt_slp\t\t%zu\nn_eat\t\t%zu\n",
		p->n_philos, p->t_die, p->t_eat, p->t_sleep, p->n_eat);
	dprintf(2, "PHILOS:\n");
	for (size_t i = 0; i < p->n_philos; i++)
	{
		dprintf(2, "PHILO ID %d\n", ph[i].id);
	}

	dprintf(2, "FORKS:\n");
	for (size_t i = 0; i < p->n_philos; i++)
	{
		dprintf(2, "FORK ID %d\n", f[i].id);
	}
	return 0;
}

int			main(int ac, char **av)
{
	t_philo		*philos;
	t_fork		*forks;
	t_params	*params;
	t_state		*state;

	m_errno(ENOERROR);
	params = init_params(ac, av);
	if (m_is_error())
		return (m_put_error());
	philos = init_philos(params->n_philos);
	if (m_is_error())
		return (m_put_error());
	forks = init_forks(params->n_philos);
	if (m_is_error())
		return (m_put_error());
	state = init_state(params, philos, forks);
	if (m_is_error())
		return (m_put_error());
	start_philo_machine(state);
	if (m_is_error())
		return (m_put_error());
	return (0);
}
