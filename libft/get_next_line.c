/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 00:59:20 by enunes            #+#    #+#             */
/*   Updated: 2017/10/07 20:56:26 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**set_line(char **rest, char **line)
{
	int		i;

	i = 0;
	while ((*rest)[i] != '\n' && (*rest)[i])
		i++;
	*line = ft_strncpy(ft_strnew(i), *rest, i);
	return (rest);
}

void			fill(char **over)
{
	char	*endl;
	char	*temp;

	if ((endl = ft_strchr(*over, '\n')))
	{
		temp = ft_strdup(endl + 1);
		ft_strclr(*over);
		ft_strdel(over);
		*over = temp;
	}
	else
	{
		ft_strdel(over);
		*over = NULL;
	}
}

int				get_next_line(const int fd, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];
	char			*temp;
	static char		*rest[MAX_FD];

	if (read(fd, buf, 0) < 0 || !line || fd < 0 || fd > MAX_FD || BUFF_SIZE < 1)
		return (-1);
	if (!(rest[fd]))
		rest[fd] = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		temp = ft_strjoin(rest[fd], buf);
		ft_strdel(rest + fd);
		rest[fd] = temp;
		if ((temp = ft_strchr(rest[fd], '\n')))
			break ;
	}
	if ((ret == 0 && rest[fd][0] == 0) || ret < 0)
	{
		ft_strdel(rest + fd);
		return (ret);
	}
	fill(set_line(rest + fd, line));
	return (1);
}
