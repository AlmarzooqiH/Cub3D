/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthodi <mthodi@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 21:44:05 by mthodi            #+#    #+#             */
/*   Updated: 2025/07/09 15:05:59 by mthodi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief Checks if a character is a player character.
 * @param c The character to check.
 * @return 1 if the character is a player, 0 otherwise.
 */
int	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

/**
 * @brief Checks if the map contains only valid characters.
 * @param map The 2D array containing the map.
 * @return 1 if all characters are valid, 0 otherwise.
 * @note Valid characters are: 0, 1, N, S, E, W, space, newline.
 */
int	is_valid_chars(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'N'
				&& map[i][j] != 'S' && map[i][j] != 'E'
				&& map[i][j] != 'W' && map[i][j] != ' ')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	set_north_south(t_d *p, char dir)
{
	if (dir == 'N')
	{
		p->player->pdx = 0;
		p->player->pdy = -1;
		p->player->camera_x = 0.66;
	}
	else
	{
		p->player->pdx = 0;
		p->player->pdy = 1;
		p->player->camera_x = -0.66;
	}
	p->player->camera_y = 0;
}

void	set_east_west(t_d *p, char dir)
{
	if (dir == 'E')
	{
		p->player->pdx = 0;
		p->player->pdy = 0;
		p->player->camera_y = 0.66;
	}
	else
	{
		p->player->pdx = -1;
		p->player->camera_y = -0.66;
		p->player->pdy = 0;
	}
	p->player->camera_x = 0;
}

void	init_player_direction(t_d *p, char dir)
{
	if (dir == 'N' || dir == 'S')
		set_north_south(p, dir);
	else
		set_east_west(p, dir);
}
