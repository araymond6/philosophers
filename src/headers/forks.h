/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araymond <araymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:36:59 by araymond          #+#    #+#             */
/*   Updated: 2023/06/28 16:08:35 by araymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORKS_H
# define FORKS_H

#include "main.h"

//int		lock_check(t_philo *philo);
int		lock_forks(t_philo *philo);
//int		unlock_check(t_philo *philo);
int		unlock_forks(t_philo *philo);

#endif