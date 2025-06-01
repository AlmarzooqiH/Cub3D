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
int	ctoi(t_color *c)
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
		while (x < WIDTH)
		{
			put_pixel(p, x, y, 0);
			x++;
		}
		y++;
	}
}

/**
 * @brief This function will calculate the inital distance that we need to
 * travel.
 * @param ddx The pointer to the variable that we want to assign the delta 
 * distance X.
 * @param ddy The pointer to the variable that we want to assign the delta
 * distance Y.
 * @param rdx The ray X direction.
 * @param rdy The ray Y direction.
 * @note If rdx or rdy are 0 we will asign a big number to stepx,y to avoid 
 * dividing by 0.
 */
void	get_inital_dist(t_ray *r)
{
	if (r->rdx == 0.0f)
		r->ddx = 1e5f;
	else
		r->ddx = fabsf(1.0f / r->rdx);
	if (r->rdy == 0.0f)
		r->ddy = 1e5f;
	else
		r->ddy = fabsf(1.0f / r->rdy);
}

void	get_steps(t_ray *r)
{
	if (r->rdx < 0)
	{
		r->step_x = -1;
		r->sdx = (r->rpx - r->mapx) * r->ddx;
	}
	else
	{
		r->step_x = 1;
		r->sdx = (r->mapx + 1.0f - r->rpx) * r->ddx;
	}
	if (r->rdy < 0)
	{
		r->step_y = -1;
		r->sdy = (r->rpy - r->mapy) * r->ddy;
	}
	else
	{
		r->step_y = 1;
		r->sdy = (r->mapy + 1.0f - r->rpy) * r->ddy;
	}
}
