/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:06:48 by mthodi            #+#    #+#             */
/*   Updated: 2025/06/01 20:50:40 by marvin           ###   ########.fr       */
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
 * @note Coming back to this functionm, it looks cursed and i forgot the math
 * behind it. Lmao.
 * -Hamad
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
			put_pixel(p, j + ((p->player->ppx - 1) * player_width), i
				+ ((p->player->ppy - 1) * player_height),
				rgb_to_int(p->player->color));
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

void	draw_line(t_d *p, int x2, int y2)
{
	int	i;
	int	player_width;
	int	player_height;
	float	dx;
	float	dy;
	int		step;
	float	stepx;
	float	stepy;
	int	x1;
	int	y1;

	player_width = (int)ceil(((double)WIDTH) / ((double)p->map_width));
	player_height = (int)ceil(((double)HEIGHT) / ((double)p->map_height));
	x1 = p->player->ppx;
	y1 = p->player->ppy;
	dx = x2 - x1;
	dy = y2 = y1;
	if (fabsf(dx) > fabsf(dy))
		step = (int)fabsf(dx);
	else
		step = (int)fabsf(dy);
	stepx = dx / step;
	stepy = dy / step;
	i = 0;
	while (i < step)
	{
		put_pixel(p, x1 + ((p->player->ppx - 1) * player_width), y1
				+ ((p->player->ppy - 1) * player_height),
				rgb_to_int(p->player->color));
		x1 += stepx;
		y1 += stepy;
		i++;
	}
}

/**
 * @brief This function will draw rays from the player position.
 * @param The program structure.
 * @return void.
 * @note For now i will implement it then i will worry about norminette lmao.
 */
void	raycast_in_2d(t_d *p)
{
	float	rdx = p->player->pdx;
	float	rdy = p->player->pdy;
	float	rpx = p->player->ppx;
	float	rpy = p->player->ppy;
	float	ddx, ddy;
	float	sdx, sdy;
	int		step_x, step_y;
	int		map_x = (int)rpx;
	int		map_y = (int)rpy;
	int		hit = 0;

	get_inital_dist(&ddx, &ddy, rdx, rdy);

	if (rdx < 0)
	{
		step_x = -1;
		sdx = (rpx - map_x) * ddx;
	}
	else
	{
		step_x = 1;
		sdx = (map_x + 1.0f - rpx) * ddx;
	}
	if (rdy < 0)
	{
		step_y = -1;
		sdy = (rpy - map_y) * ddy;
	}
	else
	{
		step_y = 1;
		sdy = (map_y + 1.0f - rpy) * ddy;
	}

	while (!hit)
	{
		if (sdx < sdy)
		{
			sdx += ddx;
			map_x += step_x;
		}
		else
		{
			sdy += ddy;
			map_y += step_y;
		}
		if (p->map[map_y][map_x] == '1')
		{
			hit = 1;
			draw_line(p, map_x, map_y);
		}
	}
}

