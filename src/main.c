/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:28:04 by bfaure            #+#    #+#             */
/*   Updated: 2023/12/01 16:45:48 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	main(int argc, char **argv)
{
	t_data			data;
	t_uint			i;

	i = 0;
	if (argc == 5 || argc == 6)
	{
		data.nb_philo = ft_atoi(argv[1]);
		data.time_to_die = ft_atoi(argv[2]);
		data.time_to_eat = ft_atoi(argv[3]);
		data.time_to_sleep = ft_atoi(argv[4]);
		data.is_alive = true;
		if (argc == 6)
			data.nb_eat = ft_atoi(argv[5]);
		else
			data.nb_eat = -1;
		data.threads = malloc(sizeof(pthread_t) * data.nb_philo);
		if (!data.threads)
			printf("Error, malloc failed\n");
		if (init_struct(&data))
			printf("Error, malloc failed\n");
		while (i < data.nb_philo)
		{
			if (pthread_create(&data.threads[i], NULL, routine, &data.philo[i]))
				printf("Error, thread creation failed\n");
			i++;
		}
		pthread_mutex_unlock(&data.philo->mutex_sync);
		ft_exit(&data);
	}
	else
		printf("Error, wrong number of arguments\n");
	return (0);
}
