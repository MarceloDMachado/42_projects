/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:24:25 by madias-m          #+#    #+#             */
/*   Updated: 2025/11/17 13:59:58 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
	private:
		bool						isSigned;
		static int const			GRADE_TO_SIGN = 72;
		static int const			GRADE_TO_EXECUTE = 45;
		std::string					target;
    public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		~RobotomyRequestForm(void);
		void	makeDrillingNoises(void) const;
		void	execute(Bureaucrat const& executor) const;

};


#endif
