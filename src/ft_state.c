/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_state.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 01:23:23 by ehakam            #+#    #+#             */
/*   Updated: 2021/12/15 01:54:54 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_philo.h"

static char	*state_msg(int state_type)
{
	if (state_type == STATE_DEAD)
		return ("is dead");
	if (state_type == STATE_EATING)
		return ("is eating");
	if (state_type == STATE_SLEEPING)
		return ("is sleeping");
	if (state_type == STATE_THINKING)
		return ("is thinking");
	return ("");
}

void		log_state(int state_type, t_state *state)
{
	const size_t now = get_current_time() / 1000;
	
	printf("[%zu] ID %d : %s\n", now, state->id, state_msg(state_type));
	
}