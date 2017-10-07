/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 17:50:16 by enunes            #+#    #+#             */
/*   Updated: 2017/06/11 15:36:07 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	int				i;
	int				num;
	unsigned char	*str;

	i = 0;
	num = n;
	str = s;
	if (!n)
		return ;
	while (i < num)
	{
		str[i] = '\0';
		i++;
	}
	return ;
}
