/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:25:52 by madias-m          #+#    #+#             */
/*   Updated: 2024/03/25 16:22:08 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_list	*parse_file_to_list(char *path)
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
	close(fd);
	return (list);
}

static void	count_nodes(t_list *lst, int *len, int *row_count)
{
	char	last;

	*row_count = 0;
	*len = 0;
	last = 0;
	while (lst)
	{
		if (*(char *)(lst->content) == '\n' && last == '\n')
			break;
		if (*(char *)(lst->content) == '\n')
			(*row_count)++;
		else
			(*len)++;
		last = *(char *)lst->content;
		lst = lst->next;
	}
	if (last != '\n')
		(*row_count)++;
}

static t_list	*fill_row(t_list *lst, char *str)
{
	while (lst)
	{
		if (*(char *)lst->content != '\n')
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
	int		row_count;
	int		i;
	t_list	*init;

	init = lst;
	count_nodes(lst, &len, &row_count);
	map = ft_calloc(row_count + 1, sizeof(char *));
	if (!map)
		return (0);
	i = 0;
	while (i < row_count)
		map[i++] = ft_calloc(len / row_count + 1, sizeof(char));
	i = 0;
	while (i < row_count && lst->next)
		lst = fill_row(lst, map[i++]);
	ft_lstclear(&init, ft_free);
	return (map);
}
