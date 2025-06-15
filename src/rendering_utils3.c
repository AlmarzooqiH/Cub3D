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
