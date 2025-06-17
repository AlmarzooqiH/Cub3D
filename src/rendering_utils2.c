/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:38:57 by hamalmar          #+#    #+#             */
/*   Updated: 2025/06/18 02:43:37 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief This function will return the eculidian distance from the player
 * to the wall.
 * @param player The player struct.
 * @return The eculidian distance.
 */
float	get_distance(t_player *player)
{
	float	dx;
	float	dy;

	dx = player->ray->mapx - player->ppx;
	dy = player->ray->mapy - player->ppy;
	return (sqrtf(dx * dx + dy * dy));
}

/**
 * @brief This function will draw the walls in 3d.
 * @param p The program struct.
 * @return void
 */
void	draw_wall(t_d *p)
{
	t_texture	*t;
	int			x;
	int			y;
	double		step;

	t = get_texture(p, p->player->ray->side);
	if (!t)
		return ;
	calc_texture(p, t);
	step = (1.0 * t->height) / t->line_height;
	t->tex_pos = (t->y_start - (HEIGHT / 2) + (t->line_height / 2)) * step;
	y = t->y_start;
	while (y < t->line_height)
	{
		x = t->x_start;
		while (x < t->x_end)
		{
			copy_pixels(p, t, x, y);
			x++;
		}
		t->tex_pos += step;
		y++;
	}
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
			r->axis = VERTICAL;
		}
		else
		{
			r->sdy += r->ddy;
			r->mapy += r->step_y;
			r->axis = HORIZONTAL;
		}
		if (!bound_check(p) || p->map[r->mapy][r->mapx] == '1')
			r->hit = 1;
	}
	r->dist = get_distance(p->player);
	r->side = get_side(p->player);
	draw_wall(p);
	draw_ray(p);
}

/**
 * @brief D(egrees) To R(adinas)
 * @param degrees The degree that you want to convert to radians.
 * @return The converted degree to radians.
 */
float	dtor(float degree)
{
	return (degree * (M_PI / 180.0f));
}

/**
 * @brief This function will raycast to the player FOV.
 * @param p The program struct.
 * @return void.
 */
void	raycast_in_2d(t_d *p)
{
	int		i;
	float	sa;
	float	ea;
	float	stp;
	float	ang;

	sa = atan2f(p->player->pdy, p->player->pdx) - dtor(30.0f);
	ea = atan2f(p->player->pdy, p->player->pdx) + dtor(30.0f);
	stp = (ea - sa) / (N_RAYS - 1);
	ang = sa;
	i = 0;
	while (i < N_RAYS)
	{
		update_ray(p->player, ang);
		p->player->ray->angle = ang;
		p->player->ray->ray_index = i;
		dda(p);
		ang += stp;
		i++;
	}
}
