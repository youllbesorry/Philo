/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:28:08 by bfaure            #+#    #+#             */
/*   Updated: 2023/12/04 13:46:49 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "struct.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

void	*routine(void *arg);
int		main(int argc, char **argv);
int		ft_atoi(const char *str);
t_uint	init_struct(t_data *data);
t_uint	ft_exit(t_data *data);
void	eat(t_philo *philo, t_uint i);
void	ft_sleep(t_philo *philo);
void	think(t_philo *philo);
void	*death(void *data_arg);
void	take_fork(t_philo *philo, t_uint i);
t_uint	ft_get_time(void);
t_uint	ft_usleep(t_uint time);
t_uint	ft_message(t_philo *philo, char *str);
t_uint	init_mutex(t_data *data);
void	drop_fork(t_philo *philo, t_uint i);

#endif