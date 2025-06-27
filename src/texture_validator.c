/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_validator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthodi <mthodi@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 05:37:34 by hamad             #+#    #+#             */
/*   Updated: 2025/06/27 20:58:05 by mthodi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	process_texture_line(char **tokens, t_d *p, int *count)
{
	if (!p->n && ft_strcmp(tokens[0], "NO"))
		p->n = init_texture(p->mlx, ft_strtrim(tokens[1], "\n"));
	else if (!p->s && ft_strcmp(tokens[0], "SO"))
		p->s = init_texture(p->mlx, ft_strtrim(tokens[1], "\n"));
	else if (!p->w && ft_strcmp(tokens[0], "WE"))
		p->w = init_texture(p->mlx, ft_strtrim(tokens[1], "\n"));
	else if (!p->e && ft_strcmp(tokens[0], "EA"))
		p->e = init_texture(p->mlx, ft_strtrim(tokens[1], "\n"));
	else
		return (0);
	(*count)++;
	return (1);
}

int	parse_texture_line(int fd, t_d *p, int *count)
{
	char	*line;
	char	**tokens;

	line = get_next_line(fd);
	while (line != NULL && *count < 4)
	{
		if (line[0] != '\n' && line[0] != '\0')
		{
			tokens = ft_split(line, ' ');
			if (!tokens || !process_texture_line(tokens, p, count))
			return (free_split(tokens), free(line), 0);
			free_split(tokens);
		}
		if (*count == 4)
			return (free(line), 1);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (1);
}

int	validate_texture(const char *path, t_d *p)
{
	int		fd;
	int		count;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (disp_err(FILE_DOESNT_EXSIST), 0);
	count = 0;
	if (!parse_texture_line(fd, p, &count))
		return (disp_err(ERROR_TEXTURE), close(fd), 0);
	close(fd);
	if (count != 4)
		return (disp_err(TEXTURE_MISSING), 0);
	return (1);
}
