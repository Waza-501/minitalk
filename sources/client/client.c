/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/08 17:49:25 by ohearn        #+#    #+#                 */
/*   Updated: 2023/01/26 16:12:36 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
	write (1, "ping\n", 6);
	return (true);
}

t_data	*info_set(void)
{
	static t_data	info;

	return (&info);
}

void	send_string(int signal)
{
	int				i;
	int				temp;
	int				bit;
	static size_t	size;

	temp = 0;
	i = 0;
	bit = 1;
	size = 0;
	if (signal == SIGUSR2)
		exit (0);
	write(1, "ping2\n", 7);
	if (bit == 1)
		write (1, "hello there\n", 13);
}

int	main(int argc, char **argv)
{
	t_data	*info;

	info = info_set();
	if (input_check(argc, argv) == false)
	{
		write(2, "input error, please try again\n", 31);
		return (-1);
	}
	info->pid = ft_atoi(argv[1]);
	info->string = argv[2];
	signal(SIGUSR1, send_string);
	signal(SIGUSR2, send_string);
	kill(info->pid, SIGUSR1);
	return (0);
}
