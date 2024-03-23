/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:25:52 by madias-m          #+#    #+#             */
/*   Updated: 2024/03/23 15:26:25 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_list	*read_map(char *path)
{
	t_list	*list;
	int		fd;
	char	c;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nMap not found!");
		return (0);
	}
	list = 0;
	while (read(fd, &c, 1))
	{
		if (!list)
			list = ft_lstnew(ft_strdup(&c));
		else
			ft_lstadd_back(&list, ft_lstnew(ft_strdup(&c)));
	}
	return (list);
}

static void	count_nodes(t_list *lst, int *len, int *lines)
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

static t_list	*fill_line(t_list *lst, char *str)
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
	t_list	*init;

	init = lst;
	count_nodes(lst, &len, &line_count);
	map = ft_calloc(line_count + 1, sizeof(char *));
	if (!map)
		return (0);
	i = 0;
	while (i < line_count)
		map[i++] = ft_calloc(len / line_count + 1, sizeof(char));
	i = 0;
	while (i < line_count && lst->next)
		lst = fill_line(lst, map[i++]);
	ft_lstclear(&init, ft_free);
	return (map);
}
