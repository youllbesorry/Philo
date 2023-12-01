/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:43:25 by bfaure            #+#    #+#             */
/*   Updated: 2023/12/01 17:18:44 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <pthread.h>
# include <stdbool.h>

typedef unsigned int	t_uint;
typedef struct timeval	t_tv;

typedef struct s_philo
{
	struct s_data	*data;
	t_uint			id_philo;
	t_uint			last_eat;
	pthread_t		death_thread;
	pthread_mutex_t	fork;
	pthread_mutex_t	mutex_sync;
}	t_philo;

typedef struct s_data
{
	bool			is_alive;
	pthread_t		*threads;
	pthread_mutex_t	*mutex;
	t_uint			nb_philo;
	t_uint			time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_eat;
	int				nb_fork;
	bool			simulation;
	t_philo			*philo;
}	t_data;

#endif