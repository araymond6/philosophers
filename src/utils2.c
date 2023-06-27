/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araymond <araymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:50:56 by araymond          #+#    #+#             */
/*   Updated: 2023/06/27 14:33:49 by araymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/utils.h"

int	pthread_join_loop(t_philo *philo)
{
	t_philo	*temp;
	int		i;

	i = 0;
	temp = philo;
	while (++i < (int)philo->params->philo_count)
	{
		if (pthread_join(temp->thread_id, NULL) != 0)
			return (ERROR);
		temp = temp->right_philo;
	}
	return (SUCCESS);
}

void	clear_philosophers(t_philo **philo)
{
	t_philo	*temp;
	
	if (!philo)
		return ;
	temp = *philo;
	while (temp != NULL)
	{
		if (temp)
		{
			*philo = (*philo)->right_philo;
			pthread_mutex_destroy(temp->fork);
			pthread_mutex_destroy(lock_function(NULL));
			free(temp);
		}
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

pthread_mutex_t	*init_mutex(void)
{
	pthread_mutex_t *mutex;

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