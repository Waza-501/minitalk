/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/08 17:49:35 by ohearn        #+#    #+#                 */
/*   Updated: 2023/01/26 18:54:06 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <unistd.h>
#include <stdlib.h>
static char	*builder(char c, char *string)
{
	
}

static char	translator(char c)
{
	static char		*string;

	string = NULL;
	if (c != "\0")
		builder(string, c);
	else
	{
		builder(string, c);
		ft_printf("%s\n", string);
		free (string);
		return (0);
	}
}

void	signal_handler(int signal, siginfo_t *info, void *other)
{
	static char		c;
	static int		i;
	static int		pid;

	(void)other;
	if (info->si_pid == 0)
	{
		write(1, ":(\n", 4);
		exit(0);
	}
	pid = info->si_pid;
	write (1, "ping\n", 6);
	ft_printf("%d\n", pid);
	if (signal == SIGUSR1)
		c |= 1 << i;
	i++;
	if (i == 8)
	{
		translator(c);
		if (c == '\0')
		{
			i = 0;
			c = 0;
			kill(pid, SIGUSR2);
			return;
		}
		i = 0;
		c = 0;
	}
	kill(pid, SIGUSR1);
}

int	main(void)
{
	pid_t					pid;
	struct	sigaction		sa;

	pid = getpid();
	ft_printf("%d\n", pid);
	sa.sa_handler = SIG_DFL;
	sa.sa_sigaction = &signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (true)
		pause();
}
