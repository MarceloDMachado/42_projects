/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 10:40:50 by marcelodmac       #+#    #+#             */
/*   Updated: 2025/03/28 16:46:20 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.h"

int main(void)
{
    Zombie	*zombie;
    int		n;

    n = 5;
    zombie = zombieHorde(n, "potato");
    while (--n >= 0)
		zombie[n].announce();
	delete[] zombie;
    return (1);
}