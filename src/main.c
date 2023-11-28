/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:28:04 by bfaure            #+#    #+#             */
/*   Updated: 2023/11/28 14:40:24 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	*routine(void *arg)
{
	t_philo			philo;
	static t_uint	i = 0;

	(void)arg;
	philo.id_philo = i++;
	printf("Hello from thread %u\n", philo.id_philo);
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_data		data;

	if (argc == 5 || argc == 6)
	{
		data.nb_philo = ft_atoi(argv[1]);
		data.time_to_die = ft_atoi(argv[2]);
		data.time_to_eat = ft_atoi(argv[3]);
		data.time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			data.nb_eat = ft_atoi(argv[5]);
		while (data.nb_philo--)
		{
			if (pthread_create(&data.thread, NULL, routine, NULL))
				printf("Error, thread creation failed\n");
			if (pthread_join(data.thread, NULL))
				printf("Error, thread join failed\n");
		}
	}
	else
		printf("Error, wrong number of arguments\n");
	return (0);
}
