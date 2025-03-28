/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 10:42:17 by marcelodmac       #+#    #+#             */
/*   Updated: 2025/03/28 11:49:49 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class Zombie
{
    public:
        Zombie(){};
        void    announce(void);
        Zombie  *newZombie(std::string name);
        void    randomChump(std::string name);
    private:
        std::string name;
        Zombie(std::string name);
};
