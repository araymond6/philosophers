/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araymond <araymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:14:49 by araymond          #+#    #+#             */
/*   Updated: 2023/06/27 12:48:41 by araymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/parsing.h"
#include "headers/utils.h"

void	ft_bzero(void *arg, unsigned int size)
{
	char	*str;

	if (!arg || size == 0)
		return ;
	str = arg;
	while (size-- > 0)
		*(str++) = 0;
}

int main(int argc, char **argv)
{
	pthread_mutex_t	*func_lock;
	pthread_mutex_t	*printing;

	func_lock = init_mutex();
	printing = init_mutex();
	if (!print_function(printing) || !lock_function(func_lock))
	{
		if (func_lock)
			free(func_lock);
		if (printing)
			free(printing);
		return (EXIT_FAILURE);
	}
	if (argc == 5 || argc == 6)
	{
		if (parse_args(argc, argv) == 0)
		{
			printf("Error.");
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
