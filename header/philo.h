/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:28:08 by bfaure            #+#    #+#             */
/*   Updated: 2023/12/01 16:30:27 by bfaure           ###   ########lyon.fr   */
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
void	eat(t_philo *philo);
void	ft_sleep(t_philo *philo);
void	think(t_philo *philo);
void	*death(void *data_arg);
void	take_fork(t_philo *philo, t_uint i);

#endif