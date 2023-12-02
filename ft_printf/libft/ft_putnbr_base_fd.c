/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:07:01 by madias-m          #+#    #+#             */
/*   Updated: 2023/12/02 16:34:30 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	putnbr(char *str, int is_negative, int size, int fd)
{
	int		i;
	char	*s;
	
	if (!size)
		return ;
	s = ft_calloc(size + is_negative, sizeof(char));
	if (!s)
		return ;
	i = 0;
	if (is_negative)
		write(fd, "-", 1);
	while (size >= is_negative)
		write(fd, (str + --size), 1);
}

static void	convert(long int nbr, int base, char *base_chars, int fd)
{
	char	digits[33];
	int		index;
	int		orig_nbr;

	orig_nbr = nbr;
	if (nbr < 0)
		nbr *= -1;
	index = 0;
	while (nbr >= 0)
	{
		digits[index] = base_chars[(nbr % base)];
		if (base != 10)
			nbr /= base;
		else
			nbr = (nbr - (nbr % 10)) / 10;
		index++;
		if (!nbr)
			nbr--;
	}
	putnbr(digits, orig_nbr < 0, index, fd);
}

static int	check_base(char *base, int len)
{
	int	i;

	if (len-- < 2)
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

void	ft_putnbr_base_fd(int nbr, char *base, int fd)
{	
	long int	long_nb;
	int			len;

	long_nb = (long int) nbr;
	len = 0;
	while (base[len])
		len++;
	if (check_base(base, len) && fd > 0)
		convert(long_nb, len, base, fd);
}
