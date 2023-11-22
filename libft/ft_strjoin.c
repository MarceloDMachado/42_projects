/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:48:37 by madias-m          #+#    #+#             */
/*   Updated: 2023/11/22 20:12:53 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*char	*ft_strjoin(const char *s1, const char *s2)
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
}*/
char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		len_s1;
	int		len_s2;
	char	*join;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	join = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!join)
		return (0);
	i = 0;
	while (*s1)
		join[i++] = *s1++;
	while (*s2)
		join[i++] = *s2++;
	join[i] = 0;
	return (join);
}
