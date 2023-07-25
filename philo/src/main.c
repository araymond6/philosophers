/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araymond <araymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:14:49 by araymond          #+#    #+#             */
/*   Updated: 2023/07/25 11:33:17 by araymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/utils.h"
#include "headers/philo.h"
#include "headers/forks.h"

static int	check_numbers(char *arg)
{
	int				i;
	int				j;
	unsigned int	nb;

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

static int	parse_args(int argc, char **argv)
{
	t_params	params;
	int			i;

	i = 1;
	while (argv[i])
	{
		if (check_numbers(argv[i]) == ERROR)
			return (clear_philosophers(NULL), ERROR);
		i++;
	}
	params = set_params(argc, argv);
	create_philo(params);
	return (SUCCESS);
}

void	ft_bzero(void *arg, unsigned int size)
{
	char	*str;

	if (!arg || size == 0)
		return ;
	str = arg;
	while (size-- > 0)
		*(str++) = 0;
}

int	main(int argc, char **argv)
{
	if (argc == 5 || argc == 6)
	{
		if (!parse_args(argc, argv))
		{
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
