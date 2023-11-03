/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:47:20 by madias-m          #+#    #+#             */
/*   Updated: 2023/11/03 11:47:22 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_str(const char *s, char c)
{
	int	count;

	count = 1;
	while (*s && c != 0)
	{
		if (*s == c && *(s + 1) != c)
			count++;
		s++;
	}
	return (count);
}

static void	split_free(char ***split)
{
	while (*split)
	{
		if (**split)
		{
			free(**split);
			**split = 0;
		}
		(*split)++;
	}
	free(*split);
	*split = 0;
}

static char	**split_allocate(const char *s, char c)
{
	int	len;

	len = count_str(s, c);
	if (!len)
		len++;
	return (ft_calloc(len + 1, sizeof(char *)));
}

char	**ft_split(const char *s, char c)
{
	char	**split;
	int		i;
	int		len;

	if (!s || !(split = split_allocate(s, c)))
		return (0);
	i = 0;
	while (*s && split)
	{
		while (*s == c)
			s++;
		if (ft_strchr(s, c))
			len = ft_strchr(s, c) - s;
		else
			len = ft_strlen(s);
		if (len)
			if (!(split[i++] = ft_substr(s, 0, len)))
				split_free(&split);
		s += len;
	}
	return (split);
}
