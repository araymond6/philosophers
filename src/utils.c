/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araymond <araymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:00:03 by araymond          #+#    #+#             */
/*   Updated: 2023/06/15 11:31:42 by araymond         ###   ########.fr       */
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

t_params	*set_params(int argc, char **argv)
{
	t_params	*params;
	int			i;
	int			j;

	params = malloc(sizeof(t_params));
	if (!params)
		return (NULL);
	i = 1;
	j = 0;
	while (i < argc)
	{
		params->params[j++] = ft_atoi(argv[i++]);
	}
	return (params);
}

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

t_philo	*initiate_philo(t_params *params)
{
	t_philo		*philo;
	static int	philo_count;

	if (philo_count == 0)
		philo_count = 1;
	philo = malloc(sizeof(t_philo));
	if (philo == NULL)
		return (NULL);
	ft_bzero(philo, sizeof(t_philo));
	if (!initiate_fork(philo))
	{
		free(philo);
		return (NULL);
	}
	philo->philo_number = philo_count++;
	philo->params = params;
	return (philo);
}

t_philo	*set_philosophers(t_params *params, t_philo **philo)
{
	unsigned int	i;
	t_philo			*temp;

	i = 0;
	temp = *philo;
	while (i < params->philo_count)
	{
		if (!(i + 1 == params->philo_count))
		{
			if (addback_philo(philo) == 0)
				return (clear_philosophers(philo), NULL);
			temp = temp->right_philo;
			if (temp->philo_number == params->philo_count)
				temp->right_philo = *philo;
		}
		i++;
	}
	return (*philo);
}