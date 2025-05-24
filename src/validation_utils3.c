/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 17:29:23 by hamalmar          #+#    #+#             */
/*   Updated: 2025/05/24 16:45:32 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief This function will get the maximum width inside the map.
 * @param map The map.
 * @return The maximum width inside the map.
 */
size_t	get_max_width(char **map)
{
	int		i;
	size_t	max;
	size_t	curr;

	i = 0;
	max = 0;
	curr = 0;
	while (map[i])
	{
		curr = ft_strlen(map[i]);
		if (curr > max)
			max = curr;
		i++;
	}
	return (max);
}

/**
 * @brief This function will set the direction.
 * @param c Is the direction that is in the old map.
 * @return A char one of the following {'E', 'W', 'S', 'N'}
 */
char	set_direction(char c)
{
	if (c == 'E')
		return ('E');
	else if (c == 'W')
		return ('W');
	else if (c == 'S')
		return ('S');
	return ('N');
}

/**
 * @brief This function will set the data of the new map from the old map.
 * @param om The Old Map.
 * @param nm The New Map.
 * @param mw The Map Width.
 * @param mh The Map Height.
 * @note In this function we will free the Old Map.
 */
void	normalize_map_2(char **om, char **nm, size_t mw, size_t mh)
{
	size_t	i;
	size_t	j;
	size_t	om_len;

	i = 0;
	while (i < mh)
	{
		j = 0;
		om_len = ft_strlen(om[i]);
		while (j < mw)
		{
			if (j >= om_len || om[i][j] == '1' || ft_isspace(om[i][j]))
				nm[i][j] = '1';
			else if (om[i][j] == '0')
				nm[i][j] = '0';
			else if (om[i][j] == 'E' || om[i][j] == 'W'
					|| om[i][j] == 'S' || om[i][j] == 'N')
				nm[i][j] = set_direction(om[i][j]);
			j++;
		}
		i++;
	}
	free_split(om);
}

/**
 * @brief This function will normalize the map size from nxm to nxn.
 * @param om Is the Old Map.
 * @return A char ** as the new nxn map.
 * @note This function will initalize the map and it's sizw also the
 * old map will be freed.
 */
char	**normalize_map_1(char **om)
{
	char	**nm;
	size_t	i;
	size_t	map_height;
	size_t	map_width;

	if (!om)
		return (NULL);
	map_height = count_split(om);
	nm = (char **)ft_calloc(map_height + 1, sizeof(char *));
	if (!nm)
		return (free_split(om), NULL);
	map_width = get_max_width(om);
	i = 0;
	while (i < map_height)
	{
		nm[i] = (char *)ft_calloc(map_width + 1, sizeof(char));
		if (!nm[i])
			return (free_split(nm), free_split(om), NULL);
		i++;
	}
	normalize_map_2(om, nm, map_width, map_height);
	return (nm);
}
