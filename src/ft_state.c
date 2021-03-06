/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_state.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 01:23:23 by ehakam            #+#    #+#             */
/*   Updated: 2021/12/16 21:23:02 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_philo.h"

static char	*state_msg(int state_type)
{
	if (state_type == STATE_DEAD)
		return ("died");
	if (state_type == STATE_EATING)
		return ("is eating");
	if (state_type == STATE_SLEEPING)
		return ("is sleeping");
	if (state_type == STATE_THINKING)
		return ("is thinking");
	if (state_type == STATE_TAKE_FORK)
		return ("has taken a fork");
	return ("");
}

void		log_state(int state_type, t_state *state)
{
	const useconds_t t_since_start = (get_current_time() - state->init_time) / 1000;

	pthread_mutex_lock(&state->params->pmtx);
	printf("[%07u] %d %s\n",
		t_since_start,
		state->id + 1,
		state_msg(state_type));
	if (state_type != STATE_DEAD)
		pthread_mutex_unlock(&state->params->pmtx);
}
