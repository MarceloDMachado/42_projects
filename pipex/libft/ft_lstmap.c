/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:20:57 by madias-m          #+#    #+#             */
/*   Updated: 2023/11/04 17:51:31 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first_node;
	t_list	*next;
	void	*ptr;

	first_node = 0;
	while (lst)
	{
		ptr = f(lst -> content);
		next = ft_lstnew(ptr);
		if (!next)
		{
			ft_lstclear(&first_node, del);
			del(ptr);
			return (0);
		}
		ft_lstadd_back(&first_node, next);
		lst = lst -> next;
	}
	return (first_node);
}
