/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:03:56 by bfaure            #+#    #+#             */
/*   Updated: 2023/11/29 16:03:56 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	*routine(void *data_arg)
{
	static t_uint	i = 0;
	t_data			*data;

	data = (t_data *)data_arg;
	if (data)
	{
		pthread_mutex_lock(data->mutex);
		data->philo->id_philo = i++;
		printf("Hello from thread %u\n", data->philo->id_philo);
		printf("Goodbye from thread %u\n", data->philo->id_philo);
		pthread_detach(data->threads[data->philo->id_philo]);
		pthread_mutex_unlock(data->mutex);
	}
	return (NULL);
}
