/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 05:37:34 by hamad             #+#    #+#             */
/*   Updated: 2025/05/23 23:58:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief This function will check if the pressed key is a valid key.
 * @param key_num The key code of the key that was pressed.
 * @return 1 If the pressed key was valid, else it will return 0.
 */
int	is_valid_key(int key_num)
{
	return (key_num == ESC || key_num == W || key_num == A || key_num == S
		|| key_num == D || key_num == LK || key_num == RK);
}

int	key_hook(int key_num, void *p)
{
	t_d	*pr;

	if (!is_valid_key(key_num))
		return (key_num);
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
		pr->player->angle -= ROTATION_SPEED;
	else if (key_num == RK)
		pr->player->angle += ROTATION_SPEED;
	game_loop(pr);
	return (key_num);
}
