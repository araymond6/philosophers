/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araymond <araymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:24:26 by araymond          #+#    #+#             */
/*   Updated: 2023/06/28 16:08:04 by araymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ACTIONS_H
# define PHILO_ACTIONS_H

#include "main.h"

int	philo_action(t_philo *philo, unsigned int time);
int	print_message(t_philo *philo, char *action);
int	is_philo_dead(t_philo *philo);

#endif