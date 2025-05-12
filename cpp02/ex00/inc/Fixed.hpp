/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:53:36 by madias-m          #+#    #+#             */
/*   Updated: 2025/05/12 19:00:10 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int	rawValue;
		static const int fract = 8;
	public:
		Fixed(void);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed(void);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};
#endif