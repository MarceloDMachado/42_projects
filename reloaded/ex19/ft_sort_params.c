/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:41:20 by madias-m          #+#    #+#             */
/*   Updated: 2023/10/04 12:31:38 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
	ft_putchar(10);
}

void	ft_swap(char **s1, char **s2)
{
	char	*temp;

	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

int	ft_strcmp(char *s1, char *s2)
{
	if (s1 == s2)
		return (0);
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return ((int) *s1 - *s2);
		s1++;
		s2++;
	}
	return ((int) *s1 - *s2);
}

void	ft_sort_params(char *arr[], int n)
{
	int	index;

	index = 1;
	while (index < n)
	{
		if (index == 1)
			index++;
		if (ft_strcmp(arr[index], arr[index - 1]) >= 0)
			index++;
		else
		{
			ft_swap(&arr[index], &arr[index - 1]);
			index--;
		}
	}
}

int	main(int argc, char *argv[])
{
	if (argc > 2)
		ft_sort_params(argv, argc);
	argv++;
	while (*argv)
	{
		ft_putstr(*argv);
		argv++;
	}
}
