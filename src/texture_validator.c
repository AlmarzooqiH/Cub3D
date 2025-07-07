/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_validator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthodi <mthodi@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 05:37:34 by hamad             #+#    #+#             */
/*   Updated: 2025/07/07 17:42:35 by mthodi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int process_texture_line(char **tokens, t_d *p, int *count)
{
    char *raw;
    char *ext;

    if (!tokens[1] || tokens[2])
        return (0);
    raw = ft_strtrim(tokens[1], " \t\n");
    if (!raw)
        return (0);
    ext = ft_strrchr(raw, '.');
    if (!ext || ft_strcmp(ext, ".xpm") != 1)
        return (free(raw), 0);
    if (ft_strcmp(tokens[0], "NO") && !p->n)
        p->n = init_texture(p->mlx, raw);
    else if (ft_strcmp(tokens[0], "SO") && !p->s)
        p->s = init_texture(p->mlx, raw);
    else if (ft_strcmp(tokens[0], "WE") && !p->w)
        p->w = init_texture(p->mlx, raw);
    else if (ft_strcmp(tokens[0], "EA") && !p->e)
        p->e = init_texture(p->mlx, raw);
    else
        return (0);
    if (!(p->n || p->s || p->w || p->e))
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

int	validate_texture(int fd, t_d *p)
{
	int		count;

	count = 0;
	if (!parse_texture_line(fd, p, &count))
		return (disp_err(ERROR_TEXTURE), 0);
	if (count != 4)
		return (disp_err(TEXTURE_MISSING), 0);
	return (1);
}
