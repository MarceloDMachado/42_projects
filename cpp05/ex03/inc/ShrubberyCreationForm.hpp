/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:24:02 by madias-m          #+#    #+#             */
/*   Updated: 2025/11/17 14:00:07 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		bool						isSigned;
		static int const			GRADE_TO_SIGN = 145;
		static int const			GRADE_TO_EXECUTE = 137;
		std::string					target;
		ShrubberyCreationForm(void);
		void						plantShrubbery(void) const;
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm(void);
		void						execute(Bureaucrat const& executor) const;

};

#endif
