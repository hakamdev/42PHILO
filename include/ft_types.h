/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:37:17 by ehakam            #+#    #+#             */
/*   Updated: 2021/12/16 19:37:34 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPES_H
# define FT_TYPES_H

# include <stdlib.h>
# include <stdbool.h>
# include <pthread.h>

typedef struct	s_params
{
	size_t	n_philos;
	useconds_t	t_die;
	useconds_t	t_eat;
	useconds_t	t_sleep;
	bool	must_eat;
	size_t	n_eat;
	pthread_mutex_t	pmtx;
}				t_params;

// typedef struct	s_philo
// {
// 	int			id;
// 	pthread_t	*thread;
// }				t_philo;

typedef struct	s_fork
{
	int				id;
	pthread_mutex_t	mtx;
}				t_fork;

typedef struct	s_state
{
	int			id;
	int			current_state;
	bool		*is_dead;
	t_params	*params;
	t_fork		*forks;
	useconds_t	last_meal_time;
	useconds_t	*start_time;
	pthread_t	philo_thread;
}				t_state;

#endif
