/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:18:32 by mthodi            #+#    #+#             */
/*   Updated: 2025/04/14 01:37:39 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_textures(int fd, char *line, t_d *p)
{
	int	e;
	int	w;
	int	s;
	int	n;

	return ((e == 1) && (w == 1) && (s == 1) && (n == 1));
}

/**
 * @brief This function checks if the map file is valid.
 * @param fname The file name to check.
 * @return 1 if the map file is valid, 0 otherwise.
 */
int	is_valid_map(char *fname, t_d *p)
{
	int		fd;
	char	*line;

	fd = open(fname, O_RDONLY);
	if (fd < 0)
		return (disp_err(FILE_DOESNT_EXSIST), 0);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), disp_err(EMPTY_MAP), 0);
	if (check_textures(fd, line, p))
		return (close(fd), 0);
	if (line)
		free(line);
	return (close(fd), 1);
}

/**
 * @brief This function checks for valid parsing.
 * @param	ac The argument counter from the main function.
 * @param	av The arguments from the main function.
 * @return 1 if the parsing is valid, 0 otherwise.
 */
int	is_valid_parsing(int ac, char **av, t_d *p)
{
	if (ac != 2)
		return (disp_err(WRONG_INPUT), 0);
	if (!is_suffix(av[1], DOT_CUB))
		return (disp_err(INVALID_FILE), 0);
	if (!is_valid_map(av[1], p))
		return (0);
	return (1);
}
