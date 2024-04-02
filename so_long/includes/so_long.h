/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 13:56:04 by madias-m          #+#    #+#             */
/*   Updated: 2024/03/28 23:12:49 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <mlx.h>

# define PIXEL	48
# define ESC	65307
# define UP		0xff52
# define DOWN	0xff54
# define LEFT	0xff51
# define RIGHT	0xff53

typedef struct s_sprites {
	void	*floor;
	void	*wall;
	void	*collectable;
	void	*player_r;
	void	*player_l;
	void	*exit;
	void	*enemy;
	void	*trail;
}	t_sprites;

typedef struct s_canvas {
	void		*mlx;
	void		*win;
	char		**map;
	int			max_x;
	int			max_y;
	int			is_valid;
	int			collectables_count;
	int			player_moves;
	char		player_dir;
	t_sprites	sprites;
}	t_canvas;

typedef struct s_coord {
	int	x;
	int	y;
}	t_coord;

void	start_game(t_canvas *cvs);
int		validate_map(t_canvas *canvas);
char	**build_map(t_list *lst);
t_list	*parse_file_to_list(char *path);
void	count_max(t_canvas *canvas);
int		check(t_canvas *canvas, char elem, int unique);
int		only_wall(char *line);
void	free_map(char ***map);
void	put_sprite(t_canvas *cvs, int y, int x, void *sprite);
int		render(t_canvas *cvs);
void	draw_pos(t_canvas *cvs, int y, int x);
void	quit_game(t_canvas *cvs, int exit_as);
int		on_key_press(int key, t_canvas *cvs);
void	move_player(int key, t_canvas *cvs);
t_coord	get_element_pos(char **map, char element);
char	**clone_map(t_canvas *cvs);
int		check_flood_fill(t_canvas *cvs);
int		animate(t_canvas *cvs);

#endif
