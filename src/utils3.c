/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araymond <araymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:19:25 by araymond          #+#    #+#             */
/*   Updated: 2023/06/27 15:47:59 by araymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/main.h"

pthread_mutex_t	*lock_function(void *arg)
{
	static pthread_mutex_t	*func_lock;

	if (arg)
		func_lock = arg;
	return (func_lock);
}

pthread_mutex_t	*print_function(void *arg)
{
	static pthread_mutex_t	*func_print;

	if (arg)
		func_print = arg;
	return (func_print);
}

pthread_mutex_t	*death_function(void *arg)
{
	static pthread_mutex_t	*func_death;

	if (arg)
		func_death = arg;
	return (func_death);
}