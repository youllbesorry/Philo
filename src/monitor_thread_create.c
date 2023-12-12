/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_thread_create.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:42:03 by bfaure            #+#    #+#             */
/*   Updated: 2023/12/12 16:44:31 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

static t_uint	create_single_monitor_thread(t_data *data)
{
	data->monitor_thread = malloc(sizeof(pthread_t) * 1);
	if (!data->monitor_thread)
		return (1);
	mono_monitor_init(data);
	pthread_create(data->monitor_thread, NULL, monitoring, &data->monitor[0]);
	pthread_detach(*data->monitor_thread);
	return (0);
}

static t_uint	create_multiple_monitor_thread(t_data *data)
{
	t_uint	i;

	i = 0;
	data->monitor_thread = malloc(sizeof(pthread_t) * 4);
	if (!data->monitor_thread)
		return (1);
	multi_monitor_init(data);
	while (i < 4)
	{
		if (pthread_create(&data->monitor_thread[i], NULL, monitoring,
				&data->monitor[i]))
			return (1);
		pthread_detach(data->monitor_thread[i]);
		i++;
	}
	return (0);
}

t_uint	monitor_thread_create(t_data *data)
{
	t_uint	i;

	i = 0;
	if (data->nb_philo < 4)
		return (create_single_monitor_thread(data));
	else
		return (create_multiple_monitor_thread(data));
	return (0);
}
