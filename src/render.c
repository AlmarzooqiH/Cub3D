/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:06:48 by mthodi            #+#    #+#             */
/*   Updated: 2025/06/09 23:10:37 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief This function will render the player in his proper position.
 * @param p The program struct.
 * @return void.
 * @note If you see here we subtract - 1 from the ppx and ppy because the NULL
 * termination.
 */
void	render_player(t_d *p)
{
	int	i;
	int	j;

	i = 0;
	while (i < p->grid_height)
	{
		j = 0;
		while (j < p->grid_width)
		{
			put_pixel(p, j + ((p->player->ppx - 1) * p->grid_width), i
				+ ((p->player->ppy - 1) * p-> grid_height),
				ctoi(p->player->color));
			j++;
		}
		i++;
	}
}

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
	int	i;
	int	j;

	i = 0;
	while (i < p->grid_height - 1)
	{
		j = 0;
		while (j < p->grid_width - 1)
		{
			put_pixel(p, j + (x * p->grid_width), i + (y * p->grid_height),
				ctoi(c));
			j++;
		}
		i++;
	}
}

/**
 * @brief This function will render the map.
 * @param p The program struct.
 * @return void.
 */
void	render_map(t_d *p)
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

/**
 * @brief This function should draw a ray from the player position to the wall
 * after performing the dda algorthim.
 * @param p The program struct.
 * @return void.
 */
void	draw_ray(t_d *p)
{
	float	x;
	float	y;
	float	dx;
	float	dy;
	int		steps;

	x = p->player->ppx * p->grid_width;
	y = p->player->ppy * p->grid_height;
	dx = p->player->ray->mapx * p->grid_width - x;
	dy = p->player->ray->mapy * p->grid_height - y;
	steps = (int)fmaxf(fabsf(dx), fabsf(dy));
	if (steps == 0)
		return ;
	dx /= (float)steps;
	dy /= (float)steps;
	while (steps--)
	{
		put_pixel(p, (int)x, (int)y, ctoi(p->player->ray->color));
		x += dx;
		y += dy;
	}
}

/**
 * @brief This function will raycast to the player FOV.
 * @param p The program struct.
 * @return void.
 */
void	raycast_in_2d(t_d *p)
{
	float	start_angle;
	float	end_angle;
	float	step;
	float	angle;
	int		i;

	start_angle = atan2(p->player->pdy, p->player->pdx)
		- (30.0f * (M_PI / 180.0f));
	end_angle = atan2(p->player->pdy, p->player->pdx)
		+ (30.0f * (M_PI / 180.0f));
	step = (end_angle - start_angle) / (N_RAYS - 1);
	angle = start_angle;
	i = 0;
	while (i < N_RAYS)
	{
		update_ray(p->player, angle);
		dda(p);
		angle += step;
		i++;
	}
}
