/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthodi <mthodi@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 17:29:23 by hamalmar          #+#    #+#             */
/*   Updated: 2025/07/03 14:34:49 by mthodi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	validate_file_extension(const char *path)
{
	const char	*ext;

	ext = ft_strrchr(path, '.');
	if (!ext || ft_strcmp(ext, ".cub") != 1)
	{
		disp_err(INVALID_FILE);
		return (0);
	}
	return (1);
}

int	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

void	set_north_south(t_d *p, char dir)
{
	if (dir == 'N')
	{
		p->player->pdx = 0;
		p->player->pdy = -1;
		p->player->camera_x = 0.66;
	}
	else
	{
		p->player->pdx = 0;
		p->player->pdy = 1;
		p->player->camera_x = -0.66;
	}
	p->player->camera_y = 0;
}

void	set_east_west(t_d *p, char dir)
{
	if (dir == 'E')
	{
		p->player->pdx = 1;
		p->player->camera_y = 0.66;
	}
	else
	{
		p->player->pdx = -1;
		p->player->camera_y = -0.66;
	}
	p->player->pdy = 0;
	p->player->camera_x = 0;
}

void	init_player_direction(t_d *p, char dir)
{
	if (dir == 'N' || dir == 'S')
		set_north_south(p, dir);
	else
		set_east_west(p, dir);
}
