/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 18:13:13 by hamalmar          #+#    #+#             */
/*   Updated: 2025/04/04 18:13:13 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	game_loop(t_d *p)
{
	clear_image_buffer(p);
	render_frame(p);
	draw_player(p);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_d	*p;

	p = init();
	init_player(p);
	if (!is_valid_parsing(ac, av, p))
		return (free_p(p), 1);
	printf("x: %f\ny: %f\n", p->player->ppx, p->player->ppy);
	game_loop(p);
	mlx_loop(p->mlx);
	return (0);
}
