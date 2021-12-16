/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subroutines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 22:37:32 by ehakam            #+#    #+#             */
/*   Updated: 2021/12/16 22:38:01 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_philo.h"

void		take_forks(t_state *state)
{
	const int left = state->id;
	const int right = (state->id + 1) % state->params->n_philos;

	if (state->id % 2 == 0)
	{
		pthread_mutex_lock(&state->forks[left].mtx);
		log_state(STATE_TAKE_FORK, state);
		pthread_mutex_lock(&state->forks[right].mtx);
		log_state(STATE_TAKE_FORK, state);
	}
	else
	{
		pthread_mutex_lock(&state->forks[right].mtx);
		log_state(STATE_TAKE_FORK, state);
		pthread_mutex_lock(&state->forks[left].mtx);
		log_state(STATE_TAKE_FORK, state);
	}
}

void		release_forks(t_state *state)
{
	const int left = state->id;
	const int right = (state->id + 1) % state->params->n_philos;

	if (state->id % 2 == 0)
	{
		pthread_mutex_unlock(&state->forks[left].mtx);
		pthread_mutex_unlock(&state->forks[right].mtx);
	}
	else
	{
		pthread_mutex_unlock(&state->forks[right].mtx);
		pthread_mutex_unlock(&state->forks[left].mtx);
	}
}

void		ro_eat(t_state *state)
{
	const size_t count = state->params->n_philos;

	take_forks(state);
	state->last_meal_time = get_current_time();
	log_state(STATE_EATING, state);
	m_sleep(state->params->t_eat);
	release_forks(state);
}

void		ro_sleep(t_state *state)
{
	const size_t count = state->params->n_philos;

	log_state(STATE_SLEEPING, state);
	m_sleep(state->params->t_sleep);
}

void		ro_think(t_state *state)
{
	log_state(STATE_THINKING, state);
}
