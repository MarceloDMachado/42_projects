/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:07:51 by madias-m          #+#    #+#             */
/*   Updated: 2024/01/13 13:39:01 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"

typedef struct s_flags
{
	int	hash;
	int	space;
	int	plus;
	int	space_fix;
	int	hyphen;
	int	o;
}	t_flags;

int		ft_printf(const char *str, ...);
void	put_char(int c, void *f, int *count);
void	put_str(char *str, void *f, int *count);
void	put_nbr(long nbr, t_flags *f, int *count);
void	put_unbr(unsigned int nbr, t_flags *f, int *count);
void	put_nbr_hex(size_t n, int is_low, t_flags *f, int *count);
void	put_ptr(size_t n, t_flags *f, int *count);
void	before(int len, t_flags *f, int *count);
void	after(int len, t_flags *f, int *count);
void	put_zero(int len, t_flags *f, int *count);
#endif
