/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:47:27 by bfaure            #+#    #+#             */
/*   Updated: 2023/12/13 18:56:14 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/philo.h"

t_uint	ft_kill_philo_threads(t_data *data, t_uint j, t_uint status)
{
	t_uint	i;

	i = 0;
	pthread_mutex_lock(&data->mutex->mutex_all);
	data->is_alive = false;
	pthread_mutex_unlock(&data->mutex->mutex_all);
	pthread_mutex_unlock(&data->mutex->mutex_sync);
	ft_usleep(100);
	while (i < j)
	{
		if (pthread_detach(data->philo_thread[i]))
			return (1);
		i++;
	}
	pthread_mutex_lock(&data->mutex->mutex_all);
	if (data->monitor && status == 0)
		free(data->monitor);
	pthread_mutex_unlock(&data->mutex->mutex_all);
	return (0);
}

t_uint	ft_kill_monitor_threads(t_data *data, t_uint j)
{
	t_uint	i;

	i = 0;
	ft_kill_philo_threads(data, data->nb_philo, 0);
	ft_usleep(100);
	while (i < j)
	{
		if (pthread_detach(data->monitor_thread[i]))
			return (1);
		i++;
	}
	return (0);
}

void	ft_exit(t_data *data, t_uint status)
{
	t_uint	i;

	i = 0;
	pthread_mutex_lock(&data->mutex->mutex_all);
	pthread_mutex_unlock(&data->mutex->mutex_all);
	while (i < data->nb_philo)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->mutex->mutex_all);
	pthread_mutex_destroy(&data->mutex->mutex_sync);
	pthread_mutex_destroy(&data->mutex->mutex_message);
	if (data->forks)
		free(data->forks);
	if (data->philo_thread)
		free(data->philo_thread);
	if (data->mutex)
		free(data->mutex);
	if (data->monitor_thread)
		free(data->monitor_thread);
	if (data->monitor && status == 0)
		free(data->monitor);
	if (data->philo)
		free(data->philo);
}
