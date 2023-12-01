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
	t_philo	*philo;
	t_tv	timeval;
	t_uint	i;

	i = 0;
	philo = (t_philo *)data_arg;
	pthread_create(&philo->death_thread, NULL, death, philo);
	pthread_detach(philo->death_thread);
	pthread_mutex_lock(&philo->mutex_sync);
	while (philo->data->is_alive)
	{
		if (philo->data->nb_eat != 0)
		{
			take_fork(philo, i);
			eat(philo);
			gettimeofday(&timeval, NULL);
			philo->last_eat = timeval.tv_sec * 1000 + timeval.tv_usec / 1000;
			if(pthread_mutex_unlock(&philo[i].fork))
				philo->data->nb_fork++;
			if(pthread_mutex_unlock(&philo[i + 1].fork))
				philo->data->nb_fork++;
			ft_sleep(philo);
			think(philo);
		}
		i++;
	}
	pthread_mutex_unlock(&philo->mutex_sync);
	return (NULL);
}
