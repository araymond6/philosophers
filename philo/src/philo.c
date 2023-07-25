/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araymond <araymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:07:45 by araymond          #+#    #+#             */
/*   Updated: 2023/07/25 11:33:29 by araymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/utils.h"
#include "headers/philo.h"
#include "headers/forks.h"

// philo thread for 5  or 6 args
static void	*life(void *arg)
{
	t_philo	*philo;

	philo = arg;
	pthread_mutex_lock(death_function());
	if (philo->info->start_time == 0) 
		philo->info->start_time = timestamp();
	pthread_mutex_unlock(death_function());
	philo->last_meal = philo->info->start_time;
	while (!is_philo_dead(philo))
	{
		if (!lock_forks(philo))
			break ;
		if (philo->params.amount_to_eat > 0)
		{
			if (philo->meal_count >= philo->params.amount_to_eat)
				break ;
		}
		usleep(300);
	}
	return (NULL);
}

// philo thread for 1 thread
static void	*life3(void *arg)
{
	t_philo	*philo;

	philo = arg;
	philo->info->start_time = timestamp();
	philo->last_meal = philo->info->start_time;
	while (!is_philo_dead(philo))
		usleep(300);
	return (NULL);
}

static void	create_loop(t_philo *philo)
{
	t_philo	*temp;
	int		i;

	i = 0;
	temp = philo;
	while (i++ < (int)temp->params.philo_count)
	{
		if (philo->params.philo_count == 1)
		{
			if (pthread_create(&temp->thread_id, NULL, &life3, temp) != 0)
				break ;
		}
		else
		{
			if (pthread_create(&temp->thread_id, NULL, &life, temp) != 0)
				break ;
		}
		temp = temp->right_philo;
	}
}

void	create_philo(t_params params)
{
	t_philo	*philo;
	t_philo	*temp;
	t_info	info;
	int		i;

	info.death_time = 0;
	info.start_time = 0;
	info.death_philo = 0;
	philo = initiate_philo(params, &info);
	if (philo == NULL)
		return ;
	if (set_philosophers(params, &philo) == NULL)
		return ;
	create_loop(philo);
	temp = philo;
	i = 0;
	while (i++ < philo->params.philo_count)
	{
		pthread_join(temp->thread_id, NULL);
		temp = temp->right_philo;
	}
	if (philo->info->death_time)
		printf("%llu %d has died\n", philo->info->death_time, 
			philo->info->death_philo);
	clear_philosophers(&philo);
}
