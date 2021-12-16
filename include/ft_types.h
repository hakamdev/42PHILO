/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:37:17 by ehakam            #+#    #+#             */
/*   Updated: 2021/12/16 22:42:45 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPES_H
# define FT_TYPES_H

# include <stdlib.h>
# include <stdbool.h>
# include <pthread.h>

# define STATE_NONE -1
# define STATE_DEAD 0
# define STATE_EATING 1
# define STATE_SLEEPING 2
# define STATE_THINKING 3
# define STATE_TAKE_FORK 4

typedef struct	s_params
{
	size_t			n_philos;
	useconds_t		t_die;
	useconds_t		t_eat;
	useconds_t		t_sleep;
	bool			must_eat;
	int				n_eat;
	pthread_mutex_t	pmtx;
}				t_params;

typedef struct	s_fork
{
	int				id;
	pthread_mutex_t	mtx;
}				t_fork;

typedef struct	s_state
{
	int			id;
	pthread_t	philo_thread;
	useconds_t	last_meal_time;
	useconds_t	init_time;
	int			*total_finished_meals;
	t_params	*params;
	t_fork		*forks;
}				t_state;

#endif
