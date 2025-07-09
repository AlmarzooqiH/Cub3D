/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthodi <mthodi@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 00:53:59 by hamad             #+#    #+#             */
/*   Updated: 2025/07/09 14:50:50 by mthodi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief This function will check if prefix in s.
 * @param	s The strnig that we want to check the prefix.
 * @param	prefix The prefix that we want to check in s.
 * @return	1 if prefix is in s. 0 othrewise.
 */
int	ft_isprefix(const char *s, const char *prefix)
{
	size_t	i;

	if (!s || !prefix || (ft_strlen(s) < ft_strlen(prefix)))
		return (0);
	i = 0;
	while ((s[i] != '\0' && prefix[i] != '\0') && prefix[i] == s[i])
		i++;
	return (!prefix[i]);
}

/**
 * @brief	This function will check if the string has the correct suffix.
 * @param	s The string we want to check.
 * @param	suffix The suffix we want to check
 * @return 1 if the file name is valid, 0 otherwise.
 */
int	is_suffix(const char *s, const char *suffix)
{
	int	i;
	int	j;

	if (!s || !suffix || (ft_strlen(s) < ft_strlen(suffix)))
		return (0);
	i = 0;
	while (s[i] != '\0' && s[i] != suffix[0])
		i++;
	if (s[i] == '\0')
		return (0);
	j = 0;
	while ((s[i] != '\0' && suffix[j] != '\0') && (s[i] == suffix[j]))
	{
		i++;
		j++;
	}
	return (s[i] == '\0' && suffix[j] == '\0');
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
				p->player->ppx = j + 1;
				p->player->ppy = i + 1;
				init_player_direction(p, map[i][j]);
			}
			j++;
		}
		i++;
	}
	return (player_count == 1);
}

int	validate_parsed_map(const char *path, t_d *p)
{
	if (!map_validator(path, p))
		return (0);
	if (!map_checks(p))
		return (0);
	return (1);
}
