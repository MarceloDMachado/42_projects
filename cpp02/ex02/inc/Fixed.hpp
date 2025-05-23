/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:53:36 by madias-m          #+#    #+#             */
/*   Updated: 2025/05/15 13:33:40 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int	rawValue;
		static const int fract = 8;
	public:
		Fixed(void);
		Fixed(const Fixed& other);
		Fixed(int const n);
		Fixed(float const n);
		~Fixed(void);
		Fixed&				operator=(const Fixed& other);
		Fixed&				operator++(void);
		Fixed&				operator--(void);
		Fixed				operator++(int);
		Fixed				operator--(int);
		Fixed				operator+(Fixed const& rhs) const;
		Fixed				operator-(Fixed const& rhs) const;
		Fixed				operator*(Fixed const& rhs) const;
		Fixed				operator/(Fixed const& rhs) const;
		bool				operator>(Fixed const& rhs) const;
		bool				operator<(Fixed const& rhs) const;
		bool				operator>=(Fixed const& rhs) const;
		bool				operator<=(Fixed const& rhs) const;
		bool				operator==(Fixed const& rhs) const;
		bool				operator!=(Fixed const& rhs) const;
		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		float				toFloat(void) const;
		int					toInt(void) const;
		static Fixed&		min(Fixed& f1, Fixed& f2);
		static Fixed const&	min(Fixed const& f1, Fixed const& f2);
		static Fixed&		max(Fixed& f1, Fixed& f2);
		static Fixed const&	max(Fixed const& f1, Fixed const& f2);
};

std::ostream&	operator<<(std::ostream& o, Fixed const& rhs);

#endif