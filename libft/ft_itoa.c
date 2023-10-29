/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:15:58 by madias-m          #+#    #+#             */
/*   Updated: 2023/10/28 15:30:28 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_digits(int n)
{
	int	count;

	count = 0;
	if (!n)
		return (1);
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		n = (n - (n % 10)) / 10;
		count++;
	}
	return (count);
}

char	*parse(int n, int len)
{
	char	*temp;
	int		is_neg;

	is_neg = 0;
	if (n < 0)
	{
		is_neg = 1;
		n *= -1;
	}
	temp = ft_calloc(is_neg + len + 1, 1);
	if (!temp)
		return (0);
	if (!is_neg)
		len--;
	while ((is_neg && len > 0) || (!is_neg && len >= 0))
	{
		temp[len--] = (n % 10) + 48;
		n = (n - (n % 10)) / 10;
	}
	if (is_neg)
		temp[0] = '-';
	return (temp);
}

char	*ft_itoa(int n)
{
	int		qtd;
	int		add;
	char	*res;

	add = 0;
	if (n == -2147483648)
		add = 1;
	qtd = count_digits(n + add);
	res = parse(n + add, qtd);
	if (res && add)
		res[qtd] += add;
	return (res);
}
