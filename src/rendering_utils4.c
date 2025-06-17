/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 02:49:18 by hamalmar          #+#    #+#             */
/*   Updated: 2025/06/18 02:49:18 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief This function will render the ceiling of the map.
 * @param p The program struct.
 * @return void
 */
void	render_ceiling(t_d *p)
{
	int	i;
	int	j;

	i = 0;
	while (i < (HEIGHT / 2))
	{
		j = 0;
		while (j < WIDTH)
		{
			put_pixel(p, j, i, ctoi(p->ceiling));
			j++;
		}
		i++;
	}
}

/**
 * @brief This function will render the floor of the map.
 * @param p The program struct.
 * @return void
 */
void	render_floor(t_d *p)
{
	int	i;
	int	j;

	i = (HEIGHT / 2);
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			put_pixel(p, j, i, ctoi(p->floor));
			j++;
		}
		i++;
	}
}
