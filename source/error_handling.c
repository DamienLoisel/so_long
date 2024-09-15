/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dloisel <dloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 20:22:47 by dloisel           #+#    #+#             */
/*   Updated: 2024/06/17 21:09:49 by dloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_error_map(char *msg, t_game *game)
{
	ft_printf(RED "%s\n", "Error");
	ft_printf("%s\n" RESET, msg);
	game->map.is_map_valid = 1;
}
