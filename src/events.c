/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthodi <mthodi@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 05:37:34 by hamad             #+#    #+#             */
/*   Updated: 2025/07/09 15:16:57 by mthodi           ###   ########.fr       */
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

/**
 * @brief This function will rotate the player and make sure the rotation is
 * bounded from 0 to 2PI.
 * @param p The player.
 * @return void.
 */
void	rotate_player(t_player *p)
{
	if (p->lk_pressed)
		p->angle -= ROTATION_SPEED;
	if (p->rk_pressed)
		p->angle += ROTATION_SPEED;
	if (p->angle > 2 * M_PI)
		p->angle -= 2 * M_PI;
	if (p->angle < 0)
		p->angle += 2 * M_PI;
	p->pdx = cos(p->angle);
	p->pdy = sin(p->angle);
}

/**
 * @brief This function will update the player position.
 * @param p The player.
 * @return void.
 */
void	update_player(t_d *p)
{
	rotate_player(p->player);
	if (p->player->w_pressed)
	{
		update_pos(p, p->player->ppx + MOVEMENT_SPEED * cos(p->player->angle),
			p->player->ppy + MOVEMENT_SPEED * sin(p->player->angle));
	}
	if (p->player->s_pressed)
	{
		update_pos(p, p->player->ppx - MOVEMENT_SPEED * cos(p->player->angle),
			p->player->ppy - MOVEMENT_SPEED * sin(p->player->angle));
	}
	if (p->player->a_pressed)
	{
		update_pos(p, p->player->ppx + MOVEMENT_SPEED * sin(p->player->angle),
			p->player->ppy - MOVEMENT_SPEED * cos(p->player->angle));
	}
	if (p->player->d_pressed)
	{
		update_pos(p, p->player->ppx - MOVEMENT_SPEED * sin(p->player->angle),
			p->player->ppy + MOVEMENT_SPEED * cos(p->player->angle));
	}
	if (p->player->ppx < 0)
		p->player->ppx = 0;
	if (p->player->ppy < 0)
		p->player->ppy = 0;
}

/**
 * @brief This function will handle key press events and update the player state.
 * @param keycode The key code of the key that was pressed.
 * @param p Pointer to the main data structure.
 * @return The keycode that was processed.
 */
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
	update_player(pr);
	return (keycode);
}

/**
 * @brief This function will handle key press events and update the player state.
 * @param keycode The key code of the key that was pressed.
 * @param p Pointer to the main data structure.
 * @return The keycode that was processed.
 */
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
