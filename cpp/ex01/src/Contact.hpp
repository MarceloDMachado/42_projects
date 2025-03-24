/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:50:59 by madias-m          #+#    #+#             */
/*   Updated: 2025/03/24 12:51:26 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

class Contact {
	public:
		const char 	*get_name(void);
		void	set_name(const char *name);
		const char	*get_phone(void);
		void	set_phone(const char *phone);
	private: 
		const char	*Name;
		const char	*Phone;
};

#endif