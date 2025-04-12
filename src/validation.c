/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:18:32 by mthodi            #+#    #+#             */
/*   Updated: 2025/04/12 13:20:20 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief	This function will check if the string has the correct suffix.
 * @param	s The string we want to check.
 * @param	suffix The suffix we want to check
 * @return 1 if the file name is valid, 0 otherwise.
 */
int	is_suffix(const char *s, const char *suffix)
{
	int	i;
	int	j;

	if (!s || !suffix)
		return (0);
	i = 0;
	while (s[i] != '\0' && s[i] != suffix[0])
		i++;
	if (s[i] == '\0')
		return (0);
	j = 0;
	while ((s[i] != '\0' && suffix[j] != '\0') && (s[i] == suffix[j]))
	{
		i++;
		j++;
	}
	return (s[i] == '\0' && suffix[j] == '\0');
}

int	check_textures(int fd, char *line)
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
int	is_valid_map(char *fname)
{
	int		fd;
	char	*line;

	fd = open(fname, O_RDONLY);
	if (fd < 0)
		return (disp_err(FILE_DOESNT_EXSIST), 0);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), disp_err(EMPTY_MAP), 0);
	if (check_textures(fd, line))
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
int	is_valid_parsing(int ac, char **av)
{
	if (ac != 2)
		return (disp_err(WRONG_INPUT), 0);
	if (!is_suffix(av[1], DOT_CUB))
		return (disp_err(INVALID_FILE), 0);
	if (!is_valid_map((char *)av[1]))
		return (0);
	return (1);
}
