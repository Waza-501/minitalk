/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fc_putchar.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/17 17:00:26 by ohearn        #+#    #+#                 */
/*   Updated: 2022/10/13 14:06:12 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	fc_putchar(char c)
{
	int	tally;

	tally = 0;
	tally += write (1, &c, 1);
	return (tally);
}
