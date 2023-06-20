/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araymond <araymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:15:50 by araymond          #+#    #+#             */
/*   Updated: 2023/06/14 17:31:03 by araymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/main.h"
#include "headers/utils.h"
#include "headers/philo.h"

int	check_numbers(char *arg)
{
	int	i;
	int	j;
	int	nb;

	i = 0;
	j = 0;
	if (arg[i] == '\0')
		return (ERROR);
	while (arg[i])
	{
		while (arg[i] == '0')
			i++;
		while (arg[i])
		{
			if (!is_digit(arg[i++]))
				return (ERROR);
			j++;
		}
	}
	if (j > 10)
		return (ERROR);
	nb = ft_atoi(arg);
	if (nb > INT_MAX || nb < 0)
		return (ERROR);
	return (SUCCESS);
}

int	parse_args(int argc, char **argv)
{
	t_params	*params;
	int			i;
	
	i = 1;
	while (argv[i])
	{
		if (check_numbers(argv[i++]) == ERROR)
			return (clear_philosophers(NULL), ERROR);
	}
	params = set_params(argc, argv);
	create_philo(params);
	return (SUCCESS);
}