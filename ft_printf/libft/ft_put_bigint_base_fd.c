/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_bigint_base_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:41:37 by madias-m          #+#    #+#             */
/*   Updated: 2023/12/04 18:53:04 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	putnbr_fd(char *digits, int size, int fd)
{
	while (size >= 0)
		write(fd, &digits[size--], 1);
}

static void	convert(size_t nbr, int base, char *base_chars, int fd)
{
	char	digits[64];
	int		index;
	
	index = 0;
	while (nbr > 0)
	{
		digits[index] = base_chars[(nbr % base)];
		if (base != 10)
			nbr /= base;
		else
			nbr = (nbr - (nbr % 10)) / 10;
		index++;
	}
	putnbr_fd(digits, index, fd);
}

static int	check_base(char *base, int len)
{
	int i;

	if (len -- < 2)
		return (0);
	while (len >= 0)
	{
		if (base[len] == 43 || base[len] == 45)
			return (0);
		i = 0;
		while (base[i])
		{
			if (base[i] == base[len] && i != len)
				return (0);
			i++;
		}
		len--;
	}
	return (1);
}

void	ft_put_bigint_base_fd(size_t nbr, char *base, int fd)
{
	int len;

	len = 0;
	while (base[len])
		len++;
	if (check_base(base, len) && fd > 0)
		convert(nbr, len, base, fd);
}
