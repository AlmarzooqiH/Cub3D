/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:06:48 by mthodi            #+#    #+#             */
/*   Updated: 2025/06/02 00:08:52 by hamalmar         ###   ########.fr       */
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
				ctoi(c));
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
		put_pixel(p, (int)x, (int)y, ctoi(p->player->color));
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

	i = 0;
	while (i < p->player_height)
	{
		j = 0;
		while (j < p->player_width)
		{
			put_pixel(p, j + ((p->player->ppx - 1) * p->player_width), i
				+ ((p->player->ppy - 1) *p-> player_height),
				ctoi(p->player->color));
			j++;
		}
		i++;
	}
	render_direction(p, p->player_width, p->player_height);
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

/**
 * @brief This function should draw a ray from the player position to the wall
 * after performing the dda algorthim.
 * @param p The program struct.
 * @return void.
 */
void	draw_line(t_d *p)
{
	int		i;
	int		incx;
	int		incy;
	int		steps;
	float	startx;
	float	starty;

	if (fabs(p->player->ray->mapx - p->player->ppx) > fabs(p->player->ray->mapy - p->player->ppy))
		steps = fabs(p->player->ray->mapx - p->player->ppx);
	else
		steps = fabs(p->player->ray->mapy - p->player->ppy);
	incx = fabs(p->player->ray->mapx - p->player->ppx) / (float)steps;
	incy = fabs(p->player->ray->mapy - p->player->ppy) / (float)steps;
	startx = p->player->ppx * p->player_width;
	starty = p->player->ppy * p->player_height;
	i = 0;
	while (i < steps)
	{
		put_pixel(p, (int)(startx + p->player_width), (int)(starty + p->player_width), ctoi(p->player->color));
		startx += incx;
		starty += incy;
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
	t_ray	*r;

	r = p->player->ray;
	while (!r->hit)
	{
		if (r->sdx < r->sdy)
		{
			r->sdx += r->ddx;
			r->mapx += r->step_x;
		}
		else
		{
			r->sdy += r->ddy;
			r->mapy += r->step_y;
		}
		if (p->map[r->mapy][r->mapx] == '1')
		{
			r->hit = 1;
			draw_line(p);
		}
	}
}

