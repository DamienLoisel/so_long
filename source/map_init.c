/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dloisel <dloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:01:37 by dloisel           #+#    #+#             */
/*   Updated: 2024/06/17 23:10:23 by dloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	first_row_length(char *line)
{
	int	i;
	int	row_length;

	i = 0;
	row_length = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
		{
			row_length = i;
			break ;
		}
		i++;
	}
	return (row_length);
}

void	ft_ismap_rectangle(char *line, t_game *game)
{
	int	row_length;
	int	current_row_length;

	if (game->map.is_map_valid == 1)
		return ;
	current_row_length = 0;
	row_length = first_row_length(line);
	while (*line)
	{
		if (*line == '\n')
		{
			if (current_row_length != row_length)
			{
				ft_error_map("The map isn't a rectangle!", game);
				return ;
			}
			current_row_length = 0;
		}
		else
			current_row_length++;
		line++;
	}
}

void	ft_check_emptyline(char *line, t_game *game)
{
	int	i;

	if (game->map.is_map_valid == 1)
		return ;
	i = 1;
	if (line == NULL || line[0] == '\0' || (line[0] == '\n' && line[1] == '\0'))
	{
		ft_error_map("The map is empty!", game);
		return ;
	}
	else if (line[0] == '\n')
		ft_error_map("The first line of the map is empty!", game);
	if (line[ft_strlen(line)] == '\n')
		ft_error_map("The last line of the map is empty!", game);
	while (line[i + 1])
	{
		if (line[i] == '\n' && line[i + 1] == '\n')
			ft_error_map("There is an empty line in your map!", game);
		i++;
	}
}

void	ft_init_check(char *line, t_game *game, int fd)
{
	if (line == NULL)
	{
		game->map.is_map_valid = 1;
		return ;
	}
	ft_check_emptyline(line, game);
	ft_ismap_rectangle(line, game);
	if (game->map.is_map_valid != 1)
	{
		game->map.fullmap = ft_split(line, '\n');
		game->map.flood_fill = ft_split(line, '\n');
		if (game->map.fullmap)
			game->map.columns = (ft_strlen(game->map.fullmap[0]));
	}
	if (game->map.columns > 60 || game->map.rows > 30)
		ft_error_map("The map is too big to be displayed on screen!", game);
	close (fd);
}

void	ft_map_init(t_game *game, char *argv, int fd)
{
	char	*buff;
	char	*line;
	char	*temp;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_error_map("The map couldn't be opened.", game);
	line = ft_strdup("");
	if (!line)
		ft_error_map("Memory allocation error.", game);
	while (1)
	{
		buff = get_next_line(fd);
		if (buff == NULL)
			break ;
		temp = line;
		line = ft_strjoin(line, buff);
		free(temp);
		free(buff);
		if (!line)
			ft_error_map("Memory allocation error.", game);
		game->map.rows++;
	}
	ft_init_check(line, game, fd);
	free(line);
}
