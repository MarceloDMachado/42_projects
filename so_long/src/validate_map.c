/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 13:36:18 by madias-m          #+#    #+#             */
/*   Updated: 2024/03/17 16:56:35 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	count(t_list *lst, int *len, int *lines)
{
	*lines = 1;
	*len = 0;
	while (lst->next)
	{
		if (*(char *)(lst->content) == 10)
			(*lines)++;
		if (ft_strchr("01CEP",*(char *)(lst->content)))
			(*len)++;
		lst = lst->next;
	}
}

t_list	*fill_line(t_list *lst, char *str)
{
	while (lst->next)
	{
		if (*(char *)(lst->content) != 10)
			*str++ = *(char *)(lst->content);
		else
		{
			lst = lst->next;
			return (lst);
		}
		lst = lst->next;
	}
	return (lst);
}


char	**build_map(t_list *lst)
{
	char	**map;
	int		len;
	int		line_count;
	int		i;
	
	count(lst, &len, &line_count);
	map = ft_calloc(line_count + 1, sizeof(char *));
	if (!map)
		return (0);
	i = 0;
	while (i < line_count)
		map[i++] = ft_calloc(len / line_count + 1, sizeof(char));
	i = 0;
	while (i < line_count && lst->next)
		lst = fill_line(lst, map[i++]);
	return (map);
}

int	is_rectangular(char **map)
{
	int	line_count;
	int	line_size;
	int	i;

	i = 0;
	while (map[i])
		i++;
	line_count = i;
	i = 0;
	line_size = 0;
	while (map[i])
	{
		if (!line_size)
			line_size = ft_strlen(map[i]);
		else
		{
			if (line_size != ft_strlen(map[i]))
				return (0);
		}
		i++;
	}
	return (line_size != line_count);
}

int	validate_map(void)
{
	t_list	*list;
	int		fd;
	char	c;
	char	**map;

	fd = open("src/default.ber", O_RDONLY);
	while (read(fd, &c, 1))
	{
		if (!list)
			list = ft_lstnew(ft_strdup(&c));
		else 
			ft_lstadd_back(&list, ft_lstnew(ft_strdup(&c)));
	}
	map = build_map(list);
	ft_lstclear(&list, ft_free);
	ft_printf("%d", is_rectangular(map));
	return (1);
}
