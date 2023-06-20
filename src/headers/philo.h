/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araymond <araymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:24:28 by araymond          #+#    #+#             */
/*   Updated: 2023/06/15 15:25:46 by araymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include "main.h"

void	create_philo(t_params *params);
void	*life(void *arg);
t_ms	timestamp(void);
int		ft_sleep(t_ms time);

#endif