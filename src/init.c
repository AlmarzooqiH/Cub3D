/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 05:19:41 by hamad             #+#    #+#             */
/*   Updated: 2025/04/09 01:14:18 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief This function will initalize the texture.
 * @return t_texture pointer.
 */
t_texture	*init_texture(void)
{
	t_texture	*t;

	t = (t_texture *)ft_calloc(1, sizeof(t_texture));
	if (!t)
		return (NULL);
	t->width = 0;
	t->height = 0;
	return (t);
}

/**
 * @brief This function will initalize the color.
 * @return	t_color pointer.
 */
t_color	*init_color(void)
{
	t_color	*c;

	c = ft_calloc(1, sizeof(t_color));
	if (!c)
		return (NULL);
	c->r = 0;
	c->g = 0;
	c->b = 0;
	return (c);
}

/**
 * @brief This function will continue with the intialization of *t_d.
 * @var	p	The *t_d pointer.
 * @return (void).
 */
void	init2(t_d *p)
{
	p->floor = init_color();
	p->ceiling = init_color();
	if (!p->floor || !p->ceiling)
	{
		disp_err(FTIC);
		free_p(p);
		return ;
	}
	mlx_key_hook(p->win, key_hook, p);
	mlx_hook(p->win, WIN_EXIT, 0, free_p, (void *)p);
}

/**
 * @brief This function will initalize the program data.
 * @param	p the t_d struct. (Can be found in includes/struct.h)
 * @return (void)
 */
t_d	*init(void)
{
	t_d	*p;

	p = ft_calloc(sizeof(t_d), 1);
	if (!p)
		return (disp_err(FTCM), free_p(p), NULL);
	p->mlx = mlx_init();
	if (!p->mlx)
		return (disp_err(FTIM), free_p(p), NULL);
	p->win = mlx_new_window(p->mlx, WIDTH, HEIGHT, CUBE);
	if (!p->win)
		return (disp_err(FTIW), free_p(p), NULL);
	p->img = mlx_new_image(p->mlx, WIDTH, HEIGHT);
	if (!p->img)
		return (disp_err(FTCI), free_p(p), NULL);
	p->imgd = mlx_get_data_addr(p->img, &p->bpp, &p->sl, &p->edn);
	if (!p->imgd)
		return (disp_err(FTGID), free_p(p), NULL);
	p->e = init_texture();
	p->w = init_texture();
	p->s = init_texture();
	p->n = init_texture();
	if (!p->e || !p->w || !p->s || !p->n)
		return (disp_err(FTIT), free_p(p), NULL);
	init2(p);
	return (p);
}
