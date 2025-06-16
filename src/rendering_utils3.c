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

/**
 * @brief This function will be responsible onto drawing the texture on the wa
 * ll.
 * @param p The program struct.
 * @param x The X pixel position.
 * @param y The Y pixel position.
 * @return void
 * @note This function is very primitive and will be changed later on.
 */
void	draw_texture(t_d *p, int x, int y)
{
	t_texture	*t;
	int			i_offset;
	int			t_offset;

	t = get_texture(p, p->player->ray->side);
	if (!t)
		return ;
	i_offset = (p->sl * y) + ((p->bpp / 8) * x);
	t_offset = (t->sl * y) + ((t->bpp / 8) * x);
	p->imgd[i_offset] = t->imgd[t_offset];
}
