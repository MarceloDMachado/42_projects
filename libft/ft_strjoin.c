/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:22:39 by madias-m          #+#    #+#             */
/*   Updated: 2023/10/27 19:05:31 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		len_s1;
	int		len_s2;
	char	*join;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	join = (char *) ft_calloc(len_s1 + len_s2 + 1, 1);
	if (!join)
		return (0);
	ft_memmove(join, s1, len_s1);
	ft_memmove(&join[len_s1], s2, len_s2);
	return (join);
}
