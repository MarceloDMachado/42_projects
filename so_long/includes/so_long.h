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
# include <mlx.h>

# define PIXEL 48

typedef struct s_elements {
	void	*floor;
	void	*wall;
	void	*collectable;
	void	*player_l;
	void	*player_r;
	void	*exit;
	void	*enemy;
}	t_elements;

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
	int		collectables_count;
	t_elements	elements;
}	t_canvas;

typedef struct s_coord {
	int x;
	int y;
}	t_coord;

void    start_game(t_canvas *cvs);
int		validate_map(t_canvas *canvas);
char	**build_map(t_list *lst);
t_list	*parse_file_to_list(char *path);
void	count_max(t_canvas *canvas);
int		check(t_canvas *canvas, char elem, int unique);
int		only_wall(char *line);
void	free_map(t_canvas *canvas);

#endif

