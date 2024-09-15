/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_flood_fill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dloisel <dloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:22:10 by dloisel           #+#    #+#             */
/*   Updated: 2024/06/14 22:02:06 by dloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_get_player_pos(t_game *flood_game, t_pos *player_pos)
{
	int	i;
	int	j;

	i = 0;
	while (flood_game->map.fullmap[i])
	{
		j = 0;
		while (flood_game->map.fullmap[i][j])
		{
			if (flood_game->map.fullmap[i][j] == PLAYER)
			{
				player_pos->x = i;
				player_pos->y = j;
			}
			j++;
		}
		i++;
	}
}

void	ft_floodfill(t_game *flood_game, int x, int y)
{
	if (flood_game->map.fullmap[x][y] == MAP_EXIT)
		flood_game->map.exit_count++;
	if (flood_game->map.fullmap[x][y] == WALL || \
	flood_game->map.fullmap[x][y] == MAP_EXIT)
		return ;
	if (flood_game->map.fullmap[x][y] == COIN)
		flood_game->map.coin_count++;
	flood_game->map.fullmap[x][y] = WALL;
	ft_floodfill(flood_game, x + 1, y);
	ft_floodfill(flood_game, x - 1, y);
	ft_floodfill(flood_game, x, y + 1);
	ft_floodfill(flood_game, x, y - 1);
	return ;
}

void	ft_free_flood_fill(t_game *game)
{
	int	i;

	i = 0;
	if (!game->map.flood_fill)
		return ;
	while (game->map.flood_fill[i])
	{
		free(game->map.flood_fill[i]);
		i++;
	}
	free(game->map.flood_fill);
	game->map.flood_fill = NULL;
}

void	ft_is_map_beatable(t_game *game)
{
	t_pos	player_pos;
	t_game	*flood_game;

	player_pos.x = 0;
	player_pos.y = 0;
	if (game->map.is_map_valid == 1)
		return ;
	flood_game = malloc(sizeof(t_game));
	if (!flood_game)
		return ;
	flood_game->map.fullmap = game->map.flood_fill;
	flood_game->map.exit_count = 0;
	flood_game->map.coin_count = 0;
	ft_get_player_pos(flood_game, &player_pos);
	ft_floodfill(flood_game, player_pos.x, player_pos.y);
	if (flood_game->map.exit_count < 1)
		ft_error_map("The map is unbeatable because the exit is unreachable!",
			game);
	if (flood_game->map.coin_count != game->map.coin_count)
		ft_error_map
		("The map is unbeatable because all coins aren't reachable!", game);
	ft_free_flood_fill(game);
	free(flood_game);
}
