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

int	count_digits(int n)
{
	int	count;

	count = 0;
	if (!n)
		return (1);
	while (n > 0)
	{
		n = (n - (n % 10)) / 10;
		count++;	
	}
	return (count);
}

char 	*parse(char *dest, int n, int len)
{
	char *temp;
	int	i;
	
	temp = ft_calloc(len + 1, 1);
	i = 0;
	while 
}

char	*ft_itoa(int n)
{	
	char	*res;
	int	qtd;

	qtd = count_digits(n);
	if (qtd == 1)
		return (strdup(&(n + 48)));
	res = ft_calloc(qtd + 1, 1);
	
}
