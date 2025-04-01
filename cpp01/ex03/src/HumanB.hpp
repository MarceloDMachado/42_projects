/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:57:58 by madias-m          #+#    #+#             */
/*   Updated: 2025/04/01 13:03:33 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "../inc/HumanB.h"

class HumanB 
{
	private:
		std::string	name;
		Weapon		weapon;
		HumanB(void);
	public:
		HumanB(std::string name);
		void		attack(void);
		void		setWeapon(Weapon weapon);
};

#endif