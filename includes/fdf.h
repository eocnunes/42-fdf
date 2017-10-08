/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 16:53:11 by enunes            #+#    #+#             */
/*   Updated: 2017/10/07 20:59:05 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <mlx.h>
# include <math.h>
# include "fcntl.h"

# define	ERR_ARG			"Error. Usage: ./fdf map.fdf"
# define	ERR_OPEN		"Error: failed to open file."
# define	ERR_MALLOC		"Error: malloc failed."
# define	ERR_MAP			"Error: invalid map."

# define XPOS		91
# define XNEG		84
# define YPOS		88
# define YNEG		86
# define RPOS		85
# define RNEG		83
# define SPOS		69
# define SNEG		78
# define HPOS		92
# define HNEG		89
# define RESET		87
# define ESC		53
# define ARU		126
# define ARD		125
# define ARL		123
# define ARR		124

typedef struct	s_line
{
	float		a;
	float		b;
	float		c;
}				t_line;

typedef struct	s_pxl
{
	int			x;
	int			y;
	int			h;
	int			x1;
	int			y1;
	int			h1;
}				t_pxl;

typedef	struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
}				t_mlx;

typedef struct	s_fdf
{
	char		*name;
	int			win_x;
	int			win_y;
	int			map_x;
	int			map_y;
	int			map_max;
	int			height;
	int			zoom;
	int			speed;
	int			color;
	float		pos_x;
	float		pos_y;
	float		pos_z;
	t_mlx		env;
	t_pxl		**map;
}				t_fdf;

/* --------------------- fdf.c ---------------------- */
int		main(int ac, char **av);
void	set_env(t_fdf *f);

/* -------------------- parser.c -------------------- */
void	parse_map(t_fdf *f);
void	alloc_map(t_fdf *f, int i);
int		checkch(char *str);
void	fill_map(t_fdf *f, int x, int y);

/* --------------------- draw.c --------------------- */
void	img_gen(t_fdf *f);
void	join_pxl(t_fdf *f, t_pxl px_a, t_pxl px_b);
void	diag_x(t_fdf *f, t_pxl steps, t_pxl point, float m);
void	diag_y(t_fdf *f, t_pxl steps, t_pxl point, float m);
void	straight(t_fdf *f, t_pxl a, t_pxl b, int sense);

/* --------------------- draw.c ---------------------- */
int		mlx_img(t_fdf *f, t_pxl a);
void	recalc(t_fdf *f, int x, int y);
void	shifting(t_fdf *f, t_pxl *px);

/* --------------------- keys.c ---------------------- */
int		keybind(int key, t_fdf *f);
void	controls(void);

/* --------------------- tools.c --------------------- */
void	error(char *message);
void	sstrdel(char **s);
int		sstrlen(char **s);

/* --------------------- tools.c --------------------- */
void	screeninfo(t_fdf *f);
void	data_msize(t_fdf *f);
void	data_xyz(t_fdf *f, int off_x);
void	data_var(t_fdf *f, int off_x, int off_y);

#endif
