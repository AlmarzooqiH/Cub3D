/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:38:57 by hamalmar          #+#    #+#             */
/*   Updated: 2025/06/17 19:05:41 by hamalmar         ###   ########.fr       */
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

void	calc_texture(t_d *p, t_texture *t)
{
	t->proj = (WIDTH / 2.0f) / tanf(dtor(60.0f) / 2.0f);
	t->line_height = ((int)ceilf(t->proj / p->player->ray->dist)) / 2 + HEIGHT / 2;
	t->y_start = -((int)ceilf(t->proj / p->player->ray->dist)) / 2 + HEIGHT / 2;
	if (t->y_start < 0)
		t->y_start = 0;
	if (t->line_height >= HEIGHT)
		t->line_height = HEIGHT - 1;
	t->x_start = p->player->ray->ray_index * (WIDTH / N_RAYS);
	t->x_end = (p->player->ray->ray_index * (WIDTH / N_RAYS)) + (WIDTH / N_RAYS);
}

char	get_texture_pixel(t_texture *t, double tex_pos)
{
	int	tex_y;

	tex_y = (int)tex_pos & (t->height - 1);
	return (t->imgd[(t->height * tex_y) + t->x_start]);
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
	double		tex_pos;

	t = get_texture(p, p->player->ray->side);
	if (!t)
		return ;
	calc_texture(p, t);
	step = (1.0 * t->height) / t->line_height;
	tex_pos = (t->y_start - (HEIGHT / 2) + (t->line_height / 2)) * step;
	y = t->y_start;
	while (y < t->line_height)
	{
		x = t->x_start;
		while (x < t->x_end)
		{
			p->imgd[(y * p->sl) + (x * (p->bpp / 8))] = get_texture_pixel(t, tex_pos);
			tex_pos += step;
			x++;
		}
		y++;
	}
}

/** Function body
	t_texture	*t;
	float	proj;
	int		line_height; // y line_height aka line_height
	int		x;
	int		y; // y start

	t = get_texture(p, p->player->ray->side);
	if (!t)
		return ;
	proj = (WIDTH / 2.0f) / tanf(dtor(60.0f) / 2.0f);
	line_height = ((int)ceilf(proj / p->player->ray->dist)) / 2 + HEIGHT / 2;
	y = -((int)ceilf(proj / p->player->ray->dist)) / 2 + HEIGHT / 2;
	if (y < 0)
		y = 0;
	if (line_height >= HEIGHT)
		line_height = HEIGHT - 1;
	while (y <= line_height)
	{
		x = ray_index * (WIDTH / N_RAYS);
		while (x < (ray_index * (WIDTH / N_RAYS)) + (WIDTH / N_RAYS))
		{
			draw_texture(p, x, y);
			x++;
		}
		y++;
	}
 */
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
