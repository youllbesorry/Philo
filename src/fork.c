/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:48:37 by bfaure            #+#    #+#             */
/*   Updated: 2023/12/12 13:28:49 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	take_fork(t_philo *philo)
{
	if (philo->philo_id % 2 == 0)
	{
		pthread_mutex_lock(philo->his_fork);
		philo->nb_fork++;
		ft_message(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		philo->nb_fork++;
		ft_message(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		philo->nb_fork++;
		ft_message(philo, "has taken a fork");
		pthread_mutex_lock(philo->his_fork);
		philo->nb_fork++;
		ft_message(philo, "has taken a fork");
	}
}

void	drop_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->his_fork);
	pthread_mutex_unlock(philo->right_fork);
	philo->nb_fork = 0;
}
