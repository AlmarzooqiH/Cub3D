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

int	main(int ac, char **av)
{
	t_d	*p;

	p = init();
	if (!is_valid_parsing(ac, av, p))
		return (free_p(p), 1);
	// mlx_put_image_to_window(p->mlx, p->win, p->e->img, 0, 0);
	int wid = 0;
	int hei = 0;
	int color = (p->floor->r << 16) | (p->floor->g << 8) | (p->floor->b);
	while (wid < (WIDTH / 2) && hei < (HEIGHT / 2))
	{
		mlx_pixel_put(p->mlx, p->win, wid, hei, color);
		wid++;
		hei++;
	}
	color = (p->ceiling->r << 16) | (p->ceiling->g << 8) | (p->ceiling->b);
	while (wid < (WIDTH) && hei < (HEIGHT))
	{
		mlx_pixel_put(p->mlx, p->win, wid, hei, color);
		wid++;
		hei++;
	}
	printf("floor: r: %d\tg: %d\tb: %d\n", p->floor->r,  p->floor->g,  p->floor->b);
	printf("ceiling: r: %d\tg: %d\tb: %d\n", p->ceiling->r,  p->ceiling->g,  p->ceiling->b);
	mlx_loop(p->mlx);
	return (0);
}
