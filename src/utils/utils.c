/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:47:40 by bfaure            #+#    #+#             */
/*   Updated: 2023/12/06 19:20:02 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/philo.h"

t_uint	ft_get_time(void)
{
	t_tv	timeval;

	if (gettimeofday(&timeval, NULL))
		return (1);
	return (timeval.tv_sec * 1000 + timeval.tv_usec / 1000);
}

t_uint	ft_usleep(t_uint time)
{
	t_uint	time_start;

	time_start = ft_get_time();
	while (ft_get_time() - time_start < time)
		usleep(time / 10);
	return (0);
}

t_uint	ft_message(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->data->mutex->mutex_message);
	if (philo->data->is_alive)
		printf("%u %u %s\n",
			ft_get_time() - philo->data->start_time, philo->philo_id, str);
	else
	{
		pthread_mutex_unlock(&philo->data->mutex->mutex_message);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->mutex->mutex_message);
	return (0);
}

t_uint	multi_monitor_init(t_data *data)
{
	t_uint	i;

	i = 0;
	data->monitor = malloc(sizeof(t_monitor) * 4);
	if (!data->monitor)
		return (1);
	while (i < 4)
	{
		if (i == 0)
			data->monitor[i].start = 0;
		else
			data->monitor[i].start = data->monitor[i - 1].end;
		if (i == 3)
			data->monitor[i].end = data->nb_philo;
		else
			data->monitor[i].end = data->nb_philo / 4 * (i + 1);
		data->monitor[i].data = data;
		i++;
	}
	return (0);
}

t_uint	mono_monitor_init(t_data *data)
{
	data->monitor = malloc(sizeof(t_monitor) * 1);
	if (!data->monitor)
		return (1);
	data->monitor[0].start = 0;
	data->monitor[0].end = data->nb_philo;
	data->monitor[0].data = data;
	return (0);
}
