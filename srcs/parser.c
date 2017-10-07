/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 22:51:33 by enunes            #+#    #+#             */
/*   Updated: 2017/10/06 22:20:15 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		fill_map(t_fdf *f, int x, int y)
{
	int		fd;
	char	*line;
	char	*tmp;
	char	**splitted;

	if ((fd = open(f->name, O_RDONLY)) < 0)
		error(ERR_OPEN);
	while (get_next_line(fd, &line))
	{
		tmp = ft_strtrim(line);
		splitted = ft_strsplit(tmp, ' ');
		if (line)
			ft_memdel((void *)&line);
		if (tmp)
			ft_memdel((void *)&tmp);
		x = 0;
		while (x < f->map_x && splitted[x])
		{
			f->map[y][x].h1 = ft_atoi(splitted[x]);
			if (f->map[y][x].h1 > f->map_max)
				f->map_max = f->map[y][x].h1;
			x++;
		}
		if (splitted)
			ft_sstrdel(splitted);
		y++;
	}
	close(fd);
}

int		checkch(char *str)
{
	int t;

	t = 0;
	if (str && str[t] == '-')
		t++;
	while (str && str[t])
	{
		if ((str[t] >= 48 && str[t] <= 58) || str[t] == 32 || str[t] == '-')
			t++;
		else
			return (0);
	}
	return (1);
}

void		alloc_map(t_fdf *f, int i)
{
	if ((f->map_x * f->map_y) > 1000000)
		 error(ERR_MAP);
	if (!(f->map = (t_pxl **)malloc(sizeof(t_pxl *) * f->map_y)))
		error(ERR_MALLOC);
	while (i < f->map_y)
		{
			if (!(f->map[i] = (t_pxl *)malloc(sizeof(t_pxl) * f->map_x)))
				error(ERR_MALLOC);
			i++;
		}
	fill_map(f, 0, 0);
}

void	parse_map(t_fdf *f)
{
	char	**splitted;
	char	*line;
	char	*temp;
	int		fd;

	if ((fd = open(f->name, O_RDONLY)) < 0)
		error(ERR_OPEN);
	if ((read(fd, NULL, 0)) < 0)
		error(ERR_OPEN);
	while (get_next_line(fd, &line))
	{
		temp = ft_strtrim(line);
		splitted = ft_strsplit(temp, ' ');
		if (line)
			ft_memdel((void *)&line);
		if (!ft_isnum(temp))
			error(ERR_MAP);
		if (temp)
			ft_memdel((void *)&temp);
		if (f->map_x == 0)
			f->map_x = ft_sstrlen(splitted);
		if (f->map_x != ft_sstrlen(splitted))
			error(ERR_MAP);
		if	(splitted)
			ft_sstrdel(splitted) : (0);
		f->map_y++;
	}
	close(fd);
	alloc_map(f, 0);
}
