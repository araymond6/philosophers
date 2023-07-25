/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araymond <araymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:15:01 by araymond          #+#    #+#             */
/*   Updated: 2023/07/20 14:52:21 by araymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>

# define ERROR 0
# define SUCCESS 1

// For print function
# define FORK "has taken a fork"
# define EATING "is eating"
# define SLEEPING "is sleeping"
# define THINKING "is thinking"
# define DEAD "died"

typedef unsigned long long	t_ms;
typedef struct timeval		t_time;

typedef struct s_params
{
	union 
	{
		struct 
		{
			int	philo_count;
			int	time_to_die;
			int	time_to_eat;
			int	time_to_sleep;
			int	amount_to_eat;
		};
		int	params[5];
	};
}	t_params;

typedef struct s_info
{
	int		death_philo;
	t_ms	death_time;
	t_ms	start_time;
}	t_info;

typedef struct s_philo
{
	int					philo_number;
	pthread_t			thread_id;
	pthread_mutex_t		fork;
	int					locked;
	int					dead;
	int					meal_count;
	t_ms				eating;
	t_ms				sleeping;
	t_ms				last_meal;
	struct s_params		params;
	struct s_philo		*right_philo;
	struct s_info		*info;
}	t_philo;

void			ft_bzero(void *arg, unsigned int size);

#endif