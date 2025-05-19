/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 02:04:21 by madias-m          #+#    #+#             */
/*   Updated: 2025/05/19 11:31:51 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DiamondTraP_HPP
# define DiamondTraP_HPP

#include <FragTrap.hpp>
#include <ScavTrap.hpp>
#include <iostream>
#include <string>

class DiamondTrap : public FragTrap, public ScavTrap
{
    private:
        std::string name;        
    public:
        DiamondTrap(void);
        DiamondTrap(std::string name);
        DiamondTrap(DiamondTrap const& other);
        DiamondTrap& operator=(DiamondTrap const& other);
        ~DiamondTrap(void);
        void    whoAmI();
        using   ScavTrap::attack;
};

#endif