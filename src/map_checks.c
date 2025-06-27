/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthodi <mthodi@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 00:53:59 by hamad             #+#    #+#             */
/*   Updated: 2025/06/27 03:48:55 by mthodi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_valid_chars(char **map)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			c = map[i][j];
			if (c != '0' && c != '1' && c != ' ' && !is_player(c))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_player(char **map, t_d *p)
{
	int	i;
	int	j;
	int	cnt;

	i = 0;
	cnt = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (is_player(map[i][j]))
			{
				cnt++;
				p->player->ppy = (double)i + 0.5;
				p->player->ppx = (double)j + 0.5;
				init_player_direction(p, map[i][j]);
				map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	return (cnt == 1);
}

/**
 * @brief Ensure the map’s outer boundary is all walls.
 * @param map    NULL-terminated array of rows.
 * @param height Number of rows in map[].
 * @return 1 if the border is fully walled, 0 otherwise.
 */
int	check_outer_walls(char **map, int height)
{
	int	width;
	int	i;
	int	j;

	width = ft_strlen(map[0]);
	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1'
			|| map[i][width - 1] != '1')
			return (0);
		i++;
	}
	j = 0;
	while (map[0][j] != '\0')
	{
		if (map[0][j] != '1'
			|| map[height - 1][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	map_checks(t_d *p)
{
	if (!is_valid_chars(p->map))
		return (disp_err(INVALID_CHARS), 0);
	if (!check_player(p->map, p))
		return (disp_err(INVALID_PLAYER), 0);
	if (!check_outer_walls(p->map, p->map_size))
		return (disp_err(MAP_NOT_CLOSED), 0);
	if (!dfs(p->map, (int)p->player->ppy, (int)p->player->ppx))
		return (disp_err(MAP_NOT_CLOSED), 0);
	return (1);
}
