/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:06:25 by madias-m          #+#    #+#             */
/*   Updated: 2025/08/28 15:15:56 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND__HPP
# define EASYFIND__HPP

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
    typename T::iterator it;
    for (it = container.begin(); it != container.end(); ++it)
    {
        if (*it == value)
            return (it);
    }
	return (it);
}

#endif
