/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 19:05:48 by madias-m          #+#    #+#             */
/*   Updated: 2024/06/19 19:05:49 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_signal(char c)
{
	return (c == 45 || c == 43);
}

void	swap_pointer(int **a, int **b)
{
	int	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	fix_stack(int **(*stack)(void))
{
	int	i;

	if (stack()[0])
		return ;
	i = 0;
	while (stack()[i + 1])
	{
		stack()[i] = stack()[i + 1];
		i++;
	}
	stack()[i] = 0;
}

int	get_argc(int n)
{
	static int	argc = 0;

	if (!argc)
		argc = n;
	return (argc);
}
