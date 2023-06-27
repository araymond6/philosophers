/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araymond <araymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:07:45 by araymond          #+#    #+#             */
/*   Updated: 2023/06/27 15:18:07 by araymond         ###   ########.fr       */
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
	t_philo	*temp;
	int		i;

	philo = arg;
	i = 0;
	philo->start_time = timestamp();
	philo->last_meal = philo->start_time;
	temp = philo;
	if (philo->philo_number % 2 == 0)
		usleep(100);
	while (1)
	{
		if (!lock_check(philo))
			break ;
		if (!is_philo_dead(philo) || philo->meal_count >= philo->params->amount_to_eat)
			break ;
	}
	return (NULL);
}

// philo thread for 4 args
void	*life2(void *arg)
{
	t_philo	*philo;
	t_philo	*temp;
	int		i;

	philo = arg;
	i = 0;
	philo->start_time = timestamp();
	philo->last_meal = philo->start_time;
	temp = philo;
	if (philo->philo_number % 2 == 0)
		usleep(100);
	while (1)
	{
		if (!lock_check(philo))
			break ;
		if (!is_philo_dead(philo))
			break ;
	}
	return (NULL);
}

// philo thread for 1 thread
void	*life3(void *arg)
{
	t_philo	*philo;
	t_philo	*temp;
	int		i;

	philo = arg;
	i = 0;
	philo->start_time = timestamp();
	philo->last_meal = philo->start_time;
	temp = philo;
	while (1)
	{
		if (!is_philo_dead(philo))
			return (NULL);
	}
	return (NULL);
}

void	create_philo(t_params *params, int argc)
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
	while (i++ < (int)temp->params->philo_count)
	{
		if (philo->params->philo_count == 1)
		{
			if (pthread_create(&temp->thread_id, NULL, &life3, temp) != 0)
				break ;
		}
		else if (argc == 6)
		{
			if (pthread_create(&temp->thread_id, NULL, &life, temp) != 0)
				break ;
		}
		else
		{
			if (pthread_create(&temp->thread_id, NULL, &life2, temp) != 0)
				break ;
		}
		temp = temp->right_philo;
	}
	temp = philo;
	i = 0;
	while (i++ < (int)philo->params->philo_count)
	{
		pthread_join(temp->thread_id, NULL);
		temp = temp->right_philo;
	}
}
