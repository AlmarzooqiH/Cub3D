/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthodi <mthodi@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 00:53:59 by hamad             #+#    #+#             */
/*   Updated: 2025/06/26 20:12:37 by mthodi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
/**
 * @brief Compute height and width of the raw map.
 */
void	compute_dimensions(char **orig, int *height, int *width)
{
	int		i;
	size_t	len;

	*height = 0;
	while (orig[*height] != NULL)
		(*height)++;
	*width = 0;
	i = 0;
	while (i < *height)
	{
		len = ft_strlen(orig[i]);
		if ((int)len > *width)
			*width = (int)len;
		i++;
	}
}

/**
 * @brief Allocate a new normalized map filled entirely with '1's.
 */
char	**allocate_norm_map(int height, int width)
{
	int		i;
	char	**norm;

	norm = malloc(sizeof(char *) * (height + 1));
	if (!norm)
		return (NULL);
	i = 0;
	while (i < height)
	{
		norm[i] = malloc(width + 1);
		if (!norm[i])
		{
			while (i-- > 0)
				free(norm[i]);
			free(norm);
			return (NULL);
		}
		ft_memset(norm[i], '1', width);
		norm[i][width] = '\0';
		i++;
	}
	norm[height] = NULL;
	return (norm);
}

/**
 * @brief Copy non-space tiles from orig into the normalized map.
 */
void	copy_map_contents(char **orig, char **norm, int height, int width)
{
	int		i;
	int		j;
	size_t	len;
	(void)	width;

	i = 0;
	while (i < height)
	{
		len = ft_strlen(orig[i]);
		j = 0;
		while (j < (int)len)
		{
			if (orig[i][j] != ' ')
				norm[i][j] = orig[i][j];
			j++;
		}
		i++;
	}
}
