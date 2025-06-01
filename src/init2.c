/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 21:07:52 by hamalmar          #+#    #+#             */
/*   Updated: 2025/06/01 21:07:52 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_ray	*init_ray(t_d *p)
{
	t_ray	*r;

	r = (t_ray *)ft_calloc(1, sizeof(t_ray));
	if (!r)
		return (disp_err(FTIR), NULL);
	r->hit = 0;
	r->mapx = (int)p->player->ppx;
	r->mapy = (int)p->player->ppy;
	r->rdx = p->player->pdx;
	r->rdy = p->player->pdy;
	r->rpx = p->player->ppx;
	r->rpy = p->player->ppy;
	get_inital_dist(r);
	get_steps(r);
	return (r);
}
