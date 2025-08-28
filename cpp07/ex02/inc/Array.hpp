/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 09:55:24 by madias-m          #+#    #+#             */
/*   Updated: 2025/08/28 14:32:07 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY__HPP
# define ARRAY__HPP

#include <cstdlib>
#include <exception>

template<typename T>
class Array
{
    private:
        T*              _elements;
        unsigned int    _size;
    
    public:
        Array(void);
        Array(unsigned int n);
        Array(Array const &src);
        ~Array(void);
    
        Array           &operator=(Array const &rhs);
        T               &operator[](unsigned int index);
        T const         &operator[](unsigned int index) const;
    
        unsigned int    size(void) const;
    
        class CustomException : public std::exception
        {
        public:
            virtual const char* what() const throw()
            {
                return "Index out of bounds";
            }
        };
};
    
template<typename T>
Array<T>::Array(void) : _elements(NULL), _size(0){}

template<typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
    _elements = new T[n]();
}

template<typename T>
Array<T>::Array(Array const &src) : _elements(NULL), _size(0)
{
    *this = src;
}

template<typename T>
Array<T>::~Array(void)
{
    delete[] _elements;
}

template<typename T>
Array<T>    &Array<T>::operator=(Array const &rhs)
{
    if (this != &rhs)
    {
        delete[] _elements;
        this->_size = rhs._size;
        this->_elements = new T[this->_size];
        for (unsigned int i = 0; i < this->_size; i++)
            this->_elements[i] = rhs._elements[i];
    }
    return (*this);
}

template<typename T>
T   &Array<T>::operator[](unsigned int index)
{
    if (index >= this->_size)
        throw CustomException();
    return (this->_elements[index]);
}

template<typename T>
T const &Array<T>::operator[](unsigned int index) const
{
    if (index >= this->_size)
        throw CustomException();
    return (this->_elements[index]);
}

template<typename T>
unsigned int    Array<T>::size(void) const
{
    return (this->_size);
}

#endif
