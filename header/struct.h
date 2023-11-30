/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:43:25 by bfaure            #+#    #+#             */
/*   Updated: 2023/11/30 11:20:03 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <pthread.h>
# include <stdbool.h>

typedef unsigned int	t_uint;

typedef struct s_philo
{
	t_uint			id_philo;
	int				fork;
	bool			is_alive;
}	t_philo;

typedef struct s_data
{
	pthread_t		*threads;
	pthread_mutex_t	*mutex;
	t_uint			nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_eat;
	int				nb_fork;
	bool			simulation;
	struct s_philo	*philo;
}	t_data;


#endif