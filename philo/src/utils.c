/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araymond <araymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:00:03 by araymond          #+#    #+#             */
/*   Updated: 2023/07/24 15:49:05 by araymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/utils.h"

int	ft_atoi(char *str)
{
	int			i;
	int			j;
	long long	nb;

	i = 0;
	j = 0;
	nb = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			j = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	if (j)
		return (-nb);
	return (nb);
}

t_params	set_params(int argc, char **argv)
{
	t_params	params;
	int			i;
	int			j;

	i = 1;
	j = 0;
	while (i < argc)
		params.params[j++] = ft_atoi(argv[i++]);
	if (argc == 5)
		params.amount_to_eat = -1;
	return (params);
}

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

t_philo	*initiate_philo(t_params params, t_info *info)
{
	t_philo		*philo;
	static int	philo_count = 1;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	ft_bzero(philo, sizeof(t_philo));
	pthread_mutex_init(&philo->fork, NULL);
	philo->philo_number = philo_count++;
	philo->params = params;
	philo->info = info;
	return (philo);
}

t_philo	*set_philosophers(t_params params, t_philo **philo)
{
	int		i;
	t_philo	*temp;

	i = 0;
	temp = *philo;
	if (temp->params.philo_count == 1)
	{
		temp->right_philo = *philo;
		return (*philo);
	}
	while (i < params.philo_count)
	{
		if (i + 1 != params.philo_count)
		{
			if (addback_philo(philo) == 0)
				return (clear_philosophers(philo), NULL);
			temp = temp->right_philo;
			if (temp->philo_number == params.philo_count)
				temp->right_philo = *philo;
		}
		i++;
	}
	return (*philo);
}
