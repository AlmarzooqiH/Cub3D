/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 05:37:34 by hamad             #+#    #+#             */
/*   Updated: 2025/04/07 06:50:05 by hamad            ###   ########.fr       */
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
		printf("W was pressed\n");
	else if (key_num == A)
		printf("A was pressed\n");
	else if (key_num == S)
		printf("S was pressed\n");
	else if (key_num == D)
		printf("D was pressed\n");
	else if (key_num == LK)
		printf("Left key was pressed\n");
	else if (key_num == RK)
		printf("Right key was pressed\n");
	return (key_num);
}
