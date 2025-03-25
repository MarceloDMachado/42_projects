/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:50:59 by madias-m          #+#    #+#             */
/*   Updated: 2025/03/24 22:43:27 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include "../inc/phonebook.h"

class Contact {
	public:
		std::string get_first_name(void);
		void		set_first_name(std::string firstName);
		std::string get_last_name(void);
		void		set_last_name(std::string lastName);
		std::string get_nickname(void);
		void		set_nickname(std::string nickname);
		std::string	get_phone_number(void);
		void		set_phone_number(std::string phone);
		std::string	get_darkest_secret(void);
		void		set_darkest_secret(std::string darkestSecret);
		void		preview(void);
	private: 
		std::string	Fist_Name;
		std::string	Last_Name;
		std::string	Nickname;
		std::string	Phone_Number;
		std::string	Darkest_Secret;
		void		trunc(std::string value);
};

#endif