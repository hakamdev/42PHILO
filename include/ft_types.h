/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:37:17 by ehakam            #+#    #+#             */
/*   Updated: 2021/12/14 18:04:24 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPES_H
# define FT_TYPES_H

#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

typedef struct	s_params
{
	size_t	num_philos;
	size_t	t_die;
	size_t	t_eat;
	size_t	t_sleep;
	bool	must_eat;
	size_t	n_eat;
	pthread_mutex_t	*pmtx;
}				t_params;

typedef struct	s_philo
{
	int			id;
	pthread_t	*thread;
}				t_philo;

typedef struct	s_fork
{
	int				id;
	pthread_mutex_t	*mtx;
}				t_fork;

typedef struct	s_state
{
	int			id;
	t_params	*args;
	t_philo		*philos;
	t_fork		*forks;
}				t_state;


#endif