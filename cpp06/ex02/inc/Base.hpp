/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 15:14:52 by madias-m          #+#    #+#             */
/*   Updated: 2025/08/27 15:19:42 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE__HPP
# define BASE__HPP

class Base {
    public:
        virtual ~Base(void){};
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

#endif
