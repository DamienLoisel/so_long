/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dloisel <dloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:06:17 by dloisel           #+#    #+#             */
/*   Updated: 2024/07/07 19:01:08 by dloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	ft_render_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	if (game->map.is_map_valid == 1)
		return (-1);
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			ft_render_sprite(game, game->floor, y, x);
			ft_identify_sprite(game, x, y);
			x++;
		}
		y++;
	}
	ft_print_movements(game);
	return (0);
}

void	ft_identify_sprite(t_game *game, int x, int y)
{
	char	which_sprite;

	which_sprite = game->map.fullmap[y][x];
	if (which_sprite == WALL)
		ft_render_sprite(game, game->wall, y, x);
	else if (which_sprite == COIN)
		ft_update_coin_sprite(game, y, x);
	else if (which_sprite == MAP_EXIT)
		ft_render_sprite(game, game->exit_open, y, x);
	else if (which_sprite == ENEMY)
		ft_update_enemy_sprite(game, y, x);
	else if (which_sprite == PLAYER)
		ft_render_sprite(game, game->player_sprite, y, x);
}

void	ft_render_sprite(t_game *game, t_sprite sprite, int line, int columns)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, sprite.image, \
	columns * sprite.width, line * sprite.height);
}

void	ft_print_movements(t_game *game)
{
	char	*movements;
	char	*str;

	movements = ft_itoa(game->movements_count);
	if (movements == NULL)
		return ;
	str = ft_strjoin("Movement count: ", movements);
	free(movements);
	if (str == NULL)
		return ;
	mlx_set_font(game->mlx_ptr, game->win_ptr, "10*20");
	mlx_string_put(game->mlx_ptr, game->win_ptr, 0, \
	(game->map.rows + 1) * 32, 0xFFFFFF, str);
	free(str);
}
