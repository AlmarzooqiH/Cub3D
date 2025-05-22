/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 05:37:34 by hamad             #+#    #+#             */
/*   Updated: 2025/05/22 15:34:05 by hamalmar         ###   ########.fr       */
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
		pr->player->ppy--;
	else if (key_num == A)
		pr->player->ppx--;
	else if (key_num == S)
		pr->player->ppy++;
	else if (key_num == D)
		pr->player->ppx++;
	else if (key_num == LK)
	{
		pr->player->ppx -= sin(pr->player->ppx);
		pr->player->ppy -= cos(pr->player->ppy);
	}
	else if (key_num == RK)
	{
		pr->player->ppx += sin(pr->player->ppx);
		pr->player->ppy += cos(pr->player->ppy);
	}
	game_loop(pr);
	return (key_num);
}
