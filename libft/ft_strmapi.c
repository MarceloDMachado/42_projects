/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcelodmachado <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 09:59:09 by marcelodmacha     #+#    #+#             */
/*   Updated: 2023/10/30 11:57:15 by marcelodmacha    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
    char    *res;
    int     len;
    int     i;

    len = ft_strlen(s);
    res = ft_calloc(len + 1, 1);
    if (!res)
        return (0);
    i = 0;
    while (i < len)
    {
        res[i] = f(i, s[i]);
        i++;          
    }
    return (res);
}

