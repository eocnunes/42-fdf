/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 16:53:11 by enunes            #+#    #+#             */
/*   Updated: 2017/09/28 18:30:33 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FDF_H
# ifndef FDF_H

# include "libft.h"
# include <mlx.h>
# include <math.h>

typedef	struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
}				t_mlx;

typedef struct	s_fdf
{
	char		*name;
	int			map_x;
	int			map_y;
	int			max;
	int			height;
	int			zoom;
	int			color;
	float		pos_x;
	float		pos_y;
	float		pos_z;
	t_mlx		env;
	t_pxl		**map;
}				t_fdf;

/* --------------------- fdf.c ---------------------- */
int		fdf(int ac, char **av);

#endif
