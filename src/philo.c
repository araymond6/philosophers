/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araymond <araymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:07:45 by araymond          #+#    #+#             */
/*   Updated: 2023/06/16 14:15:33 by araymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/utils.h"
#include "headers/philo_actions.h"
#include "headers/philo.h"
#include "headers/forks.h"

t_ms	timestamp(void)
{
	t_time	time;

	if (gettimeofday(&time, NULL) != 0)
		return (ERROR);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	ft_sleep(t_ms time)
{
	t_ms	start_time;

	start_time = timestamp();
	while (timestamp() - start_time < time)
	{
		if (usleep(100) != 0)
			return (ERROR);
	}
	return (SUCCESS);
}

// philo thread for 5 args
void	*life(void *arg)
{
	t_philo	*philo;

	philo = arg;
	if (pthread_detach(philo->thread_id) != 0)
		return (NULL);
	philo->start_time = timestamp();
	philo->last_meal = philo->start_time;
	if (philo->philo_number % 2 == 1)
		usleep(100);
	while (1)
	{
		if (!lock_check(philo))
			break ;
	}
	return (NULL);
}

void	create_philo(t_params *params)
{
	t_philo	*philo;
	t_philo	*temp;
	int		i;

	i = 0;
	philo = initiate_philo(params);
	if (philo == NULL)
		return ;
	if (set_philosophers(params, &philo) == NULL)
		return ;
	temp = philo;
	while (++i < (int)philo->params->philo_count)
	{
		if (pthread_create(&temp->thread_id, NULL, &life, temp) != 0)
			break ;
		temp = temp->right_philo;
	}
	temp = philo;
	while (--i > 0)
	{
		pthread_join(temp->thread_id, NULL);
		temp = temp->right_philo;
	}
}
