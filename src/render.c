/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:06:48 by mthodi            #+#    #+#             */
/*   Updated: 2025/05/21 22:49:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief This function will draw a grid on the screen.
 * @param p This holds the program data.
 * @param x Current X position on the screen.
 * @param y Current Y position on the screen.
 * @param c The color that we want the grid to be.
 * @return Void
 */
void	draw_grid(t_d *p, int x, int y, t_color *c)
{
	size_t	i;
	size_t	j;
	size_t	grid_width;
	size_t	grid_height;

	grid_width = (int)ceil(((double)WIDTH) / ((double)p->map_width));
	grid_height = (int)ceil(((double)HEIGHT) / ((double)p->map_height));
	i = 0;
	while (i < grid_height)
	{
		j = 0;
		while (j < grid_width)
		{
			put_pixel(p, j + (x * grid_width), i + (y * grid_height),
				rgb_to_int(c));
			j++;
		}
		i++;
	}
}

void	draw_player(t_d *p)
{
	int	i;
	int	j;
	int	map_width;
	int	map_height;

	map_width = (int)ceil(((double)WIDTH) / ((double)p->map_width));
	map_height = (int)ceil(((double)HEIGHT) / ((double)p->map_height));
	printf("map_width: %d\n", map_width);
	printf("map_height: %d\n", map_height);
	i = 0;
	while (i < map_width)
	{
		j = 0;
		while (j < map_width)
		{
			put_pixel(p, (j - p->player->ppx) + (p->player->ppx * map_width), (i - p->player->ppy) + (p->player->ppy
					* map_height), rgb_to_int(p->player->color));
			j++;
		}
		i++;
	}
}

/**
 * @brief Render a single frame: call ceiling, call floor, and call raycasting.
 */
void	render_frame(t_d *p)
{
	int	i;
	int	j;

	i = 0;
	while (p->map[i])
	{
		j = 0;
		while (p->map[i][j] != '\0')
		{
			if (p->map[i][j] == '1')
				draw_grid(p, j, i, p->ceiling);
			else
				draw_grid(p, j, i, p->floor);
			j++;
		}
		i++;
	}
}
