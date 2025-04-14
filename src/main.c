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
	printf("floor: r: %d\tg: %d\tb: %d\n", p->floor->r,
		p->floor->g, p->floor->b);
	printf("ceiling: r: %d\tg: %d\tb: %d\n", p->ceiling->r,
		p->ceiling->g, p->ceiling->b);
	mlx_loop(p->mlx);
	return (0);
}
