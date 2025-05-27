/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:06:48 by mthodi            #+#    #+#             */
/*   Updated: 2025/05/27 16:03:46 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief This function will draw a grid on the screen.
 * @param p This holds the program data.
 * @param x Current X position on the screen.
 * @param y Current Y position on the screen.
 * @param c The color that we want the grid to be.
 * @return Void
 */
void	draw_grid(t_d *p, int x, int y, t_color *c)
{
	size_t	i;
	size_t	j;
	size_t	grid_width;
	size_t	grid_height;

	grid_width = (int)ceil(((double)WIDTH) / ((double)p->map_width));
	grid_height = (int)ceil(((double)HEIGHT) / ((double)p->map_height));
	i = 0;
	while (i < grid_height)
	{
		j = 0;
		while (j < grid_width)
		{
			put_pixel(p, j + (x * grid_width), i + (y * grid_height),
				rgb_to_int(c));
			j++;
		}
		i++;
	}
}

/**
 * @brief This function will draw a line starting from the center of the playe
 * r indicating his direction of movement.
 * @param p The program struct.
 * @param pw The player width.
 * @param ph The player height.
 * @return void.
 */
void	render_direction(t_d *p, int pw, int ph)
{
	int		i;
	double	steps;
	double	x;
	double	y;

	steps = fmax(fabs((((p->player->ppx * pw) + p->player->pdx * LINE_LENGTH)
					- (p->player->ppx * pw))), fabs(((p->player->ppy * ph)
					+ p->player->pdy * LINE_LENGTH) - (p->player->ppy * ph)));
	i = 0;
	x = p->player->ppx * pw;
	y = p->player->ppy * ph;
	while (i < steps)
	{
		put_pixel(p, (int)x, (int)y, rgb_to_int(p->player->color));
		x += ((((p->player->ppx * pw) + p->player->pdx * LINE_LENGTH)
					- (p->player->ppx * pw)) / steps);
		y += (((p->player->ppy * ph) + p->player->pdy * LINE_LENGTH)
				- (p->player->ppy * ph)) / steps;
		i++;
	}
}

/**
 * @brief This function will render the player in his proper position.
 * @param p The program struct.
 * @return void.
 * @note If you see here we subtract - 1 from the ppx and ppy because the NULL
 * termination.
 */
void	render_player(t_d *p)
{
	int	i;
	int	j;
	int	player_width;
	int	player_height;

	player_width = (int)ceil(((double)WIDTH) / ((double)p->map_width));
	player_height = (int)ceil(((double)HEIGHT) / ((double)p->map_height));
	i = 0;
	while (i < player_height)
	{
		j = 0;
		while (j < player_width)
		{
			plot_player(p, j + ((p->player->ppx - 1) * player_width), i
				+ ((p->player->ppy - 1) * player_height));
			j++;
		}
		i++;
	}
	render_direction(p, player_width, player_height);
}

/**
 * @brief This function will render the map.
 * @param p The program struct.
 * @return void.
 */
void	render_map(t_d *p)
{
	int	i;
	int	j;

	i = 0;
	while (p->map[i])
	{
		j = 0;
		while (p->map[i][j] != '\0')
		{
			if (p->map[i][j] == '1')
				draw_grid(p, j, i, p->ceiling);
			else
				draw_grid(p, j, i, p->floor);
			j++;
		}
		i++;
	}
}
