/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araymond <araymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:00:13 by araymond          #+#    #+#             */
/*   Updated: 2023/06/15 12:35:52 by araymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/utils.h"
#include "headers/philo.h"
#include "headers/philo_actions.h"
#include "headers/forks.h"

int	print_message(t_philo *philo, char *action)
{
	static pthread_mutex_t	*printing;

	printing = init_mutex(printing);
	if (!printing)
		return (ERROR);
	pthread_mutex_lock(printing);
	printf("%llu %d %s\n", timestamp() - philo->start_time, \
	philo->philo_number, action);
	pthread_mutex_unlock(printing);
	return (SUCCESS);
}

int	philo_sleep(t_philo *philo)
{
	if (!print_message(philo, SLEEPING))
		return (ERROR);
	if (!ft_sleep(philo->params->time_to_sleep))
		return (ERROR);
	if (!death_check(philo))
		return (ERROR);
	return (SUCCESS);
}

int	death_check(t_philo *philo)
{
	if ((timestamp() - philo->last_meal) >= \
		philo->params->time_to_die)
	{
		print_message(philo, DEAD);
		philo->dead = 1;
		return (ERROR);
	}
	return (SUCCESS);
}
