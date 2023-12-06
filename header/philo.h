/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:28:08 by bfaure            #+#    #+#             */
/*   Updated: 2023/12/06 18:59:01 by bfaure           ###   ########lyon.fr   */
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
void	eat(t_philo *philo);
void	ft_exit(t_data *data);
void	*monitoring(void *arg);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);
void	unlock_all(t_data *data);
void	drop_fork(t_philo *philo);
void	take_fork(t_philo *philo);
void	monitor_thread_create(t_data *data);

int		ft_atoi(const char *str);
int		main(int argc, char **argv);

t_uint	ft_get_time(void);
t_uint	ft_isdigit(int c);
t_uint	ft_usleep(t_uint time);
t_uint	init_mutex(t_data *data);
t_uint	init_philo(t_data *data);
t_uint	init_data(t_data *data);
t_uint	multi_monitor_init(t_data *data);
t_uint	mono_monitor_init(t_data *data);
t_uint	ft_message(t_philo *philo, char *str);

#endif