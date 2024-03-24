/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 13:56:04 by madias-m          #+#    #+#             */
/*   Updated: 2024/03/20 18:32:56 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"

typedef struct s_canvas {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	char	**map;
	int		max_x;
	int		max_y;
	int		is_valid;
}	t_canvas;


typedef struct s_coord {
	int x;
	int y;
}	t_coord;

int		validate_map(t_canvas *canvas);
char	**build_map(t_list *lst);
t_list	*read_map(char *path);
void	count_max(t_canvas *canvas);
int		check(t_canvas *canvas, char elem, int unique);
int		only_wall(char *line);

#endif

