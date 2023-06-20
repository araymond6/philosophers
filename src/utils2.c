/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araymond <araymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:50:56 by araymond          #+#    #+#             */
/*   Updated: 2023/06/15 11:53:42 by araymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/utils.h"

void	clear_philosophers(t_philo **philo)
{
	t_philo	*temp;
	
	temp = *philo;
	while ((*philo)->right_philo != NULL)
	{
		if (temp)
		*philo = (*philo)->right_philo;
		pthread_mutex_destroy(temp->fork);
		free(temp->fork);
		free(temp);
		temp = *philo;
	}
}

int	addback_philo(t_philo **philo)
{
	t_philo	*temp;
	t_philo	*next;

	temp = *philo;
	while (!(temp->right_philo == NULL))
		temp = temp->right_philo;
	next = initiate_philo((*philo)->params);
	if (!next)
	{
		clear_philosophers(philo);
		return (ERROR);
	}
	temp->right_philo = next;
	return (SUCCESS);
}

int	initiate_fork(t_philo *philo)
{
	philo->fork = malloc(sizeof(pthread_mutex_t));
	if (!philo->fork)
		return (ERROR);
	if (pthread_mutex_init(philo->fork, NULL) != 0)
	{
		free(philo);
		return (ERROR);
	}
	return (SUCCESS);
}

pthread_mutex_t	*init_mutex(pthread_mutex_t *prev)
{
	pthread_mutex_t *mutex;

	if (prev)
		return (prev);
	mutex = malloc(sizeof(pthread_mutex_t));
	if (!mutex)
		return (NULL);
	if (pthread_mutex_init(mutex, NULL) != 0)
	{
		free(mutex);
		return (NULL);
	}
	return (mutex);
}