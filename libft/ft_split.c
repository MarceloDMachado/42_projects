/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:38:37 by madias-m          #+#    #+#             */
/*   Updated: 2023/11/04 12:47:40 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_str(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
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

static char	**matrix_allocate(const char *s, char c)
{
	int	len;

	len = count_str(s, c);
	return (ft_calloc(len + 1, sizeof(char *)));
}

static void	str_allocate(const char *s, char c, char ***split)
{
	int	i;
	int	len;

	i = 0;
	while (*s && *split)
	{
		while (*s == c)
			s++;
		if (ft_strchr(s, c))
			len = ft_strchr(s, c) - s;
		else
			len = ft_strlen(s);
		if (len)
		{
			(*split)[i] = ft_substr(s, 0, len);
			if (!(*split)[i])
				split_free(split);
			i++;
		}
		s += len;
	}
}

char	**ft_split(const char *s, char c)
{
	char	**split;

	if (!s)
		return (0);
	split = matrix_allocate(s, c);
	if (!split)
		return (0);
	str_allocate(s, c, &split);
	return (split);
}
