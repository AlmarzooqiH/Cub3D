/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthodi <mthodi@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 00:50:24 by mthodi            #+#    #+#             */
/*   Updated: 2025/07/09 14:52:38 by mthodi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief Copy non-space tiles from orig into the normalized map.
 */
void	copy_map_contents(char **orig, char **norm, int height, int width)
{
	int		i;
	int		j;
	size_t	len;

	(void) width;
	i = 0;
	while (i < height)
	{
		len = ft_strlen(orig[i]);
		j = 0;
		while (j < (int)len)
		{
			if (orig[i][j] != ' ')
				norm[i][j] = orig[i][j];
			j++;
		}
		i++;
	}
}

/**
 * @brief Fill the map array with map_size lines, starting from first_line.
 */
char	**fill_map_array(int fd, int map_size, char *first_line)
{
	int		i;
	char	*line;
	char	**map;

	map = malloc(sizeof(char *) * (map_size + 1));
	if (!map)
		return (free(first_line), NULL);
	i = 0;
	line = first_line;
	while (i < map_size && line != NULL && is_map_line(line))
	{
		strip_newline(line);
		map[i++] = line;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	if (line)
		free(line);
	return (map);
}

/**
 * @brief Read exactly map_size lines into a char**, skipping headers.
 */
char	**read_map_lines(const char *path, int map_size)
{
	int		fd;
	char	*first_line;
	char	**map;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	first_line = get_first_map_line(fd);
	if (!first_line)
		return (close(fd), NULL);
	map = fill_map_array(fd, map_size, first_line);
	close(fd);
	return (map);
}

/**
 * @brief Turn a ragged/or-spaced map into a perfect rectangle of walls+tiles.
 */
char	**make_map_square(char **orig)
{
	int		height;
	int		width;
	char	**norm;

	compute_dimensions(orig, &height, &width);
	norm = allocate_norm_map(height, width);
	if (!norm)
		return (NULL);
	copy_map_contents(orig, norm, height, width);
	return (norm);
}

int	map_validator(const char *path, t_d *p)
{
	int		map_size;
	char	**raw;
	char	**square;

	map_size = count_map_lines(path);
	if (map_size <= 0)
		return (disp_err(MAP_EMPTY), 0);
	raw = read_map_lines(path, map_size);
	if (raw == NULL)
		return (disp_err(MAP_EMPTY), 0);
	square = make_map_square(raw);
	free_split(raw);
	if (square == NULL)
		return (0);
	p->map = square;
	p->map_size = map_size;
	p->map_height = map_size;
	p->map_width = ft_strlen(square[0]);
	return (1);
}
