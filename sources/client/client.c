/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/08 17:49:25 by ohearn        #+#    #+#                 */
/*   Updated: 2023/02/02 15:09:32 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*static bool	input_check(int argc, char **argv)
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

t_data	*info_set(void)
{
	static t_data	info;

	return (&info);
}*/
void	recieve_ping(int signal, siginfo_t *info, void *other)
{

}

void	send_string()
{
	int				i;
	int				temp;
	static int		bit;
	static size_t	size;
	int				pid;

	pid = getpid();
	bit = 0;
	size = 0;
	i = size;
	temp = bit;
	if (true)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	return ;
	
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	
	if (argc != 3 || ft_atoi(argv[1]) == 0)
		error_message("Input error, please try again");
	sa.sa_handler = SIG_DFL;
	sa.sa_sigaction = &recieve_ping;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		error_message("Error");
	}


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
