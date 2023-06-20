/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araymond <araymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:15:01 by araymond          #+#    #+#             */
/*   Updated: 2023/06/15 12:00:44 by araymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <limits.h>
#include <sys/time.h>

# define ERROR 0
# define SUCCESS 1

// For print function
# define FORK "has taken a fork"
# define EATING "is eating"
# define SLEEPING "is sleeping"
# define THINKING "is thinking"
# define DEAD "died"

typedef unsigned long long t_ms;

typedef struct timeval t_time;

typedef struct s_params
{
	union 
	{
		struct 
		{
			unsigned int	philo_count;
			unsigned int	time_to_die;
			unsigned int	time_to_eat;
			unsigned int	time_to_sleep;
			unsigned int	amount_to_eat;
		};
		unsigned int params[5];
	};
	
}	t_params;

typedef struct s_philo
{
	unsigned int		philo_number;
	pthread_t			thread_id;
	pthread_t			cycle_id;
	pthread_mutex_t		*fork;
	int					locked;
	int					dead;
	t_ms				eating;
	t_ms				sleeping;
	t_ms				start_time;
	t_ms				last_meal;
	struct s_params		*params;
	struct s_philo		*right_philo;
}	t_philo;

void			ft_bzero(void *arg, unsigned int size);
pthread_mutex_t	*lock_function(void *arg);

#endif