/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:14:59 by bfaure            #+#    #+#             */
/*   Updated: 2023/12/01 17:19:32 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	eat(t_philo *philo)
{
	t_tv	timeval;

	gettimeofday(&timeval, NULL);
	printf("%li Philo %u is eating\n",
		timeval.tv_sec * 1000 + timeval.tv_usec / 1000, philo->id_philo);
	usleep(1000 * philo->data->time_to_eat);
	if (philo->data->nb_eat != -1)
		philo->data->nb_eat--;
}

void	ft_sleep(t_philo *philo)
{
	t_tv	timeval;

	gettimeofday(&timeval, NULL);
	printf("%li Philo %u is sleeping\n",
		timeval.tv_sec * 1000 + timeval.tv_usec / 1000, philo->id_philo);
	usleep(1000 * philo->data->time_to_sleep);
}

void	think(t_philo *philo)
{
	t_tv	timeval;

	gettimeofday(&timeval, NULL);
	printf("%li Philo %u is thinking\n",
		timeval.tv_sec * 1000 + timeval.tv_usec / 1000, philo->id_philo);
}

void	*death(void *data_arg)
{
	t_philo	*philo;
	t_tv	timeval;

	philo = (t_philo *)data_arg;
	while (philo->data->is_alive)
	{
		gettimeofday(&timeval, NULL);
		if (philo->data->time_to_die
			< timeval.tv_sec * 1000 + timeval.tv_usec / 1000 - philo->last_eat)
		{
			printf("%li Philo %u died\n",
				timeval.tv_sec * 1000 + timeval.tv_usec / 1000,
				philo->id_philo);
			philo->data->is_alive = false;
			ft_exit(philo->data);
			return (NULL);
		}
	}
	return (NULL);
}

void	take_fork(t_philo *philo, t_uint i)
{
	t_tv	timeval;

	gettimeofday(&timeval, NULL);
	if(pthread_mutex_lock(&philo[i].fork))
		philo->data->nb_fork--;
	if(pthread_mutex_lock(&philo[i + 1].fork))
		philo->data->nb_fork--;
	printf("%li Philo %u has taken a fork\n",
		timeval.tv_sec * 1000 + timeval.tv_usec / 1000, philo->id_philo);
	printf("%li Philo %u has taken a fork\n",
		timeval.tv_sec * 1000 + timeval.tv_usec / 1000, philo->id_philo);
}
