/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthodi <mthodi@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 00:54:23 by mthodi            #+#    #+#             */
/*   Updated: 2025/07/09 15:19:15 by mthodi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*get_first_map_line(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL && !is_map_line(line))
	{
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}

int	dfs(char **map, int y, int x)
{
	if (map[y][x] == '1' || map[y][x] == 'X')
		return (1);
	map[y][x] = 'X';
	if (!dfs(map, y, x + 1))
		return (0);
	if (!dfs(map, y, x - 1))
		return (0);
	if (!dfs(map, y + 1, x))
		return (0);
	if (!dfs(map, y - 1, x))
		return (0);
	return (1);
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
