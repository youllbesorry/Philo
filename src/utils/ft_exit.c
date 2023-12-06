/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:47:27 by bfaure            #+#    #+#             */
/*   Updated: 2023/12/06 17:09:58 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/philo.h"

void	ft_exit(t_data *data)
{
	t_uint	i;

	i = 0;
	// pthread_mutex_lock(&data->mutex->mutex_message);
	// pthread_mutex_lock(&data->mutex->mutex_eat);
	// pthread_mutex_lock(&data->mutex->mutex_sync);
	// pthread_mutex_unlock(&data->mutex->mutex_message);
	// pthread_mutex_unlock(&data->mutex->mutex_eat);
	// pthread_mutex_unlock(&data->mutex->mutex_sync);
	while (i < data->nb_philo)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->mutex->mutex_eat);
	pthread_mutex_destroy(&data->mutex->mutex_sync);
	pthread_mutex_destroy(&data->mutex->mutex_message);
	if (data->philo)
		free(data->philo);
	if (data->forks)
		free(data->forks);
	if (data->philo_thread)
		free(data->philo_thread);
	if (data->mutex)
		free(data->mutex);
}
