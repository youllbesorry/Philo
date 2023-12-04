/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:14:59 by bfaure            #+#    #+#             */
/*   Updated: 2023/12/04 16:39:23 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	eat(t_philo *philo, t_uint i)
{
	take_fork(philo, i);
	take_fork(philo, i + 1);
	pthread_mutex_lock(&philo->mutex_eat);
	if (philo->data->is_alive && philo->nb_fork_philo == 2)
	{
		philo->last_eat = (ft_get_time() - philo->data->start_time);
		ft_message(philo, "is eating");
		philo->life_time += philo->data->time_to_eat;
		ft_usleep(philo->data->time_to_eat);
		if (philo->nb_eat != -1)
			philo->nb_eat--;
		drop_fork(philo, i);
		drop_fork(philo, i + 1);
	}
	pthread_mutex_unlock(&philo->mutex_eat);
}

void	ft_sleep(t_philo *philo)
{
	if (philo->data->is_alive)
	{
		ft_message(philo, "is sleeping");
		ft_usleep(philo->data->time_to_sleep);
	}
}

void	think(t_philo *philo)
{
	ft_message(philo, "is thinking");
}

void	*death(void *data_arg)
{
	t_philo	*philo;

	philo = (t_philo *)data_arg;
	pthread_mutex_lock(&philo->data->mutex[philo->id_philo]);
	while (philo->data->is_alive && philo->is_finish == false)
	{
		if (philo->life_time
			< (ft_get_time() - philo->data->start_time) - philo->last_eat)
		{
			ft_message(philo, "died");
			philo->data->is_alive = false;
			ft_exit(philo->data);
			// return (NULL);
			return (
				pthread_mutex_unlock(&philo->data->mutex[philo->id_philo]),
				NULL);
		}
		if (philo->nb_eat == 0)
		{
			philo->is_finish = true;
			ft_exit(philo->data);
			// return (NULL);
			return (
				pthread_mutex_unlock(&philo->data->mutex[philo->id_philo]),
				NULL);
		}
	}
	pthread_mutex_unlock(&philo->data->mutex[philo->id_philo]);
	return (NULL);
}

void	take_fork(t_philo *philo, t_uint i)
{
	if (philo->data->nb_fork)
	{
		pthread_mutex_lock(&philo[i].fork);
		philo->data->nb_fork--;
		philo->nb_fork_philo++;
		ft_message(philo, "has taken a fork");
	}
}

void	drop_fork(t_philo *philo, t_uint i)
{
	if (philo->nb_fork_philo)
	{
		pthread_mutex_unlock(&philo[i].fork);
		philo->nb_fork_philo--;
		philo->data->nb_fork++;
	}
}
