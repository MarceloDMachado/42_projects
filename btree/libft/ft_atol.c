/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:06:32 by madias-m          #+#    #+#             */
/*   Updated: 2024/07/29 18:06:34 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

static int	ft_isvalid(int minus_count, int plus_count)
{
	if (minus_count == 1 && plus_count == 0)
		return (1);
	if (minus_count == 0 && plus_count == 1)
		return (1);
	if (!minus_count && !plus_count)
		return (1);
	return (0);
}

static long	ft_tonbr(char *str, int len, int neg)
{
	long	nbr;
	int		base;

	nbr = 0;
	base = 1;
	len--;
	while (len >= 0)
	{
		nbr += ((long) str[len--] - 48) * base;
		base *= 10;
	}
	if (neg)
		nbr *= -1;
	return (nbr);
}

long	ft_atol(const char *nptr)
{
	char	numbers[11];
	int		i;
	int		minus_count;
	int		plus_count;

	i = 0;
	minus_count = 0;
	plus_count = 0;
	while (ft_isspace(*nptr))
		nptr++;
	while (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			minus_count++;
		else
			plus_count++;
		nptr++;
	}
	if (!ft_isvalid(minus_count, plus_count))
		return (0);
	while (*nptr == 48)
		nptr++;
	while (ft_isdigit(*nptr) && i < 11)
		numbers[i++] = *nptr++;
	return (ft_tonbr(numbers, i, minus_count));
}
