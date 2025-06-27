/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthodi <mthodi@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 00:53:59 by hamad             #+#    #+#             */
/*   Updated: 2025/06/26 19:36:38 by mthodi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	dfs(char **map, int y, int x)
{
	if (map[y][x] == '1' || map[y][x] == 'X')
		return (1);
	map[y][x] = 'X';
	if (!dfs(map, y, x + 1))
		return (0);
	if (!dfs(map, y, x - 1))
		return (0);
	if (!dfs(map, y + 1, x))
		return (0);
	if (!dfs(map, y - 1, x))
		return (0);
	return (1);
}
