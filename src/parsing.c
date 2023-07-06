/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araymond <araymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:15:50 by araymond          #+#    #+#             */
/*   Updated: 2023/06/28 16:45:34 by araymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/main.h"
#include "headers/utils.h"
#include "headers/philo.h"
#include "headers/forks.h"
#include "headers/philo_actions.h"

static int	eatnsleep(t_philo *philo)
{
	pthread_mutex_unlock(lock_function(NULL));
	if (!is_philo_dead(philo))
 		return (ERROR);
	if (!philo_action(philo, philo->params->time_to_eat))
		return (ERROR);
	pthread_mutex_lock(lock_function(NULL));
	if (!unlock_forks(philo))
	{
		pthread_mutex_unlock(lock_function(NULL));
		return (ERROR);
	}
	pthread_mutex_unlock(lock_function(NULL));
	if (!print_message(philo, SLEEPING))
		return (ERROR);
	if (!philo_action(philo, philo->params->time_to_sleep))
		return (ERROR);
	if (!print_message(philo, THINKING))
			return (ERROR);
	return (SUCCESS);
}

int	lock_check(t_philo *philo)
{
	pthread_mutex_lock(lock_function(NULL));
	if (philo->locked == 0 && philo->right_philo->locked == 0)
	{
		if (!lock_forks(philo))
		{
			pthread_mutex_unlock(lock_function(NULL));
			return (ERROR);
		}
	}
	else
	{
		pthread_mutex_unlock(lock_function(NULL));
		return (SUCCESS);
	}
	if (!eatnsleep(philo))
		return (ERROR);
	return (SUCCESS);
}


int	check_numbers(char *arg)
{
	int				i;
	int				j;
	unsigned int	nb;

	i = 0;
	j = 0;
	if (arg[i] == '\0')
		return (ERROR);
	while (arg[i])
	{
		while (arg[i] == '0')
			i++;
		while (arg[i])
		{
			if (!is_digit(arg[i++]))
				return (ERROR);
			j++;
		}
	}
	if (j > 10)
		return (ERROR);
	nb = ft_atoi(arg);
	if (nb > INT_MAX || nb < 0)
		return (ERROR);
	return (SUCCESS);
}

int	parse_args(int argc, char **argv)
{
	t_params	*params;
	int			i;
	
	i = 1;
	while (argv[i])
	{
		if (check_numbers(argv[i]) == ERROR)
			return (clear_philosophers(NULL), ERROR);
		i++;
	}
	params = set_params(argc, argv);
	create_philo(params, argc);
	return (SUCCESS);
}