/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araymond <araymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:24:26 by araymond          #+#    #+#             */
/*   Updated: 2023/06/02 15:29:21 by araymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ACTIONS_H
# define PHILO_ACTIONS_H

#include "main.h"

int	print_message(t_philo *philo, char *action);
int	philo_sleep(t_philo *philo);
int	death_check(t_philo *philo);

#endif