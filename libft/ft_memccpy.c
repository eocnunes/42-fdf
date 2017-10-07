/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 16:01:23 by enunes            #+#    #+#             */
/*   Updated: 2017/06/14 20:20:26 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	ch;
	unsigned char	*dststr;
	unsigned char	*srcstr;

	i = 0;
	ch = (unsigned char)c;
	dststr = (unsigned char *)dst;
	srcstr = (unsigned char *)src;
	while (i < n)
	{
		dststr[i] = srcstr[i];
		if (srcstr[i] == ch)
			return (dststr + i + 1);
		i++;
	}
	return (0);
}
