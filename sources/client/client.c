/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/08 17:49:25 by ohearn        #+#    #+#                 */
/*   Updated: 2023/02/05 19:20:19 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_sent;

int	send_signal(int pid, int bit, char c)
{
	if (c & (1 << bit))
		return (kill(pid, SIGUSR1));
	else
		return (kill(pid, SIGUSR2));
}

void	send_string(int pid, char *string)
{
	static int		i;
	int				temp;
	static int		c_pid;
	static int		bit = 0;
	static char		*c_string;

	temp = bit;
	if (!c_pid)
		c_pid = pid;
	if (!c_string)
		c_string = string;
	bit++;
	if (bit == 8)
	{
		bit = 0;
		i++;
	}
	g_sent += 1;
	send_signal(c_pid, temp, c_string[i]);
}

void	recieve_ping(int signal, siginfo_t *info, void *other)
{
	static int	recieved;

	(void)info;
	(void)other;
	recieved += 1;
	if (signal == SIGUSR2)
	{
		ft_printf ("Total signals sent %d\n", g_sent);
		ft_printf ("Total signals recieved %d\n", recieved);
		exit (0);
	}
	send_string(0, NULL);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	if (argc != 3 || ft_atoi(argv[1]) < 0)
	{
		error_message("Input error, please try again");
		return (-1);
	}
	sa.sa_handler = SIG_DFL;
	sa.sa_sigaction = &recieve_ping;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) || sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		error_message("Error");
	}
	send_string(ft_atoi(argv[1]), argv[2]);
	while (true)
		pause();
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
