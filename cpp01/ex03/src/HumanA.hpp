/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:58:05 by madias-m          #+#    #+#             */
/*   Updated: 2025/04/01 12:20:22 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "../inc/HumanA.h"

class HumanA
{
	private:
		HumanA();
		std::string	name;
		Weapon		weapon;
	public:
		HumanA(std::string name, Weapon weapon);
		void		attack(void);
		
};
#endif