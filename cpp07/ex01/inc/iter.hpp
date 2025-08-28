/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 09:46:20 by madias-m          #+#    #+#             */
/*   Updated: 2025/08/28 09:47:33 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER__HPP
# define ITER__HPP

#include <cstddef>

template<typename T>
void	iter(T *array, size_t length, void (*f)(T &))
{
	if (!array || !f)
		return ;
	for (size_t i = 0; i < length; i++)
		f(array[i]);
}

template<typename T>
void	iter(const T *array, size_t length, void (*f)(const T &))
{
	if (!array || !f)
		return ;
	for (size_t i = 0; i < length; i++)
		f(array[i]);
}

#endif
