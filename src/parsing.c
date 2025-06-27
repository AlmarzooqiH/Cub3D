/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthodi <mthodi@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 05:19:41 by hamad             #+#    #+#             */
/*   Updated: 2025/06/27 17:17:40 by mthodi           ###   ########.fr       */
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

void	parse_input(const char *path, t_d *p)
{
	struct_initialization(p);
	if (!validate_file_extension(path))
		exit(EXIT_FAILURE);
	if (!validate_texture(path, p))
		exit(EXIT_FAILURE);
	if (!validate_color(path, p))
		exit(EXIT_FAILURE);
	if (!map_validator(path, p))
		exit(EXIT_FAILURE);
	if (!map_checks(p))
		exit(EXIT_FAILURE);
	p->map_width = ft_strlen(p->map[0]);
	p->map_height = p->map_size;
	p->player_width = (int)ceil((double)WIDTH / p->map_width);
	p->player_height = (int)ceil((double)HEIGHT / p->map_height);
}
