/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthodi <mthodi@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 00:53:59 by hamad             #+#    #+#             */
/*   Updated: 2025/04/26 17:45:57 by mthodi           ###   ########.fr       */
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
 * @brief Counts the number of lines in the map.
 * @param fd The map file descriptor.
 * @param first_line The first line of the map (already read).
 * @return Number of lines in the map.
 * @note This function seeks back to the position after the first line.
 */
int	count_map_lines(int fd, char *first_line)
{
	int		current_pos;
	int		count;
	char	*line;

	(void)first_line;
	count = 1;
	current_pos = lseek(fd, 0, SEEK_CUR);
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	lseek(fd, current_pos, SEEK_SET);
	return (count);
}

/**
 * @brief Reads the map from the file descriptor and stores it in a 2D array.
 * @param fd The map file descriptor.
 * @param p The program struct.
 * @return 2D array containing the map. NULL if an error occurred.
 * @note This function skips empty lines before the map and reads until EOF.
 */
char	**read_map(int fd, t_d *p)
{
	char	*line;
	char	**map;
	int		i;
	int		map_size;

	map_size = 0;
	line = get_next_line(fd);
	while (line && (line[0] == '\n' || line[0] == '\0'))
	{
		free(line);
		line = get_next_line(fd);
	}
	if (!line)
		return (NULL);
	map_size = count_map_lines(fd, line);
	if (map_size <= 0)
		return (free(line), NULL);
	map = malloc(sizeof(char *) * (map_size + 1));
	if (!map)
		return (free(line), NULL);
	i = 0;
	map[i++] = line;
	while (i < map_size)
		map[i++] = get_next_line(fd);
	map[i] = NULL;
	p->map_size = map_size;
	return (map);
}
