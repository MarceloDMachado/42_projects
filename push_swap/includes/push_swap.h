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

typedef void	(*t_func)(void);

int		get_argc(int n);
int		is_signal(char c);
int		**get_stack_a(void);
int		**get_stack_b(void);
void	free_stack(int **(*stack)(void));
void	fill_stack(int **(*stack)(void), char **argv);
int		stack_len(int **(*stack)(void));
void	sa(void);
void	sb(void);
void	ss(void);
void	pa(void);
void	pb(void);
void	ra(void);
void	rb(void);
void	rr(void);
void	reverse(int **(*stack)(void));
void	rra(void);
void	rrb(void);
void	rrr(void);
void	print(int **(*stack)(void));
void	swap_pointer(int **a, int **b);
void	fix_stack(int **(*stack)(void));
void	sort(void);
void	rotate(int **(*stack)(void));
int		is_sorted(void);
void	(*handle_sort(void))(void);
int		index_of(int **(*stack)(void), int *n);
int		*get_min(int **(*stack)(void));
int		*get_max(int **(*stack)(void));
int		*last_elem(int **(stack)(void));
int		is_sorted(void);
int		calc_distance(int **(*stack)(void), int *n);
void	(*rotate_func(int **(*f)(void), int i))(void);
t_func	**func_matrix(void);
void	free_func_matrix(void);
void	price(void);

#endif