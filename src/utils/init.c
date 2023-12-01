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

t_uint	init_philo_mutex(t_philo *philo, t_data *data)
{
	t_uint	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_mutex_init(&philo[i].fork, NULL))
			return (1);
		i++;
	}
	return (0);
}

t_uint	init_struct(t_data *data)
{
	t_uint	i;

	i = 0;
	data->philo = malloc(sizeof(t_philo) * data->nb_philo);
	if (!data->philo)
		return (1);
	pthread_mutex_init(&data->philo->mutex_sync, NULL);
	pthread_mutex_lock(&data->philo->mutex_sync);
	while (i < data->nb_philo)
	{
		data->philo[i].id_philo = i;
		data->philo[i].data = data;
		i++;
	}
	if (init_philo_mutex(data->philo, data))
		return (1);
	return (0);
}
