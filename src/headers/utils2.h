/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araymond <araymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:24:32 by araymond          #+#    #+#             */
/*   Updated: 2023/06/15 11:53:45 by araymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS2_H
# define UTILS2_H

#include "main.h"

int				addback_philo(t_philo **philo);
void			clear_philosophers(t_philo **philo);
int				initiate_fork(t_philo *philo);
pthread_mutex_t	*init_mutex(pthread_mutex_t *prev);

#endif