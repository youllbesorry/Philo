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
		if (pthread_mutex_init(&philo[i].mutex_eat, NULL))
			return (1);
		i++;
	}
	return (0);
}

t_uint	init_mutex(t_data *data)
{
	t_uint	i;

	i = 0;
	data->mutex = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (!data->mutex)
		return (1);
	while (i < data->nb_philo)
	{
		if (pthread_mutex_init(&data->mutex[i], NULL))
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
		data->philo[i].last_eat = ft_get_time() - data->start_time;
		data->philo[i].nb_fork_philo = 0;
		data->philo[i].life_time = data->time_to_die + data->time_to_eat;
		data->philo[i].is_finish = false;
		if (data->nb_eat == -1)
			data->philo[i].nb_eat = -1;
		else
			data->philo[i].nb_eat = data->nb_eat;
		i++;
	}
	if (init_philo_mutex(data->philo, data))
		return (1);
	if (init_mutex(data))
		return (1);
	return (0);
}
