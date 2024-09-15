/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dloisel <dloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 20:57:58 by dloisel           #+#    #+#             */
/*   Updated: 2024/06/15 16:27:01 by dloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_struct_init(t_game *game)
{
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
	game->map.rows = 0;
	game->map.columns = 0;
	game->map.is_map_valid = 0;
	game->map.coin_count = 0;
	game->map.player_count = 0;
	game->map.exit_count = 0;
	game->map.fullmap = NULL;
	game->movements_count = 0;
	game->player_sprite.image = NULL;
	game->coin.image = NULL;
	game->exit_open.image = NULL;
	game->wall.image = NULL;
	game->floor.image = NULL;
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (1);
	ft_struct_init(game);
	ft_arg_verif(argc, argv, game);
	if (game->map.is_map_valid != 1)
		ft_map_init(game, argv[1], 0);
	ft_map_parser(game);
	ft_is_map_beatable(game);
	if (game->map.is_map_valid != 1)
	{
		ft_mlx_init(game);
		ft_init_sprite(game);
		ft_render_map(game);
		mlx_hook(game->win_ptr, KeyPress, KeyPressMask, ft_handle_input, game);
		mlx_hook(game->win_ptr, DestroyNotify, ButtonPressMask \
		, window_destroy, game);
		mlx_loop(game->mlx_ptr);
	}
	ft_free_split(game);
	free(game);
	return (0);
}
