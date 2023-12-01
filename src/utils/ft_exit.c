/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:47:27 by bfaure            #+#    #+#             */
/*   Updated: 2023/12/01 17:05:23 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/philo.h"

t_uint	ft_exit(t_data *data)
{
	t_uint	i;

	i = 0;
	if (data)
	{
		// while (i < data->nb_philo)
		// {
		// 	pthread_mutex_destroy(&data->mutex[i]);
		// 	i++;
		// }
		// i = 0;
		while (i < data->nb_philo)
		{
			if (pthread_join(data->threads[i], NULL))
				printf("Error, thread join failed\n");
			i++;
		}
		if (data->threads)
			free(data->threads);
		if (data->philo)
			free(data->philo);
		return (0);
	}
	return (1);
}
