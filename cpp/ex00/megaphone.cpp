/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 12:44:20 by marcelodmac       #+#    #+#             */
/*   Updated: 2025/03/16 14:03:33 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
// #include

int main(int argc, char **argv)
{
	int i;
	int j;
	
    if (argc > 1)
	{
		j = 0;
		while (argv[++j])
		{
			i = -1;
			while (argv[j][++i])
				argv[j][i] = ::toupper(argv[j][i]);
			std::cout << argv[j];
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n"; 
	return (0);
}