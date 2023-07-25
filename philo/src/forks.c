/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araymond <araymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:37:01 by araymond          #+#    #+#             */
/*   Updated: 2023/07/25 11:34:51 by araymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/utils.h"
#include "headers/philo.h"
#include "headers/forks.h"

static int	philo_action(t_philo *philo, t_ms time)
{
	t_ms	start_time;

	start_time = timestamp();
	while (timestamp() - start_time < time)
	{
		if (is_philo_dead(philo))
			return (ERROR);
	}
	return (SUCCESS);
}

static int	eatnsleep(t_philo *philo)
{
	if (!philo_action(philo, philo->params.time_to_eat))
		return (ERROR);
	if (!unlock_forks(philo))
		return (ERROR);
	if (philo->meal_count == philo->params.amount_to_eat)
		return (SUCCESS);
	if (!print_message(philo, SLEEPING))
		return (ERROR);
	if (!philo_action(philo, philo->params.time_to_sleep))
		return (ERROR);
	if (!print_message(philo, THINKING))
		return (ERROR);
	return (SUCCESS);
}

int	unlock_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	pthread_mutex_lock(&philo->right_philo->fork);
	philo->locked = 0;
	philo->right_philo->locked = 0;
	philo->eating = 0;
	philo->meal_count++;
	philo->last_meal = timestamp();
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->right_philo->fork);
	return (SUCCESS);
}

int	lock_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	pthread_mutex_lock(&philo->right_philo->fork);
	if (philo->locked || philo->right_philo->locked)
	{
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->right_philo->fork);
		return (SUCCESS);
	}
	if (!print_message(philo, FORK))
		return (ERROR);
	if (!print_message(philo, FORK))
		return (ERROR);
	philo->locked = 1;
	philo->right_philo->locked = 1;
	philo->eating = 1;
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->right_philo->fork);
	if (!print_message(philo, EATING))
		return (ERROR);
	if (!eatnsleep(philo))
		return (ERROR);
	return (SUCCESS);
}

int	is_philo_dead(t_philo *philo)
{
	pthread_mutex_lock(death_function());
	if (philo->info->death_philo)
		return (pthread_mutex_unlock(death_function()), 1);
	pthread_mutex_unlock(death_function());
	if (timestamp() - philo->last_meal > (t_ms)philo->params.time_to_die)
	{
		pthread_mutex_lock(death_function());
		philo->info->death_philo = philo->philo_number;
		philo->info->death_time = timestamp() - philo->info->start_time;
		pthread_mutex_unlock(death_function());
	}
	return (0);
}
