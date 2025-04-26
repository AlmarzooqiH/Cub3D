/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthodi <mthodi@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 21:44:05 by mthodi            #+#    #+#             */
/*   Updated: 2025/04/26 17:50:56 by mthodi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
				&& map[i][j] != 'S' && map[i][j] != 'E' && map[i][j] != 'W'
				&& map[i][j] != ' ')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/**
 * @brief Initialize player direction based on the map character.
 * @param p The program struct.
 * @param dir The direction character (N, S, E, W).
 */
void	init_player_direction(t_d *p, char dir)
{
	if (dir == 'N')
	{
		p->player.dir_x = 0;
		p->player.dir_y = -1;
		p->player.plane_x = 0.66;
		p->player.plane_y = 0;
	}
	else if (dir == 'S')
	{
		p->player.dir_x = 0;
		p->player.dir_y = 1;
		p->player.plane_x = -0.66;
		p->player.plane_y = 0;
	}
	else if (dir == 'E')
	{
		p->player.dir_x = 1;
		p->player.dir_y = 0;
		p->player.plane_x = 0;
		p->player.plane_y = 0.66;
	}
	else if (dir == 'W')
	{
		p->player.dir_x = -1;
		p->player.dir_y = 0;
		p->player.plane_x = 0;
		p->player.plane_y = -0.66;
	}
}

/**
 * @brief Checks if there is exactly one player in the map.
 * @param map The 2D array containing the map.
 * @param p The program struct to store player position and direction.
 * @return 1 if there is exactly one player, 0 otherwise.
 */
int	check_player(char **map, t_d *p)
{
	int	i;
	int	j;
	int	player_count;

	player_count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
			{
				player_count++;
				p->player.x = j;
				p->player.y = i;
				init_player_direction(p, map[i][j]);
			}
			j++;
		}
		i++;
	}
	return (player_count == 1);
}

/**
 * @brief Gets the maximum line length in the map.
 * @param map The 2D array containing the map.
 * @return The maximum line length.
 */
int	get_max_line_length(char **map)
{
	int	i;
	int	len;
	int	max_len;

	max_len = 0;
	i = 0;
	while (map[i])
	{
		len = 0;
		while (map[i][len] && map[i][len] != '\n')
			len++;
		if (len > max_len)
			max_len = len;
		i++;
	}
	return (max_len);
}

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
 * @brief Checks if a position is valid (not exposed to outside).
 * // Check if position is surrounded by walls or other valid tiles
 * @param map The 2D array containing the map. (checking Left, Right, Up, Down ) in that order.
 * @param i The y-coordinate.
 * @param j The x-coordinate.
 * @param max_len The maximum line length in the map.
 * @return 1 if the position is valid, 0 otherwise.
 */
int	is_position_valid(char **map, int i, int j, int max_len)
{
	if (j == 0 || map[i][j - 1] == ' ' || map[i][j - 1] == '\0')
		return (0);
	if (j == max_len - 1 || map[i][j + 1] == ' ' || map[i][j + 1] == '\0')
		return (0);
	if (i == 0 || !map[i - 1] || j >= (int)ft_strlen(map[i - 1])
		|| map[i - 1][j] == ' ' || map[i - 1][j] == '\0')
		return (0);
	if (!map[i + 1] || j >= (int)ft_strlen(map[i + 1])
		|| map[i + 1][j] == ' ' || map[i + 1][j] == '\0')
		return (0);
	return (1);
}

/**
 * @brief Checks if the map is surrounded by walls.
 * @param map The 2D array containing the map.
 * @return 1 if the map is properly enclosed, 0 otherwise.
 */
int	is_map_closed(char **map)
{
	int	i;
	int	j;
	int	max_len;

	max_len = get_max_line_length(map);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			if ((map[i][j] == '0' || is_player(map[i][j])) &&
				!is_position_valid(map, i, j, max_len))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/**
 * @brief Free the map 2D array.
 * @param map The 2D array to free.
 */
void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

/**
 * @brief Main function to validate the map content.
 * @param fd The map file descriptor.
 * @param p The program struct.
 * @return 1 if the map is valid, 0 otherwise.
 */
int	validate_map(int fd, t_d *p)
{
	int		valid;
	char	**map;

	map = read_map(fd, p);
	if (!map)
		return (disp_err(MAP_EMPTY), 0);
	// valid = is_valid_chars(map) && check_player(map, p) && is_map_closed(map);
	valid = is_valid_chars(map) && check_player(map, p);
	if (!valid)
	{
		if (!is_valid_chars(map))
			disp_err(INVALID_CHARS);
		else if (!check_player(map, p))
			disp_err(INVALID_PLAYER);
		else if (!is_map_closed(map))
			disp_err(MAP_NOT_CLOSED);
		free_map(map);
		return (0);
	}
	p->map = map;
	return (1);
}
