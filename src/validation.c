/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthodi <mthodi@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:18:32 by mthodi            #+#    #+#             */
/*   Updated: 2025/04/09 13:51:33 by mthodi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief This function checks if the file name is valid.
 * @param fname The file name to check.
 * @return 1 if the file name is valid, 0 otherwise.
 */
int	is_valid_fname(char *fname)
{
    int	i;

    i = 0;
    while (fname[i])
        i++;
    if (i < 5)
        return (0);
    if (fname[i - 4] != '.' || fname[i - 3] != 'c' || fname[i - 2] != 'u'
        || fname[i - 1] != 'b')
        return (0);
    return (1);
}

/**
 * @brief This function checks if the map file is valid.
 * @param fname The file name to check.
 * @return 1 if the map file is valid, 0 otherwise.
 */
int	is_valid_map(char *fname)
{
    int	fd;
    char	*line;

    fd = open(fname, O_RDONLY);
    if (fd < 0)
        return (0);
    line = get_next_line(fd);
    if (!line)
        return (0);
    free(line);
    close(fd);
    return (1);
}

/**
 * @brief This function checks for valid parsing.
 * @param fname The file name to check.
 * @return 1 if the parsing is valid, 0 otherwise.
 */
int	is_valid_parsing(char *fname)
{
    if (!is_valid_fname(fname))
        return (0);
    if (!is_valid_map(fname))
        return (0);
    return (1);
}
