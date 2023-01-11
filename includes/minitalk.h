/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minitalk.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 15:10:42 by ohearn        #+#    #+#                 */
/*   Updated: 2023/01/11 19:03:53 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libraries/libft/libft.h"
# include <signal.h>
# include <stdio.h>
# include <stdbool.h>

typedef struct s_data
{
	char *		string;
	int			pid;
}	t_data;

#endif