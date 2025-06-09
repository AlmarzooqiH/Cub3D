/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:06:48 by mthodi            #+#    #+#             */
/*   Updated: 2025/06/09 18:15:23 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
// void	render_direction(t_d *p, int pw, int ph)
// {
// 	int		i;
// 	double	steps;
// 	double	x;
// 	double	y;

// 	steps = fmax(fabs((((p->player->ppx * pw) + p->player->pdx * LINE_LENGTH)
// 					- (p->player->ppx * pw))), fabs(((p->player->ppy * ph)
// 					+ p->player->pdy * LINE_LENGTH) - (p->player->ppy * ph)));
// 	i = 0;
// 	x = p->player->ppx * pw;
// 	y = p->player->ppy * ph;
// 	while (i < steps)
// 	{
// 		put_pixel(p, (int)x, (int)y, ctoi(p->player->color));
// 		x += ((((p->player->ppx * pw) + p->player->pdx * LINE_LENGTH)
// 					- (p->player->ppx * pw)) / steps);
// 		y += (((p->player->ppy * ph) + p->player->pdy * LINE_LENGTH)
// 				- (p->player->ppy * ph)) / steps;
// 		i++;
// 	}
// }

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
	while (i < p->grid_height)
	{
		j = 0;
		while (j < p->grid_width)
		{
			put_pixel(p, j + ((p->player->ppx - 1) * p->grid_width), i
				+ ((p->player->ppy - 1) * p-> grid_height),
				ctoi(p->player->color));
			j++;
		}
		i++;
	}
	// render_direction(p, p->player_width, p->player_height);
}

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
	int	i;
	int	j;

	i = 0;
	while (i < p->grid_height - 1)
	{
		j = 0;
		while (j < p->grid_width - 1)
		{
			put_pixel(p, j + (x * p->grid_width), i + (y * p->grid_height),
				ctoi(c));
			j++;
		}
		i++;
	}
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
	int	pxs;
	int	pys;
	int	pxe;
	int	pye;
	int	iodx;
	int	iody;

	pxs = p->player->ppx * p->grid_width;
	pys = p->player->ppy * p->grid_height;
	pxe = p->player->ray->mapx * p->grid_width;
	pye = p->player->ray->mapy * p->grid_height;
	if (pxs > pxe)
		iodx = -1;
	else
		iodx = 1;
	if (pys > pye)
		iody = -1;
	else
		iody = 1;
	printf("pxs: %d, pys: %d, pxe: %d, pye: %d\n", pxs, pys, pxe, pye);
	while (pys != pye)
	{
		put_pixel(p, pxs, pys, ctoi(p->player->ray->color));
		pys += iody;
	}
	while (pxs != pxe)
	{
		put_pixel(p, pxs, pys, ctoi(p->player->ray->color));
		pxs += iodx;
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

	update_ray(p->player);
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
			r->dist = get_distance(p->player);
			/*
				Checked and the ray hits at a proper position.
				All i need to understand now is just how can i draw
				a line from the player to the wall that it hit, showing
				the direction of the ray also and lastly casting multiple
				rays in the FOV of the player. Then i shall move on to 3d
				since i would be having a proper understanding.
			*/
			printf("ray hit at: (%d, %d) with a distance of: %f\n", r->mapx, r->mapy, r->dist);
			draw_line(p);
		}
	}
}

