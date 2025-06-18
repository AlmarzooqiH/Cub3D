/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 00:21:07 by hamalmar          #+#    #+#             */
/*   Updated: 2025/06/16 00:21:07 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/cub3d.h"

/**
 * @brief This function will check if the ray is in map bounds or not.
 * @param p The program structure.
 * @return 1 if within bounds, 0 otherwise.
 */
int	bound_check(t_d *p)
{
	return (p->player->ray->mapx >= 0 && p->player->ray->mapy >= 0
		&& (size_t)p->player->ray->mapx < p->map_width
		&& (size_t)p->player->ray->mapy < p->map_height);
}

/**
 * @brief This function will determine which side has the ray has hit.
 * @param p The player.
 * @return The direction that was hit (EAST, WEST, SOUTH, NORTH) Checkout the
 * side enum.
 */
int	get_side(t_player *p)
{
	if (p->ray->axis == VERTICAL)
	{
		if (p->ray->rdx > 0)
			return (WEST);
		return (EAST);
	}
	if (p->ray->rdy > 0)
		return (NORTH);
	return (SOUTH);
}

/**
 * @brief This function will check which sided was hit and will return the cor
 * rosponding texture that was stored earlier in @param p.
 * @param p The program struct.
 * @param side The direction that was hit (EAST, WEST, SOUTH, NORTH) Checkout
 * the side enum.
 * @return The texture of the wall the was hit.
 */
t_texture	*get_texture(t_d *p, int side)
{
	if (side == EAST)
		return (p->e);
	else if (side == WEST)
		return (p->w);
	else if (side == SOUTH)
		return (p->s);
	else if (side == NORTH)
		return (p->n);
	return (NULL);
}

void	calc_texture(t_d *p, t_texture *t)
{
	t->proj = (WIDTH / 2.0f) / tanf(dtor(60.0f) / 2.0f);
	t->line_height = ((int)ceilf(t->proj / p->player->ray->dist))
		/ 2 + HEIGHT / 2;
	t->y_start = -((int)ceilf(t->proj / p->player->ray->dist))
		/ 2 + HEIGHT / 2;
	if (t->y_start < 0)
		t->y_start = 0;
	if (t->line_height >= HEIGHT)
		t->line_height = HEIGHT - 1;
	t->x_start = p->player->ray->ray_index * (WIDTH / N_RAYS);
	if (p->player->ray->ray_index == N_RAYS - 1)
		t->x_end = WIDTH;
	else
		t->x_end = t->x_start + (WIDTH / N_RAYS);
	if (p->player->ray->axis == HORIZONTAL)
		t->wall_x = p->player->ppy
			+ (p->player->ray->dist * p->player->ray->rdy);
	else if (p->player->ray->axis == VERTICAL)
		t->wall_x = p->player->ppx
			+ (p->player->ray->dist * p->player->ray->rdx);
	t->wall_x -= floor(t->wall_x);
	t->tex_x = (int)(t->wall_x * t->width);
}

void	copy_pixels(t_d *p, t_texture *t, int x, int y)
{
	int				i;
	int				tex_y;
	unsigned char	*tex_pixel;
	unsigned char	*screen_pixel;

	tex_y = (int)t->tex_pos;
	if (tex_y < 0)
		tex_y = 0;
	if (tex_y >= t->height)
		tex_y = t->height - 1;
	tex_pixel = (unsigned char *)&t->imgd[(tex_y * t->sl)
		+ ((int)t->tex_x * (t->bpp / 8))];
	screen_pixel = (unsigned char *)&p->imgd[(y * p->sl) + (x * (p->bpp / 8))];
	i = 0;
	while (i < (t->bpp / 8))
	{
		screen_pixel[i] = tex_pixel[i];
		i++;
	}
}
