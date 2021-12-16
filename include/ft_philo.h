/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:01:12 by ehakam            #+#    #+#             */
/*   Updated: 2021/12/16 22:42:38 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PHILO_H
# define FT_PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>

# include "ft_types.h"
# include "ft_errors.h"

/*
** Helper Functions
*/
size_t		m_aton(const char *str);
bool		m_is_number(char *arg);
void		log_state(int state_type, t_state *state);

/*
** Init Functions
*/
t_params	*init_params(int count, char **params);
t_state		*init_state(t_params *params, t_fork *forks);
t_fork		*init_forks(size_t count);

/*
** Staring Functions
*/
int			start_threads(t_state *state);
int			start_supervisor_thread(t_state *state);
int			start_philo_machine(t_state *state);

/*
** Destructor Functions
*/
int			destroy_all(t_params *params, t_fork *forks);
void		destroy_forks(t_fork *forks, int last_index);

/*
** Routine Functions
*/
void		take_forks(t_state *state);
void		release_forks(t_state *state);
void		ro_eat(t_state *state);
void		ro_sleep(t_state *state);
void		ro_think(t_state *state);
void		*routine(void *args);
void		*super_routine(void *args);

/*
** Time Functions
*/
useconds_t	get_current_time();
useconds_t	get_elapsed_since(useconds_t usec);
useconds_t	get_time_diff(useconds_t new_usec, useconds_t old_usec);
void		m_sleep(useconds_t usec);

#endif