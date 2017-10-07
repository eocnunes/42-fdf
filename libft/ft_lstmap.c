/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 20:44:31 by enunes            #+#    #+#             */
/*   Updated: 2017/06/28 16:30:29 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;
	t_list		*f_lst;

	if (!lst)
		return (0);
	f_lst = f(lst);
	new = f_lst;
	while (lst->next)
	{
		lst = lst->next;
		if (!(f_lst->next = f(lst)))
		{
			free(f_lst->next);
			return (0);
		}
		f_lst = f_lst->next;
	}
	return (new);
}
