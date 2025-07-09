/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthodi <mthodi@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 17:29:23 by hamalmar          #+#    #+#             */
/*   Updated: 2025/07/09 13:31:44 by mthodi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	strip_newline(char *line)
{
	size_t	len;

	if (!line)
		return ;
	len = ft_strlen(line);
	while (len > 0 && (line[len - 1] == '\n' || line[len - 1] == '\r'))
	{
		line[len - 1] = '\0';
		len--;
	}
}

int	is_map_line(char *line)
{
	int		i;
	char	c;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		c = line[i];
		if (c != ' ' && c != '0' && c != '1' && !is_player(c))
			return (0);
		i++;
	}
	return (i > 0);
}

int	count_map_lines(const char *path)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line && !is_map_line(line))
	{
		free(line);
		line = get_next_line(fd);
	}
	count = 0;
	while (line && is_map_line(line))
	{
		free(line);
		count++;
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close(fd);
	return (count);
}

/**
 * @brief Compute height and width of the raw map.
 */
void	compute_dimensions(char **orig, int *height, int *width)
{
	int		i;
	size_t	len;

	*height = 0;
	while (orig[*height] != NULL)
		(*height)++;
	*width = 0;
	i = 0;
	while (i < *height)
	{
		len = ft_strlen(orig[i]);
		if ((int)len > *width)
			*width = (int)len;
		i++;
	}
}

/**
 * @brief Allocate a new normalized map filled entirely with '1's.
 */
char	**allocate_norm_map(int height, int width)
{
	int		i;
	char	**norm;

	norm = malloc(sizeof(char *) * (height + 1));
	if (!norm)
		return (NULL);
	i = 0;
	while (i < height)
	{
		norm[i] = malloc(width + 1);
		if (!norm[i])
		{
			while (i-- > 0)
				free(norm[i]);
			free(norm);
			return (NULL);
		}
		ft_memset(norm[i], '1', width);
		norm[i][width] = '\0';
		i++;
	}
	norm[height] = NULL;
	return (norm);
}
