/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 00:31:03 by hamad             #+#    #+#             */
/*   Updated: 2025/06/17 18:29:35 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief This function is responsible to freeing *t_texture.
 * @var	t	The texture we want to free.
 * @var	mlx The mlx connection.
 * @return	(void).
 */
void	free_texture(t_texture *t, void *mlx)
{
	if (!t)
		return ;
	if (t->img)
		mlx_destroy_image(mlx, t->img);
	t->height = 0;
	t->width = 0;
	t->edn = 0;
	t->bpp = 0;
	t->sl = 0;
	t->proj = 0.0f;
	t->line_height = 0;
	t->y_start = 0;
	t->x_start = 0;
	t->x_end = 0;
	t->imgd = NULL;
	free(t);
}

/**
 * @brief This function is responsible to freeing *t_color.
 * @var	c	The color we want to free.
 * @return	(void).
 */
void	free_color(t_color *c)
{
	if (!c)
		return ;
	c->r = 0;
	c->g = 0;
	c->b = 0;
	free(c);
}

void	free_player(t_player *p)
{
	if (!p)
		return ;
	if (p->color)
	{
		free_color(p->color);
		p->color = NULL;
	}
	if (p->ray)
	{
		free_color(p->ray->color);
		p->ray->color = NULL;
		free(p->ray);
		p->ray = NULL;
	}
	p->ppx = 0;
	p->ppy = 0;
	p->pdx = 0;
	p->pdy = 0;
	p->camera_x = 0;
	p->camera_y = 0;
	free(p);
}

/**
 * @brief This function will be responsible for the cleanup of the program.
 * @param	p the t_d struct. (Can be found in includes/struct.h)
 * @return (void)
 * @note After freeing the allocated memorey this function will terminate the
 * cub3d program.
 */
int	free_p(t_d *p)
{
	if (p->img)
		mlx_destroy_image(p->mlx, p->img);
	if (p->mlx)
		mlx_destroy_window(p->mlx, p->win);
	if (p->player)
		free_player(p->player);
	free_texture(p->e, p->mlx);
	free_texture(p->w, p->mlx);
	free_texture(p->s, p->mlx);
	free_texture(p->n, p->mlx);
	free_color(p->floor);
	free_color(p->ceiling);
	if (p->mlx)
		free(p->mlx);
	if (p)
		free(p);
	exit(EXIT_SUCCESS);
	return (1);
}
