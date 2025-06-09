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

void	update_ray(t_player *p, float angle)
{
	p->ray->hit = 0;
	p->ray->mapx = (int)p->ppx;
	p->ray->mapy = (int)p->ppy;
	p->ray->rdx = cos(angle);
	p->ray->rdy = sin(angle);
	p->ray->rpx = p->ppx;
	p->ray->rpy = p->ppy;
	get_inital_dist(p->ray);
	get_steps(p->ray);
}
