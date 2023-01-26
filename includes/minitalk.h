/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minitalk.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 15:10:42 by ohearn        #+#    #+#                 */
/*   Updated: 2023/01/26 15:29:57 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libraries/libft/header/libft.h"
# include <signal.h>
# include <stdio.h>
# include <stdbool.h>

typedef struct s_data
{
	char		*string;
	int			pid;
}	t_data;

/*server*/
void		signal_handler(int signal, siginfo_t *info, void *other);


/*client*/


#endif