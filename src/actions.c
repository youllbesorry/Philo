/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:14:59 by bfaure            #+#    #+#             */
/*   Updated: 2023/12/05 18:53:27 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	eat(t_philo *philo)
{
	take_his_fork(philo);
	take_right_fork(philo);
	pthread_mutex_lock(&philo->data->mutex->mutex_eat);
	if (philo->data->is_alive && philo->nb_eat != 0 && philo->nb_fork == 2)
	{
		philo->last_eat = ft_get_time() - philo->data->start_time;
		philo->lifespan += philo->last_eat;
		if (ft_message(philo, "is eating"))
			return ;
		ft_usleep(philo->data->time_to_eat);
		if (philo->nb_eat != -1)
		{
			philo->nb_eat--;
			if (philo->nb_eat == 0)
				philo->data->finish++;
		}
		drop_fork(philo);
	}
	pthread_mutex_unlock(&philo->data->mutex->mutex_eat);
}

void	sleeping(t_philo *philo)
{
	if (ft_message(philo, "is sleeping"))
		return ;
	ft_usleep(philo->data->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	if (ft_message(philo, "is thinking"))
		return ;
}
