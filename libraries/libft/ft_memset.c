/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/23 09:09:13 by ohearn        #+#    #+#                 */
/*   Updated: 2023/01/25 11:35:34 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			tally;
	unsigned char	*copy_b;

	tally = 0;
	copy_b = (unsigned char *)b;
	while (tally < len)
	{
		copy_b[tally] = c;
		tally++;
	}
	return (b);
}
