/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:50:59 by madias-m          #+#    #+#             */
/*   Updated: 2025/03/24 14:31:52 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include "../inc/phonebook.h"

class Contact {
	public:
		std::string get_name(void);
		void		set_name(std::string name);
		std::string	get_phone(void);
		void		set_phone(std::string phone);
	private: 
		std::string	Name;
		std::string	Phone;
};

#endif