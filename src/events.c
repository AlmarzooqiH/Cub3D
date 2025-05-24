/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 05:37:34 by hamad             #+#    #+#             */
/*   Updated: 2025/05/24 15:44:39 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief This function will check if the pressed key is a valid key.
 * @param keycode The key code of the key that was pressed.
 * @return 1 If the pressed key was valid, else it will return 0.
 */
int	is_valid_key(int keycode)
{
	return (keycode == ESC || keycode == W || keycode == A || keycode == S
		|| keycode == D || keycode == LK || keycode == RK);
}

int	update_player(int keycode, t_d *p)
{
	if (keycode == W)
		p->player->ppy -= MOVEMENT_SPEED;
	else if (keycode == A)
		p->player->ppx -= MOVEMENT_SPEED;
	else if (keycode == S)
		p->player->ppy += MOVEMENT_SPEED;
	else if (keycode == D)
		p->player->ppx += MOVEMENT_SPEED;
	else if (keycode == LK)
		p->player->angle -= ROTATION_SPEED;
	else if (keycode == RK)
		p->player->angle += ROTATION_SPEED;
	if (keycode == LK || keycode == RK)
		p->player->rotate = 1;
	return (keycode);
}

int	key_press(int keycode, void *p)
{
	t_d	*pr;

	pr = (t_d *)p;
	if (!is_valid_key(keycode))
		return (keycode);
	if (keycode == ESC)
		free_p(pr);
	if (keycode == W)
		pr->player->w_pressed = 1;
	if (keycode == A)
		pr->player->a_pressed = 1;
	if (keycode == S)
		pr->player->s_pressed = 1;
	if (keycode == D)
		pr->player->d_pressed = 1;
	if (keycode == LK)
		pr->player->lk_pressed = 1;
	if (keycode == RK)
		pr->player->rk_pressed = 1;
	update_player(keycode, pr);
	return (keycode);
}

int	key_release(int keycode, void *p)
{
	t_d	*pr;

	if (!is_valid_key(keycode))
		return (keycode);
	pr = (t_d *)p;
	if (keycode == W)
		pr->player->w_pressed = 0;
	if (keycode == A)
		pr->player->a_pressed = 0;
	if (keycode == S)
		pr->player->s_pressed = 0;
	if (keycode == D)
		pr->player->d_pressed = 0;
	if (keycode == LK)
		pr->player->lk_pressed = 0;
	if (keycode == RK)
		pr->player->rk_pressed = 0;
	return (keycode);
}
