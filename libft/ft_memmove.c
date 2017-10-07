/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 13:37:32 by enunes            #+#    #+#             */
/*   Updated: 2017/06/18 19:00:40 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	int				i;
	unsigned char	*dst_str;
	unsigned char	*src_str;

	i = (int)n;
	dst_str = (unsigned char *)dst;
	src_str = (unsigned char *)src;
	if (src_str < dst_str)
		while (--i > -1)
			dst_str[i] = src_str[i];
	else
		while (i)
		{
			*dst_str++ = *src_str++;
			i--;
		}
	return (dst);
}
