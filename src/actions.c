/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:14:59 by bfaure            #+#    #+#             */
/*   Updated: 2023/12/11 15:51:41 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	eat(t_philo *philo)
{
	take_fork(philo);
	if (philo->nb_eat != 0 && philo->nb_fork == 2)
	{
		pthread_mutex_lock(&philo->data->mutex->mutex_all);
		philo->last_eat = ft_get_time() - philo->data->start_time;
		philo->lifespan += philo->last_eat;
		pthread_mutex_unlock(&philo->data->mutex->mutex_all);
		if (ft_message(philo, "is eating"))
		{
			drop_fork(philo);
			return ;
		}
		ft_usleep(philo->time_to_eat);
		drop_fork(philo);
		pthread_mutex_lock(&philo->data->mutex->mutex_all);
		if (philo->nb_eat != -1)
		{
			philo->nb_eat--;
			if (philo->nb_eat == 0)
				philo->data->finish++;
		}
		pthread_mutex_unlock(&philo->data->mutex->mutex_all);
	}
	else
		drop_fork(philo);
}

void	sleeping(t_philo *philo)
{
	if (philo->data->is_alive && philo->nb_eat != 0)
	{
		if (ft_message(philo, "is sleeping"))
		{
			// pthread_mutex_unlock(&phlo->data->mutex->mutex_all);
			return ;
		}
		ft_usleep(philo->data->time_to_sleep);
	}
	// pthread_mutex_unlock(&philo->data->mutex->mutex_all);
}

void	thinking(t_philo *philo)
{
	// pthread_mutex_lock(&philo->data->mutex->mutex_all);
	if (philo->data->is_alive && philo->nb_eat != 0)
	{
		if (ft_message(philo, "is thinking"))
		{
			// pthread_mutex_unlock(&philo->data->mutex->mutex_all);
			return ;
		}
	}
	// pthread_mutex_unlock(&philo->data->mutex->mutex_all);
}
