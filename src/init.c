/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 05:19:41 by hamad             #+#    #+#             */
/*   Updated: 2025/04/07 06:48:02 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief This function will be responsible for the cleanup of the program.
 * @param	p the t_d struct. (Can be found in includes/struct.h)
 * @return (void)
 */
void	free_p(t_d *p)
{
	if (p->img)
		mlx_destroy_image(p->mlx, p->img);
	if (p->mlx)
		mlx_destroy_window(p->mlx, p->win);
	if (p->mlx)
		free(p->mlx);
	if (p)
		free(p);
	exit(EXIT_SUCCESS);
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
	mlx_key_hook(p->win, key_hook, p);
	return (p);
}
