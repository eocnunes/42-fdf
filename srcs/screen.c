/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 02:03:37 by enunes            #+#    #+#             */
/*   Updated: 2017/10/07 02:08:49 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		data_var(t_fdf *f, int off_x, int off_y)
{
	char	*temp;
	char	*vtemp;

	vtemp = ft_itoa(f->height);
	temp = ft_strjoin("Multiplier:", vtemp);
	mlx_string_put(f->env.mlx, f->env.win, 5, f->win_y - 25, 0x3399FF, temp);
	temp ? ft_memdel((void *)&temp) : (0);
	vtemp ? ft_memdel((void *)&vtemp) : (0);
	vtemp = ft_itoa(f->speed);
	temp = ft_strjoin("Speed:", vtemp);
	off_x = f->win_x - (ft_strlen(temp) * 10) - 5;
	off_y = f->win_y - 25;
	mlx_string_put(f->env.mlx, f->env.win, off_x, off_y, 0x3399FF, temp);
	temp ? ft_memdel((void *)&temp) : (0);
	vtemp ? ft_memdel((void *)&vtemp) : (0);
}

void		data_xyz(t_fdf *f, int off_x)
{
	char	*temp;
	char	*vtemp;
	char	*rt;

	temp = NULL;
	vtemp = ft_itoa(f->pos_x);
	temp = ft_strjoin("X:", vtemp);
	rt = ft_strjoin(temp, " Y:");
	temp ? ft_memdel((void *)&temp) : (0);
	vtemp ? ft_memdel((void *)&vtemp) : (0);
	vtemp = ft_itoa(f->pos_y);
	temp = ft_strjoin(rt, vtemp);
	rt ? ft_memdel((void *)&rt) : (0);
	rt = ft_strjoin(temp, " Z:");
	temp ? ft_memdel((void *)&temp) : (0);
	vtemp ? ft_memdel((void *)&vtemp) : (0);
	vtemp = ft_itoa(f->pos_z);
	temp = ft_strjoin(rt, vtemp);
	off_x = (f->win_x - (ft_strlen(temp) * 10)) / 2;
	mlx_string_put(f->env.mlx, f->env.win, off_x, f->win_y - 25, 0xCC0033, temp);
	temp ? ft_memdel((void *)&temp) : (0);
	vtemp ? ft_memdel((void *)&vtemp) : (0);
	rt ? ft_memdel((void *)&rt) : (0);
}

void		data_msize(t_fdf *f)
{
	char	*temp;
	char	*vtemp;
	char	*rt;
	int		offset;

	vtemp = ft_itoa(f->map_x);
	rt = ft_strjoin("X:", vtemp);
	vtemp ? ft_memdel((void *)&vtemp) : (0);
	temp = ft_strjoin(rt, " Y:");
	rt ? ft_memdel((void *)&rt) : (0);
	vtemp = ft_itoa(f->map_y);
	rt = ft_strjoin(temp, vtemp);
	offset = (f->win_x - (ft_strlen(rt) * 10)) / 2;
	mlx_string_put(f->env.mlx, f->env.win, offset, 20, 0x00ceFF, rt);
	rt ? ft_memdel((void *)&rt) : (0);
	temp ? ft_memdel((void *)&temp) : (0);
	vtemp ? ft_memdel((void *)&vtemp) : (0);
}

void			screeninfo(t_fdf *f)
{
	char	*temp;
	int		offset;

	temp = NULL;
	temp = ft_strjoin("MAP:", f->name);
	offset = (f->win_x - (ft_strlen(temp) * 10)) / 2;
	mlx_string_put(f->env.mlx, f->env.win, offset, 0, 0x00FF00, temp);
	if (temp)
		ft_memdel((void *)&temp);
	data_msize(f);
	data_xyz(f, 0);
	data_var(f, 0, 0);
}

