/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araymond <araymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:14:49 by araymond          #+#    #+#             */
/*   Updated: 2023/06/14 17:08:19 by araymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/parsing.h"

void	ft_bzero(void *arg, unsigned int size)
{
	char	*str;

	if (!arg || size == 0)
		return ;
	str = arg;
	while (size-- > 0)
		*(str++) = 0;
}

pthread_mutex_t	*lock_function(void *arg)
{
	static pthread_mutex_t	*func_lock;

	if (arg)
		func_lock = arg;
	return (func_lock);
}

int main(int argc, char **argv)
{
	pthread_mutex_t	*func_lock;

	func_lock = malloc(sizeof(func_lock));
	if (!func_lock)
		return (EXIT_FAILURE);
	lock_function(func_lock);
	if (pthread_mutex_init(lock_function(NULL), NULL) != 0)
	{
		free(func_lock);
		return (EXIT_FAILURE);
	}
	if (argc == 5 || argc == 6)
	{
		if (parse_args(argc, argv) == 0)
		{
			printf("Error.");
			return (EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
