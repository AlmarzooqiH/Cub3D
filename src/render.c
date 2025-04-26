/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthodi <mthodi@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:06:48 by mthodi            #+#    #+#             */
/*   Updated: 2025/04/26 17:47:03 by mthodi           ###   ########.fr       */
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
	ceiling_render(p);
	floor_render(p);
	// raycasting(p);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
}
