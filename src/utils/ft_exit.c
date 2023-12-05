/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:47:27 by bfaure            #+#    #+#             */
/*   Updated: 2023/12/05 18:49:07 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/philo.h"

void	ft_exit(t_data *data)
{
	t_uint	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_destroy(data->philo[i].his_fork);
		pthread_mutex_destroy(data->philo[i].right_fork);
		i++;
	}
	pthread_mutex_destroy(&data->mutex->mutex_eat);
	pthread_mutex_destroy(&data->mutex->mutex_sync);
	pthread_mutex_destroy(&data->mutex->mutex_message);
	pthread_mutex_destroy(&data->monitor_mutex);
	if (data->philo)
		free(data->philo);
	if (data->forks)
		free(data->forks);
}
