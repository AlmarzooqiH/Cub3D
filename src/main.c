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

int	main(int ac, char const *av[])
{
	t_d	*p;

	p = ft_calloc(sizeof(t_d), 1);
	if (!p)
		return (1);
	(void)ac;
	(void)av;
	printf("Hello, World!\n");
	p->mlx = mlx_init();
	p->win = mlx_new_window(p->mlx, WIDTH, HEIGHT, CUBE);
	sleep(10);
	mlx_destroy_window(p->mlx, p->win);
	free(p->mlx);
	free(p);
	return (0);
}
