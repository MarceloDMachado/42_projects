/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 21:41:24 by madias-m          #+#    #+#             */
/*   Updated: 2025/05/20 15:26:35 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{
    private:
        std::string	ideas[100];
    public:
        Brain(void);
        Brain(Brain const& other);
        Brain&	operator=(Brain const& other);
		~Brain(void);
        std::string*	getIdeas(void);
};

#endif
