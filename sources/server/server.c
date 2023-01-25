/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/08 17:49:35 by ohearn        #+#    #+#                 */
/*   Updated: 2023/01/25 15:56:27 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(const char *s)
{
	int	size;

	while (*s)
	{
		size++;
		s++;
	}
	return (size);
}

static char	translator(char c)
{
	char	*string;
	char	*new_string;
	int		tally;	

	new_string = (char *)malloc(ft_strlen (string) + 2);
	tally = 0;
	if (!new_string)
		return (0);
	while (*string)
	{
		new_string[tally] = *string;
		tally++;
		string++;
	}
	if (c)
	{
		new_string[tally] = c;
		tally++;
	}
	new_string[tally] = 0;
	printf("%s\n", string);
	return (*string);
}

static void	signal_handler(int signal, siginfo_t *info, void *other)
{
	int		i;
	char	c;
	int 	pid;

	(void)other;
	pid = info->si_pid;
	if (signal == SIGUSR1)
		c |= 1 << i;
	i++;
	if (i == 8)
		translator(c);
	if (c == '\0')
		i = 0;
		c = 0;
		kill(pid, SIGUSR1);
		return ;
	kill(pid, SIGUSR2);
}

int	main(void)
{
	pid_t					pid;
	struct	sigaction		sa;

	pid = getpid();
	printf("%d\n", pid);
	sa.sa_handler = SIG_DFL;
	sa.sa_sigaction = &signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	return (0);
}
