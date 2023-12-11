/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:34:24 by bfaure            #+#    #+#             */
/*   Updated: 2023/12/11 14:33:54 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	monitor_thread_create(t_data *data)
{
	t_uint	i;

	i = 0;
	if (data->nb_philo < 4)
	{
		data->monitor_thread = malloc(sizeof(pthread_t) * 1);
		if (!data->monitor_thread)
			return ;
		mono_monitor_init(data);
		pthread_create(data->monitor_thread, NULL, monitoring, &data->monitor[0]);
		pthread_detach(*data->monitor_thread);
	}
	else
	{
		data->monitor_thread = malloc(sizeof(pthread_t) * 4);
		if (!data->monitor_thread)
			return ;
		multi_monitor_init(data);
		while (i < 4)
		{
			pthread_create(&data->monitor_thread[i], NULL, monitoring,
				&data->monitor[i]);
			pthread_detach(data->monitor_thread[i]);
			i++;
		}
	}
}

void	*monitoring(void *data_arg)
{
	t_monitor	*monitor;
	t_uint		i;

	monitor = (t_monitor *)data_arg;
	while (monitor->data->is_alive && !monitor->data->is_finish)
	{
		i = monitor->start;
		while (i < monitor->end)
		{
			pthread_mutex_lock(&monitor->data->mutex->mutex_all);
			if (monitor->data->philo[i].lifespan
				< (ft_get_time() - monitor->data->start_time) - monitor->data->philo[i].last_eat)
			{
				ft_message(&monitor->data->philo[i], "died");
				monitor->data->is_alive = false;
				return (pthread_mutex_unlock(&monitor->data->mutex->mutex_all), NULL);
			}
			pthread_mutex_unlock(&monitor->data->mutex->mutex_all);
			i++;
		}
		pthread_mutex_lock(&monitor->data->mutex->mutex_all);
		if (monitor->data->finish == monitor->data->nb_philo)
		{
			monitor->data->is_finish = true;
			return (pthread_mutex_unlock(&monitor->data->mutex->mutex_all), NULL);
		}
		pthread_mutex_unlock(&monitor->data->mutex->mutex_all);
	}
	return (NULL);
}
