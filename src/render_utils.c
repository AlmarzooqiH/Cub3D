/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 22:00:11 by marvin            #+#    #+#             */
/*   Updated: 2025/05/21 22:00:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief Set a pixel in the image buffer.
 * @param p The program struct.
 * @param x The X position of the pixel.
 * @param y The Y position of the pixel.
 * @param color The pixel color that we will plot.
 * @return void.
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
 * @param c The color struct that contains the rgb values.
 * @return The color acording to minilibx standards. (See man mlx_pixel_put.3)
 */
int	rgb_to_int(t_color *c)
{
	return ((c->r << 16) | (c->g << 8) | c->b);
}
/**
 * @brief This function will clear the image buffer before re-rendering.
 * @param p The program struct.
 * @note As you can see it is still implemented.
 */
void	clear_image_buffer(t_d *p)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x  < WIDTH)
		{
			put_pixel(p, x, y, 0);
			x++;
		}
		y++;
	}
}
