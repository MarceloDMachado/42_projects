/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:09:19 by madias-m          #+#    #+#             */
/*   Updated: 2025/05/05 15:27:01 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include "../inc/Weapon.h"

class Weapon
{
	private:
		std::string	*type;
	public:
		Weapon(void);
		Weapon(std::string type);
		const std::string	getType(void);
		void				setType(std::string type);
		
};

#endif