/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:34:24 by bfaure            #+#    #+#             */
/*   Updated: 2023/12/05 18:21:19 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	*monitoring(void *data_arg)
{
	t_data	*data;
	t_uint	i;

	data = (t_data *)data_arg;
	pthread_mutex_lock(&data->monitor_mutex);
	while (data->is_alive && !data->is_finish)
	{
		i = 0;
		while (i < data->nb_philo)
		{
			if (data->philo[i].lifespan
				< (ft_get_time() - data->start_time) - data->philo[i].last_eat)
			{
				ft_message(&data->philo[i], "died");
				data->is_alive = false;
				ft_exit(data);
				return (pthread_mutex_unlock(&data->monitor_mutex), NULL);
			}
			i++;
		}
		if (data->finish == data->nb_philo)
		{
			data->is_finish = true;
			ft_exit(data);
			return (pthread_mutex_unlock(&data->monitor_mutex), NULL);
		}
	}
	pthread_mutex_unlock(&data->monitor_mutex);
	return (NULL);
}
