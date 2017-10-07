/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 22:23:23 by enunes            #+#    #+#             */
/*   Updated: 2017/06/13 22:27:42 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		first;

	i = 0;
	first = 0;
	if (little[0] == '\0')
		return ((char*)big);
	while (big[i] != '\0' && i < len)
	{
		first = i;
		j = 0;
		while (big[i] == little[j] && i < len)
		{
			i++;
			j++;
			if (little[j] == '\0')
				return ((char*)&big[first]);
		}
		i = first;
		i++;
	}
	return (0);
}
