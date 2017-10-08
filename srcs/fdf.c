/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 15:09:48 by enunes            #+#    #+#             */
/*   Updated: 2017/10/07 20:39:41 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void		set_env(t_fdf *f)
{
	if (f->map_x > f->map_y)
		f->win_x = (f->map_x * 10);
	else
		f->win_x = (f->map_y * 10);
	if (f->win_x < 800)
		f->win_x = 800;
	if (f->win_x > 1920)
		f->win_x = 1920;
	f->win_y = (f->win_x * 9) / 16;
	if (f->map_x > f->map_y)
		f->zoom = f->win_y / f->map_x;
	else
		f->zoom = f->win_y / f->map_y;
	if (!f->zoom)
		f->zoom = 2;
	f->height = 1;
	f->pos_x = 30;
	f->pos_y = 0;
	f->pos_z = 0;
	f->color = 0xFFFFFF;
	f->speed = 3;
}



int		main(int ac, char **av)
{
	t_fdf	fdf;

	if (ac != 2)
		error(ERR_ARG);
	fdf.name = ft_strdup(av[1]);
	fdf.map_y = 0;
	fdf.map_x = 0;
	fdf.map_max = 0;
	parse_map(&fdf);
	set_env(&fdf);
	fdf.env.mlx = mlx_init();
	fdf.env.win = mlx_new_window(fdf.env.mlx, fdf.win_x, fdf.win_y, "42-fdf");
	img_gen(&fdf);
	controls();
	mlx_hook(fdf.env.win, 2, (1L << 0), &keybind, &fdf);
	mlx_loop(fdf.env.mlx);
	return (0);
}
