/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:04:13 by madias-m          #+#    #+#             */
/*   Updated: 2023/10/28 14:55:38 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_str(char *s, char c)
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
	if (*dest)
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
	i = count_str(trimmed_s, c) + 1;
	split = ft_calloc(i, sizeof(char *));
	if (i == 2)
	{
		split[0] = ft_strdup(trimmed_s);
		return (split);
	}
	if (!split)
		return (0);
	i = 0;
	while (trimmed_s && *trimmed_s && split)
	{
		trimmed_s = set_str(&split[i], trimmed_s, c);
		if (!split[i])
			split_free(&split);
		i++;
	}
	return (split);
}

/*int main(void)
{
	char *s = "";
 	char **result = ft_split(s, 122);

	free(result[0]);
	free(result[1]);
	free(result);
	return (0);
}*/
