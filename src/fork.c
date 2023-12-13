/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:48:37 by bfaure            #+#    #+#             */
/*   Updated: 2023/12/13 18:45:40 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

static t_uint	even_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->his_fork);
	philo->nb_fork++;
	ft_message(philo, "has taken a fork");
	pthread_mutex_lock(&philo->mutex->mutex_all);
	if (philo->data->nb_philo == 1)
	{
		philo->nb_fork--;
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(&philo->mutex->mutex_all);
		return (1);
	}
	pthread_mutex_unlock(&philo->mutex->mutex_all);
	pthread_mutex_lock(philo->right_fork);
	philo->nb_fork++;
	ft_message(philo, "has taken a fork");
	return (0);
}

static t_uint	uneven_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	philo->nb_fork++;
	ft_message(philo, "has taken a fork");
	pthread_mutex_lock(&philo->mutex->mutex_all);
	if (philo->data->nb_philo == 1)
	{
		philo->nb_fork--;
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(&philo->mutex->mutex_all);
		return (1);
	}
	pthread_mutex_unlock(&philo->mutex->mutex_all);
	pthread_mutex_lock(philo->his_fork);
	philo->nb_fork++;
	ft_message(philo, "has taken a fork");
	return (0);
}

t_uint	take_fork(t_philo *philo)
{
	if (philo->philo_id % 2 == 0)
		return (even_fork(philo));
	else
		return (uneven_fork(philo));
	return (0);
}

void	drop_fork(t_philo *philo)
{
	philo->nb_fork = 0;
	pthread_mutex_unlock(philo->his_fork);
	pthread_mutex_unlock(philo->right_fork);
}
