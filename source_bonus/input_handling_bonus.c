/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dloisel <dloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:09:35 by dloisel           #+#    #+#             */
/*   Updated: 2024/06/20 15:30:49 by dloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	ft_handle_input(int keycode, t_game *game)
{
	if (keycode == UP_KEY || keycode == W_KEY)
		ft_player_move(game, game->player.pos.y - 1, game->player.pos.x);
	else if (keycode == DOWN_KEY || keycode == S_KEY)
		ft_player_move(game, game->player.pos.y + 1, game->player.pos.x);
	else if (keycode == RIGHT_KEY || keycode == D_KEY)
		ft_player_move(game, game->player.pos.y, game->player.pos.x + 1);
	else if (keycode == LEFT_KEY || keycode == A_KEY)
		ft_player_move(game, game->player.pos.y, game->player.pos.x - 1);
	else if (keycode == ESC_KEY)
		window_destroy(game);
	return (0);
}

void	ft_player_move(t_game *game, int new_y, int new_x)
{
	int	old_y;
	int	old_x;

	old_y = game->player.pos.y;
	old_x = game->player.pos.x;
	if (game->map.fullmap[new_y][new_x] == MAP_EXIT \
	&& game->map.coin_count == 0)
		ft_win(game);
	else if (game->map.fullmap[new_y][new_x] == ENEMY)
		ft_lose(game);
	else if (game->map.fullmap[new_y][new_x] != WALL && \
	game->map.fullmap[new_y][new_x] != MAP_EXIT)
	{
		if (game->map.fullmap[new_y][new_x] == COIN)
			game->map.coin_count -= 1;
		game->map.fullmap[old_y][old_x] = FLOOR;
		game->player.pos.x = new_x;
		game->player.pos.y = new_y;
		game->map.fullmap[new_y][new_x] = PLAYER;
		game->movements_count += 1;
		ft_enemy_detect(game);
	}
}

void	ft_enemy_detect(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			if (game->map.fullmap[y][x] == ENEMY)
			{
				if (ft_enemy_direction(game, y, x) == 1)
					game->map.fullmap[y][x] = FLOOR;
			}
			x++;
		}
		y++;
	}
}

int	ft_enemy_direction(t_game *game, int y, int x)
{
	int	direction;

	direction = (rand() % 4) + 1;
	if (direction == 1)
		return (ft_enemy_move(game, y + 1, x));
	else if (direction == 2)
		return (ft_enemy_move(game, y, x + 1));
	else if (direction == 3)
		return (ft_enemy_move(game, y - 1, x));
	else if (direction == 4)
		return (ft_enemy_move(game, y, x - 1));
	else
		return (0);
}

int	ft_enemy_move(t_game *game, int y, int x)
{
	if (game->map.fullmap[y][x] == PLAYER)
		ft_lose(game);
	else if (game->map.fullmap[y][x] == FLOOR)
	{
		game->map.fullmap[y][x] = ENEMY;
		return (1);
	}
	return (0);
}
