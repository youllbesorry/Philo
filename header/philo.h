/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:28:08 by bfaure            #+#    #+#             */
/*   Updated: 2023/11/29 16:17:18 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "struct.h"
# include <stdio.h>
# include <stdlib.h>

void	*routine(void *arg);
int		main(int argc, char **argv);
int		ft_atoi(const char *str);

#endif