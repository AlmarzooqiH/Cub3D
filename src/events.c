/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 05:37:34 by hamad             #+#    #+#             */
/*   Updated: 2025/05/23 16:15:47 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	key_hook(int key_num, void *p)
{
	t_d	*pr;

	pr = (t_d *)p;
	if (key_num == ESC)
		free_p(pr);
	else if (key_num == W)
		pr->player->ppy -= MOVEMENT_SPEED;
	else if (key_num == A)
		pr->player->ppx -= MOVEMENT_SPEED;
	else if (key_num == S)
		pr->player->ppy += MOVEMENT_SPEED;
	else if (key_num == D)
		pr->player->ppx += MOVEMENT_SPEED;
	else if (key_num == LK)
	{
		pr->player->angle -= ROTATION_SPEED;
		pr->player->rotate = 1;
	}
	else if (key_num == RK)
	{
		pr->player->angle += ROTATION_SPEED;
		pr->player->rotate = 1;
	}
	game_loop(pr);
	return (key_num);
}
