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
	t_uint	i;

	i = 0;
	philo = (t_philo *)data_arg;
	pthread_create(&philo->death_thread, NULL, death, philo);
	pthread_detach(philo->death_thread);
	pthread_mutex_lock(&philo->mutex_sync);
	while (philo->data->is_alive && philo->is_finish == false)
	{
		think(philo);
		eat(philo, i);
		ft_sleep(philo);
		i++;
	}
	pthread_mutex_unlock(&philo->mutex_sync);
	return (NULL);
}
