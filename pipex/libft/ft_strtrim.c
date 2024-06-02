/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:51:26 by madias-m          #+#    #+#             */
/*   Updated: 2023/11/03 11:51:29 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_c(const char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == c)
			count++;
		str++;
	}
	return (count);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*str;
	int		s1_len;
	int		i;

	i = 0;
	s1_len = ft_strlen(s1);
	while (ft_count_c(set, *s1))
		s1++;
	s1_len = ft_strlen(s1);
	while (ft_count_c(set, s1[s1_len - i]) || s1[s1_len - i] == 0)
		i++;
	s1_len -= --i;
	if (s1_len < 1)
		return (ft_calloc(1, 1));
	str = ft_calloc(s1_len + 1, 1);
	if (!str)
		return (0);
	ft_memmove(str, s1, s1_len);
	str[s1_len] = 0;
	return (str);
}
