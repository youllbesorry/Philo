/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:18:37 by bfaure            #+#    #+#             */
/*   Updated: 2023/11/30 11:18:37 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/philo.h"

t_uint	init_data(t_data *data)
{
	t_uint	i;

	i = 0;
	data->is_alive = true;
	data->start_time = ft_get_time();
	data->finish = 0;
	data->is_finish = false;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (!data->forks)
		return (1);
	data->philo_thread = malloc(sizeof(pthread_t) * data->nb_philo);
	if (!data->philo_thread)
		return (1);
	while (i < data->nb_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (0);
		i++;
	}
	data->mutex = malloc(sizeof(t_mutex));
	if (init_mutex(data) == 1)
		return (1);
	if (init_philo(data) == 1)
		return (1);
	return (0);
}

t_uint	init_mutex(t_data *data)
{
	if (pthread_mutex_init(&data->mutex->mutex_message, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&data->mutex->mutex_all, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&data->mutex->mutex_sync, NULL) != 0)
		return (1);
	return (0);
}

t_uint	init_philo(t_data *data)
{
	t_uint	i;

	i = 0;
	data->philo = malloc(sizeof(t_philo) * data->nb_philo);
	if (!data->philo)
		return (1);
	while (i < data->nb_philo)
	{
		data->philo[i].data = data;
		data->philo[i].philo_id = i + 1;
		data->philo[i].last_eat = ft_get_time() - data->start_time;
		data->philo[i].his_fork = &data->forks[i];
		data->philo[i].right_fork = &data->forks[(i + 1) % data->nb_philo];
		data->philo[i].lifespan = data->time_to_die;
		data->philo[i].nb_eat = data->nb_eat;
		data->philo[i].nb_fork = 0;
		data->philo[i].mutex = *data->mutex;
		data->philo[i].time_to_eat = data->time_to_eat;
		i++;
	}
	return (0);
}
