/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:31:51 by bfaure            #+#    #+#             */
/*   Updated: 2023/12/12 16:50:31 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/philo.h"

bool	is_dead(t_data *data)
{
	bool	ret;

	pthread_mutex_lock(&data->mutex->mutex_all);
	ret = data->is_alive;
	pthread_mutex_unlock(&data->mutex->mutex_all);
	return (ret);
}

bool	running(t_data *data)
{
	bool	ret;

	pthread_mutex_lock(&data->mutex->mutex_all);
	ret = (data->is_alive && !data->is_finish);
	pthread_mutex_unlock(&data->mutex->mutex_all);
	return (ret);
}
