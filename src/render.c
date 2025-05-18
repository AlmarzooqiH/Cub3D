/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:06:48 by mthodi            #+#    #+#             */
/*   Updated: 2025/05/18 16:20:46 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief Set a pixel in the image buffer.
 */
void	put_pixel(t_d *p, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = p->imgd + (y * p->sl + x * (p->bpp / 8));
	*(unsigned int *) dst = color;
}

/**
 * @brief Convert RGB components to a single integer color.
 */
int	rgb_to_int(t_color *c)
{
	return ((c->r << 16) | (c->g << 8) | c->b);
}

void	floor_render(t_d *p)
{
	int	x;
	int	y;

	y = HEIGHT / 2;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel(p, x, y, rgb_to_int(p->floor));
			x++;
		}
		y++;
	}
}

/**
 * @brief Render the ceiling.
 */
void	ceiling_render(t_d *p)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT / 2)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel(p, x, y, rgb_to_int(p->ceiling));
			x++;
		}
		y++;
	}
}

/**
 * @brief Render a single frame: call ceiling, call floor, and call raycasting.
 */
void	render_frame(t_d *p)
{
	// ceiling_render(p);
	// floor_render(p);
	// raycasting(p);
	int i = 0, j = 0;
	while (p->map[i])
	{
		j = 0;
		while (p->map[i][j] != '\0')
		{
			if (p->map[i][j] == '1'){
				put_pixel(p, j, i, rgb_to_int(p->ceiling));
				put_pixel(p, j+1, i+1, rgb_to_int(p->ceiling));
				put_pixel(p, j+1, i+2, rgb_to_int(p->ceiling));
				put_pixel(p, j+1, i+3, rgb_to_int(p->ceiling));
				put_pixel(p, j+1, i+4, rgb_to_int(p->ceiling));
			}
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
}
