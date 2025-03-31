/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 10:42:17 by marcelodmac       #+#    #+#             */
/*   Updated: 2025/03/31 14:37:15 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include "../inc/Zombie.h"

class Zombie
{
	public:
		Zombie(){};
		Zombie(std::string name);
		~Zombie();
		void	announce(void);
		void	set_name(std::string name);
	private:
		std::string name;
};

#endif