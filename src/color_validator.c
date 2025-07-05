/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_validator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthodi <mthodi@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 00:53:59 by hamad             #+#    #+#             */
/*   Updated: 2025/06/28 13:16:10 by mthodi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	process_color_line(char **tokens, t_d *p, int *count)
{
	if (!tokens[1])
		return (0);
	if (!p->floor && ft_strcmp(tokens[0], "F"))
		p->floor = init_color(ft_strtrim(tokens[1], "\n"));
	else if (!p->ceiling && ft_strcmp(tokens[0], "C"))
		p->ceiling = init_color(ft_strtrim(tokens[1], "\n"));
	else
		return (0);
	(*count)++;
	return (1);
}

int	parse_color_lines(int fd, t_d *p, int *count)
{
	char	*line;
	char	**tokens;

	line = get_next_line(fd);
	while (line != NULL && *count < 2)
	{
		if (line[0] != '\n' && line[0] != '\0')
		{
			tokens = ft_split(line, ' ');
			if (!tokens || !process_color_line(tokens, p, count))
				return (free_split(tokens), free(line), 0);
			free_split(tokens);
		}
		if (*count == 2)
			return (free(line), 1);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (1);
}

int	validate_color(int fd, t_d *p)
{
	int		count;

	count = 0;
	if (!parse_color_lines(fd, p, &count))
		return (disp_err(ERROR_COLOR), close(fd), 0);
	if (count != 2)
		return (disp_err(COLOR_MISSING), 0);
	return (1);
}
