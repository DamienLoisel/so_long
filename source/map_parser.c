/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dloisel <dloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:59:33 by dloisel           #+#    #+#             */
/*   Updated: 2024/06/14 00:49:06 by dloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_map_parser(t_game *game)
{
	if (game->map.is_map_valid == 1)
		return ;
	ft_check_rows(game);
	ft_check_columns(game);
	ft_count_map_parameters(game);
	ft_verify_map_parameters(game);
}

void	ft_check_rows(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.columns)
	{
		if (game->map.fullmap[0][i] != WALL)
		{
			ft_error_map("There's a wall missing from the first row!", game);
			return ;
		}
		else if (game->map.fullmap[game->map.rows - 1][i] != WALL)
		{
			ft_error_map("There's a wall missing from the last row!", game);
			return ;
		}
		i++;
	}
}

void	ft_check_columns(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.rows)
	{
		if (game->map.fullmap[i][0] != WALL)
			ft_error_map("There's a wall missing from the first column!", game);
		else if (game->map.fullmap[i][game->map.columns - 1] != WALL)
			ft_error_map("There's a wall missing from the last column!", game);
		i++;
	}
}

void	ft_count_map_parameters(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.rows)
	{
		j = -1;
		while (++j < game->map.columns)
		{
			if (game->map.fullmap[i][j] == PLAYER)
			{
				game->player.pos.x = j;
				game->player.pos.y = i;
				game->map.player_count++;
			}
			else if (game->map.fullmap[i][j] == COIN)
				game->map.coin_count++;
			else if (game->map.fullmap[i][j] == MAP_EXIT)
				game->map.exit_count++;
			else if (game->map.fullmap[i][j] != WALL
				&& game->map.fullmap[i][j] != FLOOR)
				ft_error_map("There's an invalid character in the map!", game);
		}
	}
}

void	ft_verify_map_parameters(t_game *game)
{
	if (game->map.is_map_valid == 1)
		return ;
	if (game->map.player_count > 1)
		ft_error_map("Only 1 player is allowed in the map!", game);
	else if (game->map.player_count < 1)
		ft_error_map("At least 1 player must be present in the map!", game);
	if (game->map.coin_count == 0)
		ft_error_map("At least 1 coin must be present in the map!", game);
	if (game->map.exit_count == 0)
		ft_error_map("At least 1 exit must be present in the map!", game);
	else if (game->map.exit_count > 1)
		ft_error_map("Only 1 exit is allowed in the map!", game);
}
