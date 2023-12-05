/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:28:04 by bfaure            #+#    #+#             */
/*   Updated: 2023/12/05 18:50:57 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

t_uint	pars_arg(t_data *data, char **argv)
{
	t_uint	i;
	t_uint	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	data->nb_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->nb_eat = ft_atoi(argv[5]);
	else
		data->nb_eat = -1;
	return (0);
}

t_uint	thread_create(t_data *data)
{
	t_uint	i;

	i = 0;
	pthread_create(&data->monitor_thread, NULL, monitoring, data);
	pthread_detach(data->monitor_thread);
	pthread_mutex_lock(&data->mutex->mutex_sync);
	while (i < data->nb_philo)
	{
		if (pthread_create(&data->philo_thread[i],
				NULL, routine, &data->philo[i]))
			return (1);
		i++;
	}
	pthread_mutex_unlock(&data->mutex->mutex_sync);
	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_join(data->philo_thread[i], NULL))
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data			data;
	t_uint			i;

	i = 0;
	if (argc == 5 || argc == 6)
	{
		if (pars_arg(&data, argv) == 1)
			return (printf("Error: Wrong argument\n"), 1);
		if (init_data(&data) == 1)
			return (1);
		if (thread_create(&data) == 1)
			return (printf("Error: Thread creation failed\n"), 1);
		while (i < data.nb_philo)
			if (pthread_join(data.philo_thread[i++], NULL))
				return (printf("Error: Thread join failed\n"), 1);
	}
	else
	{
		printf("Error: Wrong number of arguments\n");
		return (1);
	}
	return (0);
}
