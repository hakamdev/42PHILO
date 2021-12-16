/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 23:55:48 by ehakam            #+#    #+#             */
/*   Updated: 2021/12/16 22:37:44 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_philo.h"

void		*routine(void *args)
{
	t_state *state = (t_state *)args;
	size_t	n_eat;

	n_eat = 0;
	if (state->params->must_eat)
	{
		while (n_eat < state->params->n_eat)
		{
			ro_eat(state);
			n_eat++;
			ro_sleep(state);
			ro_think(state);
		}
		*state->total_finished_meals = (*state->total_finished_meals) + n_eat;
	}
	else
	{
		while (true)
		{
			ro_eat(state);
			ro_sleep(state);
			ro_think(state);
		}
	}
	return (state);
}

void		*super_routine(void *args)
{
	size_t		i;
	t_state		*state = (t_state *)args;
	const int	totoal_expected_meals =
			state->params->n_philos * state->params->n_eat;
	i = 0;
	while (i < state->params->n_philos)
	{
		if (state->params->must_eat &&
			*state->total_finished_meals == totoal_expected_meals)
			break ;
		if (get_elapsed_since(state[i].last_meal_time) >= state->params->t_die)
			{
				log_state(STATE_DEAD, &state[i]);
				break;
			}
		++i;
		i %= state->params->n_philos;
	}
	return (state);
}
