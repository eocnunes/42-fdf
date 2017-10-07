/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 17:11:31 by enunes            #+#    #+#             */
/*   Updated: 2017/06/11 15:34:13 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	int				n;
	int				i;
	unsigned char	*dest;

	n = len;
	i = 0;
	dest = b;
	while (i < n)
	{
		dest[i] = c;
		i++;
	}
	return (b);
}
