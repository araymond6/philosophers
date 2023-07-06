/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araymond <araymond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:14:49 by araymond          #+#    #+#             */
/*   Updated: 2023/06/27 15:47:12 by araymond         ###   ########.fr       */
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
	pthread_mutex_t	*death;

	func_lock = init_mutex();
	printing = init_mutex();
	death = init_mutex();
	if (!print_function(printing) || !lock_function(func_lock) || !death_function(death))
	{
		if (func_lock)
			free(func_lock);
		if (printing)
			free(printing);
		if (death)
			free(death);
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
