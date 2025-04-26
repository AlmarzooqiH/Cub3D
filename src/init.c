/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthodi <mthodi@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 05:19:41 by hamad             #+#    #+#             */
/*   Updated: 2025/04/16 22:19:33 by mthodi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief This function will initalize the texture.
 * @param	mlx The mlx connection.
 * @param	texture_path The path to the texture.
 * @return t_texture pointer.
 * @note The texture_path will be freed here.
 */
t_texture	*init_texture(void *mlx, char *texture_path)
{
	t_texture	*t;

	if (!texture_path)
		return (NULL);
	t = (t_texture *)ft_calloc(1, sizeof(t_texture));
	if (!t)
		return (free(texture_path), NULL);
	t->width = 0;
	t->height = 0;
	t->img = mlx_xpm_file_to_image(mlx, texture_path, &t->width, &t->height);
	if (!t->img)
	{
		t->width = 0;
		t->height = 0;
		free(t);
		free(texture_path);
		return (NULL);
	}
	free(texture_path);
	return (t);
}

/**
 * @brief This function will initalize the color.
 * @param	color The color string.
 * @return	t_color pointer.
 * @note The color will look like this: val1,val2,val3
 * so i would split it at ',' and will initalize the values acordingly.
 * @note We will free the @param color here, due to norminette restrictions.
 */
t_color	*init_color(char *color)
{
	t_color	*c;
	char	**rgb;

	if (!color)
		return (NULL);
	c = ft_calloc(1, sizeof(t_color));
	if (!c)
		return (free(color), NULL);
	rgb = ft_split(color, ',');
	if (!rgb)
		return (free(c), free(color), NULL);
	else if (count_split(rgb) < 3 || !rgb[0] || !rgb[1] || !rgb[2])
		return (free(c), free_split(rgb), free(color), NULL);
	if (ft_atol(rgb[0]) < 0 || ft_atol(rgb[0]) > 255
		|| ft_atol(rgb[1]) < 0 || ft_atol(rgb[1]) > 255
		|| ft_atol(rgb[2]) < 0 || ft_atol(rgb[2]) > 255)
		return (free_split(rgb), free(c), free(color), NULL);
	c->r = ft_atoi(rgb[0]);
	c->g = ft_atoi(rgb[1]);
	c->b = ft_atoi(rgb[2]);
	free_split(rgb);
	free(color);
	return (c);
}

/**
 * @brief This function will continue with the intialization of *t_d.
 * @var	p	The *t_d pointer.
 * @return (void).
 */
// void	init2(t_d *p)
// {
// }

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
	mlx_key_hook(p->win, key_hook, p);
	mlx_hook(p->win, WIN_EXIT, 0, free_p, (void *)p);
	return (p);
}

void	init_player(t_d *game)
{
	game->player.x = 3.5;
	game->player.y = 3.5;
	game->player.dir_x = -1;
	game->player.dir_y = 0;
	game->player.plane_x = 0;
	game->player.plane_y = 0.66;
}
