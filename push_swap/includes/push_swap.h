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

typedef void	(*t_farray)(void);

t_farray	**fmatrix(void);
t_farray	last_func(t_farray *f_array);
t_farray	*get_cheapest(void);
int			get_argc(int n);
int			is_signal(char c);
int			**stack_a(void);
int			**stack_b(void);
void		free_stack(int **(*stack)(void));
void		fill_stack(int **(*stack)(void), char **argv);
int			stack_len(int **(*stack)(void));
void		sa(void);
void		sb(void);
void		ss(void);
void		pa(void);
void		pb(void);
void		ra(void);
void		rb(void);
void		rr(void);
void		reverse(int **(*stack)(void));
void		rra(void);
void		rrb(void);
void		rrr(void);
void		print(int **(*stack)(void));
void		swap_pointer(int **a, int **b);
void		fix_stack(int **(*stack)(void));
void		sort(void);
void		rotate(int **(*stack)(void));
int			is_sorted(void);
void		(*handle_sort(void))(void);
int			index_of(int **(*stack)(void), int *n);
int			*get_min(int **(*stack)(void));
int			*get_max(int **(*stack)(void));
int			*get_nearest(int target);
int			*last_elem(int **(stack)(void));
int			is_sorted(void);
int			calc_distance(int **(*stack)(void), int *n);
void		(*rotate_func(int **(*f)(void), int i))(void);
void		free_func_matrix(void);
void		price(void);
void		append(t_farray *f_array, t_farray new_func);
void		dynamic_append(t_farray *farray, t_farray new_func, unsigned int n);
void		replicate(t_farray *f_array, t_farray new_func, unsigned int n);
void		reduce(t_farray *f_array);
int			farray_len(t_farray *f_array);
int			is_biggest(int *n);
int			is_smallest(int *n);
int			is_middle(int *n);
void		clean_func_matrix(void);

#endif