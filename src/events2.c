/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 22:48:07 by hamalmar          #+#    #+#             */
/*   Updated: 2025/06/01 22:48:07 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief This function will check for wall collisions, if there was a wall co
 * llision it won't update the player position else it will.
 * @param p The program struct.
 * @param new_x The player new X position.
 * @param new_y The player new Y position.
 * @return void
 */
void	update_pos(t_d *p, float new_x, float new_y)
{
	if (p->map[(int)new_y][(int)new_x] != '1')
	{
		p->player->ppx = new_x;
		p->player->ppy = new_y;
	}
}

/**
 * @brief This function will update the ray data.
 * @param p The player.
 * @param angle The angle in radians that will be used to detemine the ray dir
 * ection.
 * @return void
 */
void	update_ray(t_player *p, float angle)
{
	p->ray->hit = 0;
	p->ray->mapx = (int)p->ppx;
	p->ray->mapy = (int)p->ppy;
	p->ray->rdx = cos(angle);
	p->ray->rdy = sin(angle);
	p->ray->rpx = p->ppx;
	p->ray->rpy = p->ppy;
	p->ray->side = -1;
	get_inital_dist(p->ray);
	get_steps(p->ray);
}
