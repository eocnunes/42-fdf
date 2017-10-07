/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 23:07:08 by enunes            #+#    #+#             */
/*   Updated: 2017/06/23 23:14:54 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_lstsize(t_list *lst_begin)
{
	int		i;
	t_list	*list;

	i = 0;
	list = lst_begin;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}
