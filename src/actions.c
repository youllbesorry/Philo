/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:14:59 by bfaure            #+#    #+#             */
/*   Updated: 2023/12/13 18:38:37 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

static void	update_last_eat_and_lifespan(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mutex->mutex_all);
	philo->last_eat = ft_get_time() - philo->data->start_time;
	philo->lifespan += philo->last_eat;
	pthread_mutex_unlock(&philo->data->mutex->mutex_all);
}

static void	update_eat_count(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mutex->mutex_all);
	if (philo->nb_eat != -1)
	{
		philo->nb_eat--;
		if (philo->nb_eat == 0)
			philo->data->finish++;
	}
	pthread_mutex_unlock(&philo->data->mutex->mutex_all);
}

t_uint	eat(t_philo *philo)
{
	if (take_fork(philo))
		return (1);
	if (philo->nb_eat != 0 && philo->nb_fork == 2)
	{
		update_last_eat_and_lifespan(philo);
		if (ft_message(philo, "is eating"))
		{
			drop_fork(philo);
			return (1);
		}
		update_eat_count(philo);
		if (ft_usleep(philo->time_to_eat))
			return (1);
		drop_fork(philo);
	}
	return (0);
}

t_uint	sleeping(t_philo *philo)
{
	t_uint	time;

	pthread_mutex_lock(&philo->data->mutex->mutex_all);
	time = philo->data->time_to_sleep;
	pthread_mutex_unlock(&philo->data->mutex->mutex_all);
	if (is_dead(philo->data) != 0)
	{
		if (ft_message(philo, "is sleeping"))
			return (1);
		if (ft_usleep(time))
			return (1);
	}
	return (0);
}

void	thinking(t_philo *philo)
{
	if (ft_message(philo, "is thinking"))
		return ;
}
