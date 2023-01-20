/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/08 17:49:25 by ohearn        #+#    #+#                 */
/*   Updated: 2023/01/20 16:56:50 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>
#include <stdio.h>
#include <stdbool.h>

static bool	input_check(int argc, char **argv)
{
	int	i;

	i = -1;
	if (argc != 3)
		return (false);
	while (argv[1][++i])
	{
		if (!ft_strchr("0123456789", argv[1][i]))
			return (false);
	}
	return (true);
}

void	send_string(int signal)
{
	int	i;
	int	temp;
	int	bit;

	bit = 1;
	if (signal == SIGUSR1)
	{
		while (bit == 1)
		{
			write (1, "hello there\n", 13);
			usleep (500);
		}
	}
	
}

int	main(int argc, char **argv)
{
	t_data	*info;
	if (input_check(argc, argv) == false)
	{
		write(2, "input error, please try again", 30);
		return (-1);
	}
	info->pid = ft_atoi(argv[1]);
	info->string = argv[2];
	signal(SIGUSR1, send_string);
	return (0);
}
