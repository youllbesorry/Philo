/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:43:25 by bfaure            #+#    #+#             */
/*   Updated: 2023/12/06 19:05:16 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <pthread.h>
# include <stdbool.h>

typedef unsigned int	t_uint;
typedef struct timeval	t_tv;

typedef struct s_mutex
{
	pthread_mutex_t	mutex_eat;
	pthread_mutex_t	mutex_sync;
	pthread_mutex_t	mutex_message;
}	t_mutex;

typedef struct s_philo
{
	struct s_data	*data;
	t_mutex			mutex;
	pthread_mutex_t	*his_fork;
	pthread_mutex_t	*right_fork;
	int				nb_eat;
	t_uint			nb_fork;
	t_uint			last_eat;
	t_uint			lifespan;
	t_uint			philo_id;
}	t_philo;

typedef struct s_data
{
	t_philo				*philo;
	t_mutex				*mutex;
	struct s_monitor	*monitor;
	pthread_mutex_t		*forks;
	pthread_t			*philo_thread;
	pthread_t			*monitor_thread;
	bool				is_alive;
	bool				is_finish;
	int					nb_eat;
	t_uint				finish;
	t_uint				nb_philo;
	t_uint				start_time;
	t_uint				time_to_die;
	t_uint				time_to_eat;
	t_uint				time_to_sleep;
}	t_data;

typedef struct s_monitor
{
	t_data			*data;
	t_uint			start;
	t_uint			end;
}	t_monitor;

#endif