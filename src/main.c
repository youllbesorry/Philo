/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:28:04 by bfaure            #+#    #+#             */
/*   Updated: 2023/11/29 18:26:01 by bfaure           ###   ########lyon.fr   */
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
		if (argc == 6)
			data.nb_eat = ft_atoi(argv[5]);
		data.threads = malloc(sizeof(pthread_t) * data.nb_philo);
		if (!data.threads)
			printf("Error, malloc failed\n");
		data.mutex = malloc(sizeof(pthread_mutex_t) * data.nb_philo);
		if (!data.mutex)
			printf("Error, malloc failed\n");
		while (i < data.nb_philo)
		{
			pthread_mutex_init(&data.mutex[i], NULL);
			if (pthread_create(&data.threads[i], NULL, routine, &data))
				printf("Error, thread creation failed\n");
			i++;
		}
		i = 0;
		while (i < data.nb_philo)
		{
			if (pthread_join(data.threads[i], NULL))
				printf("Error, thread join failed\n");
			i++;
		}
		i = 0;
		while (i < data.nb_philo)
		{
			pthread_mutex_destroy(&data.mutex[i]);
			i++;
		}
		free(data.threads);
	}
	else
		printf("Error, wrong number of arguments\n");
	return (0);
}
