/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthodi <mthodi@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 17:29:23 by hamalmar          #+#    #+#             */
/*   Updated: 2025/06/26 19:42:08 by mthodi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
