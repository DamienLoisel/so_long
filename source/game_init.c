/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dloisel <dloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:27:44 by dloisel           #+#    #+#             */
/*   Updated: 2024/06/14 21:53:24 by dloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_sprite	ft_load_sprite(t_game *game, char *file_path)
{
	t_sprite	sprite;

	sprite.image = mlx_xpm_file_to_image(game->mlx_ptr, file_path, \
	&sprite.width, &sprite.height);
	if (!sprite.image)
	{
		ft_printf("%s%s%s\n", "Couldn't load the sprite at '", \
		file_path, "' does it exist ?");
		window_destroy(game);
	}
	return (sprite);
}

void	ft_init_sprite(t_game *game)
{
	if (game->map.is_map_valid == 1)
		return ;
	game->wall = ft_load_sprite(game, "xpm/Tree.xpm");
	game->coin = ft_load_sprite(game, "xpm/Coin.xpm");
	game->exit_open = ft_load_sprite(game, "xpm/Exit_open.xpm");
	game->floor = ft_load_sprite(game, "xpm/Floor.xpm");
	game->player_sprite = ft_load_sprite(game, "xpm/Player.xpm");
}

void	ft_mlx_init(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
	{
		ft_error_map("Couldn't init the mlx ptr.", game);
		window_destroy(game);
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr, \
	game->map.columns * IMG_WIDTH, game->map.rows * IMG_HEIGHT, "so_long");
	if (!game->win_ptr)
	{
		free(game->win_ptr);
		ft_printf("%s\n", "Couldn't create the window.");
		return ;
	}
}
