/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 21:48:50 by enunes            #+#    #+#             */
/*   Updated: 2017/06/24 15:10:29 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		ft_len(const char *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		num;
	char	**dst;

	i = 0;
	if (!s)
		return (0);
	num = ft_count_word((const char *)s, c);
	dst = (char **)malloc(sizeof(*dst) * (num + 1));
	if (dst == 0)
		return (0);
	while (num--)
	{
		while (*s == c && *s)
			s++;
		dst[i] = ft_strsub((const char *)s, 0, ft_len((const char *)s, c));
		if (dst[i] == 0)
			return (0);
		s = s + ft_len(s, c);
		i++;
	}
	dst[i] = 0;
	return (dst);
}
