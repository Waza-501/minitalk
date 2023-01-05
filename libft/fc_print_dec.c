/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fc_print_dec.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: owen <owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/17 11:59:42 by owen          #+#    #+#                 */
/*   Updated: 2022/10/13 14:20:15 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	fc_print_dec(unsigned int dec)
{
	int					size;
	unsigned int		ret;

	size = 0;
	ret = (dec % 10);
	if (dec > 9)
		size += fc_print_dec(dec / 10);
	size += fc_putchar((ret + '0'));
	return (size);
}
