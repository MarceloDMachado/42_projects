/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:21:47 by madias-m          #+#    #+#             */
/*   Updated: 2025/08/27 16:22:20 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER__HPP
# define WHATEVER__HPP

template<typename T>
void    swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
T const &min(T const &a, T const &b)
{
    return (a < b ? a : b);
}

template<typename T>
T const &max(T const &a, T const &b)
{
    return (a > b ? a : b);
}

#endif
