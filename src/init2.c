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

t_color	*init_ray_color(void)
{
	t_color	*new_c;
	char	*color;

	color = ft_strdup(RAY_COLOR);
	if (!color)
		return (NULL);
	new_c = init_color(color);
	if (!new_c)
		return (free(color), NULL);
	return (new_c);
}

t_ray	*init_ray(t_d *p)
{
	t_ray	*r;

	r = (t_ray *)ft_calloc(1, sizeof(t_ray));
	if (!r)
		return (disp_err(FTIR), NULL);
	r->color = init_ray_color();
	if (!r->color)
		return (free(r), disp_err(FTIC), NULL);
	r->hit = 0;
	r->mapx = (int)p->player->ppx;
	r->mapy = (int)p->player->ppy;
	r->rdx = p->player->pdx;
	r->rdy = p->player->pdy;
	r->rpx = p->player->ppx;
	r->rpy = p->player->ppy;
	r->dist = 0;
	r->angle = p->player->angle;
	r->side = -1;
	r->ray_index = 0;
	get_inital_dist(r);
	get_steps(r);
	return (r);
}

/**
 * @brief This function will initalize the keys.
 * @param p The player.
 * @note I created this function due to norminette, i was exceeding 25 lines 😓
 */
void	init_keys(t_player *p)
{
	p->w_pressed = 0;
	p->a_pressed = 0;
	p->s_pressed = 0;
	p->d_pressed = 0;
	p->lk_pressed = 0;
	p->rk_pressed = 0;
}
