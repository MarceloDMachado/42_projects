/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:24:51 by madias-m          #+#    #+#             */
/*   Updated: 2023/11/21 19:40:43 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*c_dest;
	unsigned char	*c_src;

	c_src = (unsigned char *) src;
	c_dest = (unsigned char *) dest;
	if (c_dest == 0 && c_src == 0 && n > 0)
		return (dest);
	i = 0;
	while (i < n)
	{
		c_dest[i] = c_src[i];
		i++;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*c_dest;
	unsigned char	*c_src;

	if (dest == src)
		return (dest);
	c_dest = (unsigned char *) dest;
	c_src = (unsigned char *) src;
	if (dest > src)
	{
		i = 1;
		while (i <= n)
		{
			c_dest[n - i] = c_src[n - i];
			i++;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		len_s1;
	int		len_s2;
	char	*join;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	join = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!join)
		return (0);
	ft_memmove(join, s1, len_s1);
	ft_memmove(&join[len_s1], s2, len_s2);
	return (join);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *) &s[i]);
		i++;
	}
	if ((char) c == 0)
		return ((char *) &s[i]);
	return (0);
}
