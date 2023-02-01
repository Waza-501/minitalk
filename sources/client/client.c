/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/08 17:49:25 by ohearn        #+#    #+#                 */
/*   Updated: 2023/02/01 17:59:21 by ohearn        ########   odam.nl         */
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
	return (true);
}

// t_data	*info_set(void)
// {
// 	static t_data	info;

// 	return (&info);
// }

void	send_string(int signal, siginfo_t *info, void *other)
{
	int				i;
	int				temp;
	static int		bit;
	static size_t	size;

	bit = 1;
	size = 0;
	i = size;
	temp = bit;
	if (signal == SIGUSR2)
		exit (0);
	exit (1);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	
	if (argc != 3 || ft_itao(argv[1]) == 0)
		error_message();
	sa.sa_handler = SIG_DFL;
	sa.sa_sigaction = &send_string;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
}

// int	main(int argc, char **argv)
// {
// 	t_data	*info;

// 	info = info_set();
// 	if (input_check(argc, argv) == false)
// 	{
// 		error_message();
// 		return (-1);
// 	}
// 	info->pid = ft_atoi(argv[1]);
// 	info->string = argv[2];
// 	signal(SIGUSR1, send_string);
// 	signal(SIGUSR2, send_string);
// 	return (0);
// }
