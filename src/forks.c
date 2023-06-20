/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araymond <araymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:37:01 by araymond          #+#    #+#             */
/*   Updated: 2023/06/15 15:54:47 by araymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/utils.h"
#include "headers/philo_actions.h"
#include "headers/philo.h"
#include "headers/forks.h"

int	lock_check(t_philo *philo)
{
	while (philo->locked != 1 || philo->right_philo->locked != 1)
	{
		usleep(10);
		pthread_mutex_lock(lock_function(NULL));
		if (philo->locked == 0 && philo->right_philo->locked == 0)
		{
			if (!lock_forks(philo))
				return (ERROR);
		}
		else
		{
			if (!print_message(philo, THINKING))
				return (ERROR);
		}
		pthread_mutex_unlock(lock_function(NULL));
		if (!death_check(philo))
		return (ERROR);
	}
	if (!unlock_check(philo))
		return (ERROR);
	return (SUCCESS);
}

int	unlock_check(t_philo *philo)
{
	if (philo->eating != 0)
	{
		if (!ft_sleep(philo->params->time_to_eat))
			return (ERROR);
		if (!death_check(philo))
			return (ERROR);
		pthread_mutex_lock(lock_function(NULL));
		if (!unlock_forks(philo))
			return (ERROR);
		pthread_mutex_unlock(lock_function(NULL));
		if (!philo_sleep(philo))
			return (ERROR);
	}
	return (SUCCESS);
}

int	unlock_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->fork);
	philo->locked = 0;
	pthread_mutex_unlock(philo->right_philo->fork);
	philo->right_philo->locked = 0;
	philo->eating = 0;
	philo->last_meal = timestamp();
	return (SUCCESS);
}

int	lock_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->fork);
	if (!print_message(philo, FORK))
		return (ERROR);
	philo->locked = 1;
	pthread_mutex_lock(philo->right_philo->fork);
	if (!print_message(philo, FORK))
		return (ERROR);
	philo->right_philo->locked = 1;
	philo->eating = 1;
	if (!print_message(philo, EATING))
		return (ERROR);
	return (SUCCESS);
}
