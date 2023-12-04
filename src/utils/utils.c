/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:47:40 by bfaure            #+#    #+#             */
/*   Updated: 2023/12/04 15:17:10 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/philo.h"

t_uint	ft_get_time(void)
{
	t_tv	timeval;

	if (gettimeofday(&timeval, NULL))
		return (0);
	return (timeval.tv_sec * 1000 + timeval.tv_usec / 1000);
}

t_uint	ft_usleep(t_uint time)
{
	t_uint	time_start;

	time_start = ft_get_time();
	while (ft_get_time() - time_start < time)
		usleep(time / 10);
	return (0);
}

t_uint	ft_message(t_philo *philo, char *str)
{
	if (philo->data->is_alive)
		printf("%u %u %s\n",
			ft_get_time() - philo->data->start_time, philo->id_philo, str);
	return (0);
}

