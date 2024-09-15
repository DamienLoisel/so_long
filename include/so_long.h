/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dloisel <dloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 19:37:41 by dloisel           #+#    #+#             */
/*   Updated: 2024/06/18 19:47:57 by dloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "/home/dloisel/sgoinfre/minilibx-linux/mlx.h"
# include "/home/dloisel/sgoinfre/minilibx-linux/mlx_int.h"
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>
# include <math.h>

# define IMG_HEIGHT	32
# define IMG_WIDTH	32

# define WALL '1'
# define FLOOR '0'
# define PLAYER 'P'
# define COIN 'C'
# define MAP_EXIT 'E'

# define ESC_KEY 65307
# define W_KEY	119
# define A_KEY	97
# define S_KEY	115
# define D_KEY	100

# define UP_KEY	65362
# define LEFT_KEY	65361
# define RIGHT_KEY	65363
# define DOWN_KEY	65364

# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define BLUE "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN "\x1b[36m"
# define RESET "\x1b[0m"

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_sprite
{
	void	*image;
	int		width;
	int		height;
}	t_sprite;

typedef struct s_map
{
	char	**fullmap;
	char	**flood_fill;
	int		rows;
	int		columns;
	int		player_count;
	int		coin_count;
	int		exit_count;
	int		is_map_valid;
}	t_map;

typedef struct s_player
{
	t_pos	pos;
}	t_player;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			width;
	int			height;
	int			movements_count;
	t_map		map;
	t_player	player;
	t_sprite	wall;
	t_sprite	coin;
	t_sprite	exit_open;
	t_sprite	floor;
	t_sprite	player_sprite;
}	t_game;

void		ft_map_parser(t_game *game);
void		ft_check_rows(t_game *game);
void		ft_check_columns(t_game *game);
void		ft_count_map_parameters(t_game *game);
void		ft_verify_map_parameters(t_game *game);
void		ft_error_map(char *msg, t_game *game);
void		ft_map_init(t_game *game, char *argv, int fd);
void		ft_check_emptyline(char *line, t_game *game);
void		ft_ismap_rectangle(char *line, t_game *game);
int			first_row_length(char *line);
void		ft_arg_verif(int argc, char **argv, t_game *game);
void		ft_is_map_beatable(t_game *game);
void		ft_floodfill(t_game *flood_game, int x, int y);
void		ft_get_player_pos(t_game *flood_game, t_pos *player_pos);
void		ft_free_split(t_game *game);
void		ft_struct_init(t_game *game);
void		ft_map_main(t_game *game, char **argv);
void		ft_mlx_init(t_game *game);
int			window_destroy(t_game *game);
int			ft_handle_input(int keycode, t_game *game);
int			ft_render_map(t_game *game);
t_sprite	ft_load_sprite(t_game *game, char *file_path);
void		ft_init_sprite(t_game *game);
void		ft_identify_sprite(t_game *game, int x, int y);
void		ft_render_sprite(t_game *game, t_sprite sprite, \
int line, int columns);
void		ft_render_player(t_game *game, int line, int columns);
void		ft_free_flood_fill(t_game *game);
void		ft_player_move(t_game *game, int new_y, int new_x);
void		ft_destroy_images(t_game *game);
void		ft_win(t_game *game);

#endif
