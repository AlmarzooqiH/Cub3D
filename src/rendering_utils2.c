/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:38:57 by hamalmar          #+#    #+#             */
/*   Updated: 2025/06/11 22:03:23 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

float	get_distance(t_player *p)
{
	float	dx;
	float	dy;

	dx = p->ray->mapx - p->ppx;
	dy = p->ray->mapy - p->ppy;
	return ((dx * dx) + (dy * dy));
}

/**
 * @brief This function will perform the Digital Differential Analysis
 * algorthim then it will draw the ray acordingly.
 * @param The program structure.
 * @return void.
 */
void	dda(t_d *p)
{
	t_ray	*r;

	r = p->player->ray;
	while (!r->hit)
	{
		if (r->sdx < r->sdy)
		{
			r->sdx += r->ddx;
			r->mapx += r->step_x;
		}
		else
		{
			r->sdy += r->ddy;
			r->mapy += r->step_y;
		}
		if (p->map[r->mapy][r->mapx] == '1')
		{
			r->hit = 1;
			r->dist = get_distance(p->player);
			draw_ray(p);
		}
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
