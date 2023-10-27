/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:04:13 by madias-m          #+#    #+#             */
/*   Updated: 2023/10/27 19:20:09 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_str(char *s, char c)
{
	int	count;

	if (!ft_strlen(s))
		return (0);
	count = 1;
	while (*s && c != 0)
	{
		if (*s == c && *(s + 1) != c)
			count++;
		s++;
	}
	return (count);
}

static char	**allocate(char ***split, int n)
{
	*split = (char **) ft_calloc(n + 1, 8);
	return (*split);
}

static char	*set_str(char **dest, char *src, char c)
{
	char	*end;
	int		len;

	end = ft_strchr(src, c);
	if (!end)
		len = ft_strlen(src);
	else
		len = end - src;
	*dest = ft_calloc(len + 1, 1);
	if(*dest)
		ft_memmove(*dest, src, len);
	while (end && *end == c && c != 0)
		end++;
	return (end);
}

char	**ft_split(const char *s, char c)
{
	char	**split;
	char	*trimmed_s;
	int		i;

	trimmed_s = ft_strtrim(s, &c);
	allocate(&split, ft_count_str(trimmed_s, c));
	if (!split)
		return (0);
	i = 0;
	while (trimmed_s && *trimmed_s)
	{
		trimmed_s = set_str(&split[i], trimmed_s, c);
		if (!split[i])
			return (0);
		i++;
	}
	return (split);
}
