/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araymond <araymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:24:32 by araymond          #+#    #+#             */
/*   Updated: 2023/07/25 11:30:48 by araymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS2_H
# define UTILS2_H

# include "main.h"

int				addback_philo(t_philo **philo);
void			clear_philosophers(t_philo **philo);
pthread_mutex_t	*death_function(void);
t_ms			timestamp(void);
int				print_message(t_philo *philo, char *action);

#endif