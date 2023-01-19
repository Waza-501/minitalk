/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/08 17:49:25 by ohearn        #+#    #+#                 */
/*   Updated: 2023/01/19 13:38:21 by ohearn        ########   odam.nl         */
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
	return (1);
}
