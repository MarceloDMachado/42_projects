/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:37:42 by madias-m          #+#    #+#             */
/*   Updated: 2025/03/27 13:26:45 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "../inc/phonebook.h"

class PhoneBook{
	public:
		void	init(void);
	private:
		Contact 	Contacts[8];
		int			ContactsCount;
		std::string	LastCommand;
		bool		run(void);
		void		add_contact(void);
		void		show_contacts(void);
};

#endif