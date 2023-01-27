/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/08 17:49:35 by ohearn        #+#    #+#                 */
/*   Updated: 2023/01/27 15:30:18 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <unistd.h>
#include <stdlib.h>

static char	*end_string(char *string)
{
	ft_printf("%s\n", string);
	free (string);
	string = NULL;
	return (string);
}

static void	malloc_error(void)
{
	write (2, "Malloc error\n", 14);
	exit ;
}

static void	translator(char c)
{
	static char		*string;
	static char		*temp;
	char			ch[2];

	ch[0] = c;
	ch[1] = '\0';
	if (c != '\0')
	{
		if (temp == NULL)
		{
			temp = ft_strdup(ch);
			if (temp == NULL)
				malloc_error();
		}
		else
		{
			string = ft_strjoin(temp, c);
			free (temp);
		}
	}
	if (string == NULL)
		malloc_error();
	else
		string = end_string(string);
}

void	signal_handler(int signal, siginfo_t *info, void *other)
{
	static char		c;
	static int		i;
	static int		pid;

	(void)other;
	if (info->si_pid != 0)
		pid = info->si_pid;
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
			return ;
		}
		i = 0;
		c = 0;
	}
	kill(pid, SIGUSR1);
}

int	main(void)
{
	pid_t					pid;
	struct sigaction		sa;

	pid = getpid();
	ft_printf("%d\n", pid);
	sa.sa_handler = SIG_DFL;
	sa.sa_sigaction = &signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (true)
		pause();
}
