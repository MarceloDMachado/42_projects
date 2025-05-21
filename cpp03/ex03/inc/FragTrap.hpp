/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 16:41:27 by madias-m          #+#    #+#             */
/*   Updated: 2025/05/21 15:40:00 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <ClapTrap.hpp>
#include <iostream>
#include <string>

class FragTrap : virtual public ClapTrap
{
    public:
        FragTrap(void);
        FragTrap(std::string name);
        FragTrap(FragTrap const& other);
        FragTrap& operator=(FragTrap const& other);
        ~FragTrap(void);
        void    attack(std::string &const target);´
        void    highFivesGuys(void);
};

#endif
