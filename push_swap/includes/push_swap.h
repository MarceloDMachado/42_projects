/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 13:30:06 by madias-m          #+#    #+#             */
/*   Updated: 2024/06/09 13:30:13 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

int		get_argc(int n);
int		**get_stack_a(void);
int		**get_stack_b(void);
void	free_stack(int **(*stack)(void));
void	fill_stack(int **(*stack)(void), char **argv);
int		stack_len(int **(*stack)(void));

#endif