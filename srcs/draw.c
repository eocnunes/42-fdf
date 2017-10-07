/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 07:41:29 by enunes            #+#    #+#             */
/*   Updated: 2017/10/07 02:02:10 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	straight(t_fdf *f, t_pxl a, t_pxl b, int sense)
{
	if (a.y == b.y)
	{
		if (a.x > b.x)
			sense = -1; 
		else
			sense = 1;
		while (a.x != b.x)
		{
			mlx_img(f, a);
			a.x += sense;
		}
		mlx_img(f, a);
	}
	else
	{
		if (a.y > b.y)
			sense = -1;
		else
			sense = 1;
		while (a.y != b.y)
		{
			mlx_img(f, a);
			a.y += sense;
		}
		mlx_img(f, a);
	}
}

void	diag_y(t_fdf *f, t_pxl steps, t_pxl point, float m)
{
	float	start;
	int		i;
	int		n;
	t_pxl	a;

	i = steps.x;
	n = steps.y;
	start = point.x;
	a.x = start;
	a.y = i;
	mlx_img(f, a);
	while (i <= n)
	{
		a.x = start;
		a.y = i;
		mlx_img(f, a);
		start += m;
		i++;
	}
}

void	diag_x(t_fdf *f, t_pxl steps, t_pxl point, float m)
{
	float	start;
	int		i;
	int		n;
	t_pxl	a;

	i = steps.x;
	n = steps.y;
	start = point.y;
	a.x = i;
	a.y = start;
	mlx_img(f, a);
	while (i <= n)
	{
		a.x = i;
		a.y = start;
		mlx_img(f, a);
		start += m;
		i++;
	}
}

void		join_pxl(t_fdf *f, t_pxl px_a, t_pxl px_b)
{
	float	m;
	t_pxl	shift;

	if (px_a.x == px_b.x || px_a.y == px_b.y)
		straight(f, px_a, px_b, 0);
	else if (abs(px_a.x - px_b.x) > abs(px_a.y - px_b.y))
	{
		m = ((float)(px_b.y - px_a.y)) / (px_b.x - px_a.x);
		shift.x = (int)fmin(px_a.x, px_b.x);
		shift.y = (int)fmax(px_a.x, px_b.x);
		diag_x(f, shift, (px_a.x < px_b.x) ? px_a : px_b, m);
	}
	else
	{
		m = ((float)(px_b.x - px_a.x)) / (px_b.y - px_a.y);
		shift.x = (int)fmin(px_a.y, px_b.y);
		shift.y = (int)fmax(px_a.y, px_b.y);
		diag_y(f, shift, (px_a.y < px_b.y) ? px_a : px_b, m);
	}
}

void		img_gen(t_fdf *f)
{
	int y;
	int x;

	recalc(f, 0, 0);
	f->mlx.img = mlx_new_image(f->env.mlx, f->win_x, f->win_y);
	y = 0;
	while (y < f->map_y)
	{
		x = 0;
		while (x < f->map_x)
		{
			if (y != f->map_y - 1)
				join_pxl(f, f->map[y][x], f->map[y + 1][x]);
			if (x != f->map_x - 1)
				join_pxl(f, f->map[y][x], f->map[y][x + 1]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->env.mlx, f->env.win, f->env.img, 0, 0);
	mlx_destroy_image(f->env.mlx, f->env.img);
	screeninfo(f);
}


