/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_and_free_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dloisel <dloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:15:10 by dloisel           #+#    #+#             */
/*   Updated: 2024/06/18 20:25:05 by dloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	window_destroy(t_game *game)
{
	ft_destroy_images(game);
	ft_free_split(game);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	free(game);
	exit(0);
	return (0);
}

void	ft_free_split(t_game *game)
{
	int	i;

	i = 0;
	if (!game->map.fullmap)
		return ;
	while (game->map.fullmap[i])
	{
		free(game->map.fullmap[i]);
		i++;
	}
	free(game->map.fullmap);
	i = 0;
	if (!game->map.flood_fill)
		return ;
	while (game->map.flood_fill[i])
	{
		free(game->map.flood_fill[i]);
		i++;
	}
	free(game->map.flood_fill);
}

void	ft_destroy_images(t_game *game)
{
	if (game->player_sprite.image)
		mlx_destroy_image(game->mlx_ptr, game->player_sprite.image);
	if (game->coin1.image)
		mlx_destroy_image(game->mlx_ptr, game->coin1.image);
	if (game->coin2.image)
		mlx_destroy_image(game->mlx_ptr, game->coin2.image);
	if (game->floor.image)
		mlx_destroy_image(game->mlx_ptr, game->floor.image);
	if (game->wall.image)
		mlx_destroy_image(game->mlx_ptr, game->wall.image);
	if (game->exit_open.image)
		mlx_destroy_image(game->mlx_ptr, game->exit_open.image);
	if (game->enemy_sprite.image)
		mlx_destroy_image(game->mlx_ptr, game->enemy_sprite.image);
	if (game->enemy_sprite2.image)
		mlx_destroy_image(game->mlx_ptr, game->enemy_sprite2.image);
}
