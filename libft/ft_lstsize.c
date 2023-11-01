/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:00:39 by madias-m          #+#    #+#             */
/*   Updated: 2023/11/01 12:43:17 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*next;

	if (!lst)
		return (0);
	size = 1;
	next = lst -> next;
	while (next)
	{
		size++;
		next = next -> next;
	}
	return (size);
}
