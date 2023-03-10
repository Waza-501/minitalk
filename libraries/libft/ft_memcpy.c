/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/09 17:56:45 by ohearn        #+#    #+#                 */
/*   Updated: 2023/01/25 11:35:25 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			tally;
	unsigned char	*copy_src;
	unsigned char	*copy_dst;

	tally = 0;
	copy_src = (unsigned char *)src;
	copy_dst = (unsigned char *)dst;
	if (!dst || !src)
		return (NULL);
	while (tally < n)
	{
		copy_dst[tally] = copy_src[tally];
		++tally;
	}
	return (dst);
}
