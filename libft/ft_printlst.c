/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 21:00:06 by enunes            #+#    #+#             */
/*   Updated: 2017/06/23 21:20:11 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_printlst(t_list **head)
{
	t_list *node;

	node = *head;
	while (node)
	{
		ft_putstr((char *)node->content);
		ft_putchar('\n');
		node = node->next;
	}
}
