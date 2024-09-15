/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_render.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dloisel <dloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:16:25 by dloisel           #+#    #+#             */
/*   Updated: 2024/06/19 16:10:55 by dloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	ft_update_enemy_sprite(t_game *game, int y, int x)
{
	static struct timespec	last_update_time;
	struct timespec			current_time;
	double					time_diff;

	clock_gettime(0, &current_time);
	time_diff = (current_time.tv_sec - last_update_time.tv_sec) + \
				(current_time.tv_nsec - last_update_time.tv_nsec) / 1e9;
	if (time_diff >= ANIMATION_UPDATE)
	{
		last_update_time = current_time;
		game->current_frame = (game->current_frame + 1) % 2;
	}
	if (game->current_frame == 0)
		ft_render_sprite(game, game->enemy_sprite, y, x);
	else
		ft_render_sprite(game, game->enemy_sprite2, y, x);
}

void	ft_update_coin_sprite(t_game *game, int y, int x)
{
	static struct timespec	last_update_time;
	struct timespec			current_time;
	double					time_diff;

	clock_gettime(0, &current_time);
	time_diff = (current_time.tv_sec - last_update_time.tv_sec) + \
				(current_time.tv_nsec - last_update_time.tv_nsec) / 1e9;
	if (time_diff >= ANIMATION_UPDATE && game->map.enemy_count == 0)
	{
		last_update_time = current_time;
		game->current_frame = (game->current_frame + 1) % 2;
	}
	if (game->current_frame == 0)
		ft_render_sprite(game, game->coin1, y, x);
	else
		ft_render_sprite(game, game->coin2, y, x);
}
