/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 14:32:05 by madias-m          #+#    #+#             */
/*   Updated: 2025/08/27 14:48:01 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER__HPP
# define SERIALIZER__HPP

# include <cstdint>
# include "Data.hpp"

class Serializer {
private:
    Serializer(void);
    Serializer(const Serializer &other);
    Serializer &operator=(const Serializer &other);
    ~Serializer(void);

public:
    static uintptr_t    serialize(Data *ptr);
    static Data        *deserialize(uintptr_t raw);
};

#endif
