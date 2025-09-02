/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 19:41:53 by madias-m          #+#    #+#             */
/*   Updated: 2025/09/02 19:53:18 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK__HPP
# define MUTANTSTACK__HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
    	typedef typename std::stack<T>::container_type::iterator				iterator;
    	typedef typename std::stack<T>::container_type::reverse_iterator		reverse_iterator;
    	typedef typename std::stack<T>::container_type::const_iterator			const_iterator;
    	typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;

    	MutantStack(void) : std::stack<T>(){}
    	MutantStack(MutantStack const &other) : std::stack<T>(other) {}
    	MutantStack	&operator=(MutantStack const &rhs)
    	{
            if (this != &rhs)
            	std::stack<T>::operator=(rhs);
    		return (*this);
    	}
        ~MutantStack(void){}

    	iterator			begin(void)
        {
            return (this->c.begin());
        }
        
    	iterator			end(void)
        {
            return (this->c.end());
        }
    
    	reverse_iterator	rbegin(void)
        {
            return (this->c.rbegin());
        }
        
    	reverse_iterator	rend(void)
        {
            return (this->c.rend());
        }
        
        const_iterator		begin(void) const
        {
            return (this->c.begin());
        }
        
    	const_iterator		end(void) const
        {
            return (this->c.end());
        }
    
    	const_reverse_iterator rbegin(void) const
        { 
            return (this->c.rbegin());
        }
        
    	const_reverse_iterator rend(void) const
        { 
            return (this->c.rend());
        }
};

#endif
