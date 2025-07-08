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
	printf("Player position: x = %f, y = %f\n", p->player->ppx, p->player->ppy);
	clear_image_buffer(p);
	render_ceiling(p);
	render_floor(p);
	render_map(p);
	render_player(p);
	raycast_in_2d(p);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	p->player->rotate = 0;
	return (0);
}

int	main(int ac, char **av)
{
	t_d	*p;

	p = init();
	init_player(p);
	if (!is_valid_parsing(ac, av, p))
		return (free_p(p), 1);
	mlx_hook(p->win, 2, 1L << 0, key_press, p);
	mlx_hook(p->win, 3, 1L << 1, key_release, p);
	mlx_loop_hook(p->mlx, game_loop, p);
	mlx_loop(p->mlx);
	return (0);
}
