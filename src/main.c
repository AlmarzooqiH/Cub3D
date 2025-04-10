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

int	main(int ac, char const **av)
{
	t_d	*p;

	if (ac != 2)
		return (disp_err(WRONG_INPUT), 1);
	//av[1] is the file name and is passed to the parsing function.
	if (ac != 2 || !is_valid_parsing((char *)av[1]))
		return (disp_err(FTF), 1);
	p = init();
	mlx_loop(p->mlx);
	return (0);
}
