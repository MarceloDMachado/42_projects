/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>              +#+  +:+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 09:59:09 by marcelodmacha     #+#    #+#             */
/*   Updated: 2023/10/30 12:26:18 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*res;
	int		len;
	int		i;

	len = ft_strlen(s);
	res = ft_calloc(len + 1, 1);
	if (!res)
		return (0);
	i = 0;
	while (i < len)
	{
		res[i] = f(i, s[i]);
		i++;
	}
	return (res);
}
