/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fc_print_cha.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/17 15:35:55 by ohearn        #+#    #+#                 */
/*   Updated: 2022/10/13 14:20:23 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	fc_print_cha(char string)
{
	int	size;

	size = 0;
	size = fc_putchar(string);
	return (size);
}
