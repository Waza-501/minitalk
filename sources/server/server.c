/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/08 17:49:35 by ohearn        #+#    #+#                 */
/*   Updated: 2023/01/12 18:36:09 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

//#include "minitalk.h"
#include <signal.h>
#include <stdio.h>



int	main(void)
{
	pid_t					id;
	struct	sigaction		sa;

	id = getpid();
	printf("%d\n", id);
}
