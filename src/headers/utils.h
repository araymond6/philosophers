/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araymond <araymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:24:30 by araymond          #+#    #+#             */
/*   Updated: 2023/06/27 12:19:45 by araymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include "main.h"
#include "utils2.h"
#include "utils3.h"

t_params	*set_params(int argc, char **argv);
int			is_digit(char c);
int			ft_atoi(char *str);
t_philo	*initiate_philo(t_params *params);
t_philo	*set_philosophers(t_params *params, t_philo **philo);

#endif