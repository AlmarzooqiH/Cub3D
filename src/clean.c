/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 00:31:03 by hamad             #+#    #+#             */
/*   Updated: 2025/04/09 00:50:33 by hamad            ###   ########.fr       */
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

/**
 * @brief This function will be responsible for the cleanup of the program.
 * @param	p the t_d struct. (Can be found in includes/struct.h)
 * @return (void)
 */
int	free_p(t_d *p)
{
	if (p->img)
		mlx_destroy_image(p->mlx, p->img);
	if (p->mlx)
		mlx_destroy_window(p->mlx, p->win);
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
