/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araymond <araymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:50:56 by araymond          #+#    #+#             */
/*   Updated: 2023/07/25 11:30:39 by araymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/utils.h"

void	clear_philosophers(t_philo **philo)
{
	t_philo	*temp;
	int		i;
	int		philo_count; 

	if (!philo)
		return ;
	i = 0;
	philo_count = (*philo)->params.philo_count;
	temp = *philo;
	while (i < philo_count)
	{
		*philo = (*philo)->right_philo;
		pthread_mutex_destroy(&temp->fork);
		free(temp);
		temp = (*philo);
		i++;
	}
}

int	addback_philo(t_philo **philo)
{
	t_philo	*temp;
	t_philo	*next;

	temp = *philo;
	while (!(temp->right_philo == NULL))
		temp = temp->right_philo;
	next = initiate_philo((*philo)->params, (*philo)->info);
	if (!next)
	{
		clear_philosophers(philo);
		return (ERROR);
	}
	temp->right_philo = next;
	return (SUCCESS);
}

pthread_mutex_t	*death_function(void)
{
	static pthread_mutex_t	func_death = PTHREAD_MUTEX_INITIALIZER;

	return (&func_death);
}

t_ms	timestamp(void)
{
	t_time	time;

	if (gettimeofday(&time, NULL) != 0)
		return (ERROR);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	print_message(t_philo *philo, char *action)
{
	printf("%llu %d %s\n", timestamp() - philo->info->start_time, \
	philo->philo_number, action);
	return (SUCCESS);
}
