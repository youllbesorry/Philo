/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:34:24 by bfaure            #+#    #+#             */
/*   Updated: 2023/12/12 16:43:03 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

static t_uint	check_philo_lifespan(t_monitor *monitor, t_uint i)
{
	pthread_mutex_lock(&monitor->data->mutex->mutex_all);
	if (monitor->data->philo[i].lifespan
		< (ft_get_time() - monitor->data->start_time)
		- monitor->data->philo[i].last_eat)
	{
		if (monitor->data->is_alive)
			printf("%u %u %s\n",
				ft_get_time() - monitor->data->start_time,
				monitor->data->philo[i].philo_id, "died");
		monitor->data->is_alive = false;
		return (pthread_mutex_unlock(&monitor->data->mutex->mutex_all), 1);
	}
	pthread_mutex_unlock(&monitor->data->mutex->mutex_all);
	return (0);
}

static t_uint	check_finish_status(t_monitor *monitor)
{
	pthread_mutex_lock(&monitor->data->mutex->mutex_all);
	if (monitor->data->finish == monitor->data->nb_philo)
	{
		monitor->data->is_finish = true;
		return (pthread_mutex_unlock(&monitor->data->mutex->mutex_all), 1);
	}
	pthread_mutex_unlock(&monitor->data->mutex->mutex_all);
	return (0);
}

void	*monitoring(void *data_arg)
{
	t_monitor	*monitor;
	t_uint		i;

	monitor = (t_monitor *)data_arg;
	while (running(monitor->data))
	{
		i = monitor->start;
		while (i < monitor->end)
		{
			if (check_philo_lifespan(monitor, i))
				return (NULL);
			i++;
		}
		if (check_finish_status(monitor))
			return (NULL);
	}
	return (NULL);
}
