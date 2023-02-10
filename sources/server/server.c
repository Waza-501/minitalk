/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/08 17:49:35 by ohearn        #+#    #+#                 */
/*   Updated: 2023/02/08 14:32:38 by ohearn        ########   odam.nl         */
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

static void	translator(char c)
{
	static char		*string = NULL;
	char			*temp;
	char			ch[2];

	temp = NULL;
	ch[0] = c;
	ch[1] = '\0';
	if (c != '\0')
	{
		if (temp == NULL && string == NULL)
			string = ft_strdup(ch);
		else
		{
			temp = ft_strdup(string);
			free (string);
			string = ft_strjoin(temp, ch);
			free (temp);
		}
	}
	else
		string = end_string(string);
}

void	signal_handler(int signal, siginfo_t *info, void *other)
{
	static char		c;
	static int		i = 0;
	static int		pid = 0;

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
