/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 23:55:48 by ehakam            #+#    #+#             */
/*   Updated: 2021/12/15 02:14:00 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_philo.h"

void		take_forks(t_fork *forks, int left, int right)
{
	pthread_mutex_lock(&forks[left].mtx);
	pthread_mutex_lock(&forks[right].mtx);
}

void		release_forks(t_fork *forks, int left, int right)
{
	pthread_mutex_unlock(&forks[left].mtx);
	pthread_mutex_unlock(&forks[right].mtx);
}

void		ro_eat(t_state *state)
{
	const size_t	count = state->params->n_philos;

	if (state->id % 2 == 0)
		m_sleep(state->params->t_eat);
	log_state(STATE_EATING, state);
	m_sleep(state->params->t_eat);
	take_forks(state->forks, state->id, (state->id + 1) % count);
	m_sleep(state->params->t_eat);
	release_forks(state->forks, state->id, (state->id + 1) % count);
}

void		ro_eat(t_state *state)
{
	const size_t	count = state->params->n_philos;

	if (state->id % 2 == 0)
		m_sleep(state->params->t_eat);
	log_state(STATE_SLEEPING, state);
	m_sleep(state->params->t_eat);
	take_forks(state->forks, state->id, (state->id + 1) % count);
	m_sleep(state->params->t_eat);
	release_forks(state->forks, state->id, (state->id + 1) % count);
}

/*
** Routine...
** prototype: void *(*start_routine)(void *)
*/
void		*routine(void *params)
{
	t_state *state = (t_state *)params;
	pthread_mutex_lock(&state->params->pmtx);
	log_state(STATE_DEAD, state);
	log_state(STATE_EATING, state);
	log_state(STATE_SLEEPING, state);
	log_state(STATE_THINKING, state);
	pthread_mutex_unlock(&state->params->pmtx);
	return state;
}

void		*super_routine(void *params)
{
	t_state *state = (t_state *)params;
	pthread_mutex_lock(&state->params->pmtx);
	dprintf(2, "THREAD %d STARTED\n", state->id);
	pthread_mutex_unlock(&state->params->pmtx);
	return state;
}
