/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:14:50 by madias-m          #+#    #+#             */
/*   Updated: 2025/05/05 16:41:14 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Weapon.h"

Weapon::Weapon(void){}

Weapon::Weapon(std::string type)
{
	this->type = type;
}

const std::string	Weapon::getType(void)
{
	return (this->type);
}

void		Weapon::setType(std::string type)
{
	this->type = type;
}
