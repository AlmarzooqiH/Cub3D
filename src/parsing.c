/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthodi <mthodi@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 05:19:41 by hamad             #+#    #+#             */
/*   Updated: 2025/07/07 14:19:17 by mthodi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	struct_initialization(t_d *p)
{
	p->n = NULL;
	p->s = NULL;
	p->w = NULL;
	p->e = NULL;
	p->floor = NULL;
	p->ceiling = NULL;
	p->map = NULL;
	p->map_size = 0;
}

int	parse_input(const char *path, t_d *p)
{
	int		fd;

	struct_initialization(p);
	if (!validate_file_extension(path))
		return (free_p(p));
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (disp_err(FILE_DOESNT_EXSIST), free_p(p), 0);
	if (!validate_texture(fd, p))
		return (close(fd), free_p(p));
	if (!validate_color(fd, p))
		return (close(fd), free_p(p));
	if (!map_validator(path, p))
		return (close(fd), free_p(p));
	if (!map_checks(p))
		return (close(fd), free_p(p));
	p->map_width = ft_strlen(p->map[0]);
	p->map_height = p->map_size;
	p->player_width = (int)ceil((double)WIDTH / p->map_width);
	p->player_height = (int)ceil((double)HEIGHT / p->map_height);
	p->grid_width = p->player_width;
	p->grid_height = p->player_height;
	return (close(fd));
}
