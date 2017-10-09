/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 19:05:39 by enunes            #+#    #+#             */
/*   Updated: 2017/10/09 01:09:03 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	controlpanel(void)
{
	ft_putstr("\n\t        \e[1;104;97m FDF Controls \e[0m      \n");
	ft_putendl("\t\e[90m ------ ------ ------ ------\e[0m");
	ft_putendl("\t\e[90m|   1  |   2  |   3  |   4  |\e[0m");
	ft_putstr("\t\e[90m| \e[1;91mRED\e[90m  | \e[1;32mGRN\e[90m  | ");
	ft_putstr("\e[1;34mBLUE\e[90m |      |\e[0m\n");
	ft_putendl("\t\e[90m ------ ------ ------ ------\e[0m");
	ft_putendl("\t\e[90m|   Q  |   W  |   E  |   R  |\e[0m");
	ft_putstr("\t\e[90m| \e[1;36mRotL\e[90m |  \e[1;31mY+\e[90m  | ");
	ft_putstr("\e[1;36mRotR\e[90m | \e[93mzIN\e[90m  |\n\e[0m");
	ft_putendl("\t\e[90m ------ ------ ------ ------\e[0m");
	ft_putendl("\t\e[90m|   A  |   S  |   D  |   F  |\e[0m");
	ft_putstr("\t\e[90m|  \e[1;31mX-\e[90m  |  \e[1;31mY-\e[90m  |  ");
	ft_putstr("\e[1;31mX+\e[90m  | \e[93mzOUT\e[90m |\n\e[0m");
	ft_putendl("\t\e[90m ------ ------ ------ ------\e[0m");
	ft_putendl("\t\e[90m|   Z  |   X  |   C  |   V  |\e[0m");
	ft_putstr("\t\e[90m| \e[1;95mMUL-\e[90m | \e[1;95mMUL+\e[90m | ");
	ft_putstr("\e[1;92mSpd-\e[90m | \e[1;92mSpd+\e[90m |\n\e[0m");
	ft_putendl("\t\e[90m ---------------------------|\e[0m");
	ft_putendl("\t\e[90m|           SPACE           |\e[0m");
	ft_putstr("\t\e[90m|           \e[1;97mRESET\e[90m           |\e[0m\n");
	ft_putendl("\t\e[90m ---------------------------\e[0m");
	ft_putstr("\n\t  \e[1;104;97m Press [ESC] to quit FDF \e[0m\n\n");
}

void	key_controls(int key, t_fdf *f)
{
	(key == ESC) ? exit(0) : (0);
	(key == RESET) ? set_env(f) : (0);
	(key == HPOS) ? f->height++ : (0);
	(key == HNEG && f->height) ? f->height-- : (0);
	(key == SPOS && f->speed < 10) ? f->speed++ : (0);
	(key == SNEG && f->speed) ? f->speed-- : (0);
	(key == XPOS) ? f->pos_x += f->speed : (0);
	(key == XNEG) ? f->pos_x -= f->speed : (0);
	(key == YPOS) ? f->pos_y += f->speed : (0);
	(key == YNEG) ? f->pos_y -= f->speed : (0);
	(key == RNEG) ? f->pos_z += f->speed : (0);
	(key == RPOS) ? f->pos_z -= f->speed : (0);
	(key == ZPOS && ((f->map_x * f->zoom) < (f->win_x * 0.8)) &&
		((f->map_y * f->zoom) < (f->win_y * 0.8))) ? f->zoom++ : (0);
	(key == ZNEG && ((f->map_x * f->zoom) > (f->win_x * 0.1)) &&
		((f->map_y * f->zoom) > (f->win_y * 0.1))) ? f->zoom-- : (0);
	(key == RED) ? f->color = 0xed3b3b : (0);
	(key == GREEN) ? f->color = 0x76ed3b : (0);
	(key == BLUE) ? f->color = 0x4261ff : (0);
	(key == DEL) ? f->color = 0x000000 : (0);
}

int		keybind(int key, t_fdf *f)
{
	f->pos_x >= 360 ? f->pos_x -= 360 : (0);
	f->pos_y >= 360 ? f->pos_y -= 360 : (0);
	f->pos_z >= 360 ? f->pos_z -= 360 : (0);
	f->pos_x <= -360 ? f->pos_x += 360 : (0);
	f->pos_y <= -360 ? f->pos_y += 360 : (0);
	f->pos_z <= -360 ? f->pos_z += 360 : (0);
	key_controls(key, f);
	((f->height * f->map_max) > (f->win_y / 2)) ? f->height-- : (0);
	(!f->height) ? f->height++ : (0);
	img_gen(f);
	return (0);
}
