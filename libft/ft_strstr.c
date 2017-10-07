/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 22:23:23 by enunes            #+#    #+#             */
/*   Updated: 2017/06/13 22:20:23 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		j;
	int		first;

	i = 0;
	first = 0;
	if (little[0] == '\0')
		return ((char*)big);
	while (big[i] != '\0')
	{
		first = i;
		j = 0;
		while (big[i] == little[j])
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
