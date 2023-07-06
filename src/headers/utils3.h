/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araymond <araymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:19:30 by araymond          #+#    #+#             */
/*   Updated: 2023/06/27 15:48:07 by araymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS3_H
# define UTILS3_H

#include "main.h"

pthread_mutex_t	*lock_function(void *arg);
pthread_mutex_t	*print_function(void *arg);
pthread_mutex_t	*death_function(void *arg);

#endif