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

	if (!is_valid_parsing(ac, av))
		return (1);
	p = init();
	mlx_loop(p->mlx);
	return (0);
}
