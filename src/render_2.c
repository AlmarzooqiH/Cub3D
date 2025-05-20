/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 21:29:11 by marvin            #+#    #+#             */
/*   Updated: 2025/05/18 21:29:11 by marvin           ###   ########.fr       */
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

void	clear_image_buffer(t_d *p)
{
	(void) p;
	// ft_memset(p->imgd, 0, ft_strlen(p->imgd));
	// mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
}

void	draw_player(t_d *p)
{
	size_t	i;
	size_t	j;
	size_t	square_width;
	size_t	map_relative_width;
	size_t	map_relative_height;


	map_relative_width = (int)ceil(((double)WIDTH) / ((double)p->map_width));
	map_relative_height = (int)ceil(((double)HEIGHT) / ((double)p->map_height));
	square_width = (size_t)(ceil((double)WIDTH / p->map_width));
	i = p->player->ppy;
	while (i < square_width)
	{
		j = p->player->ppx;
		while (j < square_width)
		{
			put_pixel(p, j + (p->player->ppx * map_relative_width), i + (p->player->ppy * map_relative_height), rgb_to_int(p->player->color));
			j++;
		}
		i++;
	}
}
