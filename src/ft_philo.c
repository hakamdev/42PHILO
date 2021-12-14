/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:35:16 by ehakam            #+#    #+#             */
/*   Updated: 2021/12/14 18:45:30 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_philo.h"

/*
** Initialize all Arguments and check for agrs errors
*/
t_params	*init_params(int count, char **args)
{
	
}

/*
** Initialize a list philo objects
*/
t_philo		*init_philos(size_t count)
{
	
}

/*
** Initialize a list fork objects
*/
t_fork		*init_forks(size_t count)
{
	
}

/*
** Initialize a list state object for each philo
*/
t_state		*init_state(t_params *params, t_philo *philos, t_fork *forks)
{
	
}

/*
** Start threading...
*/
int			start_threads(t_philo *philos)
{
	
}

/*
** Start listening on the threads using a supervisor thread...
*/
int			start_supervisor(t_state *state) {
	
}

int			start_state_machine(t_state *state) {
	
}

int	main(int ac, char **av)
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
	start_state_machine(state);
	if (m_is_error())
		return (m_put_error());
	return (0);
}
