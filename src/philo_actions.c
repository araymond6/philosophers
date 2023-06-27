/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araymond <araymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:00:13 by araymond          #+#    #+#             */
/*   Updated: 2023/06/27 15:19:35 by araymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/utils.h"
#include "headers/philo.h"
#include "headers/philo_actions.h"
#include "headers/forks.h"

int	is_philo_dead(t_philo *philo)
{
	int		i;
	t_philo	*temp;
	
	i = 0;
	temp = philo;
	while (i < philo->params->philo_count)
	{
		if ((timestamp() - temp->last_meal) >= \
			(t_ms)temp->params->time_to_die)
		{
			print_message(temp, DEAD);
			temp->dead = 1;
			return (ERROR);
		}
		i++;
	}
	
	return (SUCCESS);
}

int	print_message(t_philo *philo, char *action)
{
	pthread_mutex_lock(print_function(NULL));
	printf("%llu %d %s\n", timestamp() - philo->start_time, \
	philo->philo_number, action);
	pthread_mutex_unlock(print_function(NULL));
	return (SUCCESS);
}

int	philo_sleep(t_philo *philo)
{
	if (!print_message(philo, SLEEPING))
		return (ERROR);
	if (!philo_action(philo, philo->params->time_to_sleep))
		return (ERROR);
	if (!print_message(philo, THINKING))
			return (ERROR);
	usleep(200);
	return (SUCCESS);
}

int	philo_action(t_philo *philo, unsigned int time)
{
	t_ms	start_time;

	start_time = timestamp();
	while (timestamp() - start_time <= time)
	{
		if (!is_philo_dead(philo))
			return (ERROR);
	}
	return (SUCCESS);
}
