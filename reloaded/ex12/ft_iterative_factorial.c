/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:14:43 by madias-m          #+#    #+#             */
/*   Updated: 2023/10/03 13:14:46 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	unsigned int	result;

	if (nb == 0)
		return (1);
	result = nb;
	while (nb > 1 && result <= 2147483647)
		result *= --nb;
	if (result > 2147483647 || nb < 0)
		return (0);
	return (result);
}
