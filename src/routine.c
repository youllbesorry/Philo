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

	philo = (t_philo *)data_arg;
	pthread_mutex_lock(&philo->mutex.mutex_sync);
	while (philo->data->is_alive || philo->nb_eat != 0)
	{
		thinking(philo);
		eat(philo);
		sleeping(philo);
	}
	pthread_mutex_unlock(&philo->mutex.mutex_sync);
	return (NULL);
}
