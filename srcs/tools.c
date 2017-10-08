/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 01:40:11 by enunes            #+#    #+#             */
/*   Updated: 2017/10/07 20:44:24 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error(char *message)
{
	ft_putendl_fd("\e[1;31mKO\n", 2);
	ft_putendl_fd(message, 2);
	ft_putstr_fd("\e[0m", 2);
	exit(EXIT_FAILURE);
}

void	sstrdel(char **s)
{
	int i;

	i = 0;
	while (s[i])
	{
		ft_memdel((void *)&s[i++]);
	}
	ft_memdel((void *)&s);
}

int		sstrlen(char **s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
