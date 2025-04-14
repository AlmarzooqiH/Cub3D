/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:18:32 by mthodi            #+#    #+#             */
/*   Updated: 2025/04/14 12:13:38 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief This function will check and initalize the colors.
 * @parm	fd The map file descriptor.
 * @param	line The line we want to get.
 * @param	p The program struct.
 * @return 1 if all colors were initalized properly. 0 otherwise.
 * @note When we split the line it will be stored like this:
 * floor or the ceiling, color}. The color will also have a \n at the
 * end so make sure to trim it.
 */
int check_colors(int fd, char *line, t_d *p)
{
	char	**tokenized_line;
	int		i;

	if (!line || !line[0])
		line = get_next_line(fd);
	i = 0;
	while (i < 2 && line != NULL)
	{
		tokenized_line = ft_split(line, ' ');
		if (!tokenized_line || !tokenized_line[0] || !tokenized_line[1])
			return (0);
		if (!p->floor && !ft_strcmp(tokenized_line[0], F)) {
			printf("Assigning to floor\n");
			p->floor = init_color(ft_strtrim(tokenized_line[1], "\n"));
		} else if (!p->ceiling && !ft_strcmp(tokenized_line[0], C)) {
			printf("Assigning to ceiling\n");
			p->ceiling = init_color(ft_strtrim(tokenized_line[1], "\n"));
		}
		else
			return (free_split(tokenized_line), free(line), 0);
		free_split(tokenized_line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	return (p->floor && p->ceiling);
}

/**
 * @brief This function will check and initalize the textures.
 * @parm	fd The map file descriptor.
 * @param	line The line we want to get.
 * @param	p The program struct.
 * @return 1 if all textures were initalized properly. 0 otherwise.
 * @note @param line will initality contain the first line of the fd.
 * @note When we split the line it will be stored like this:
 * Direction, file_path}. The file path will also have a \n at the end so make
 * sure to trim it.
 */
int	check_textures(int fd, char *line, t_d *p)
{
	char	**tokenized_line;
	int		i;

	i = 0;
	while (i < 4 && line != NULL)
	{
		tokenized_line = ft_split(line, ' ');
		if (!tokenized_line || !tokenized_line[0] || !tokenized_line[1])
			return (0);
		if (!p->n && !ft_strcmp(tokenized_line[0], NO))
			p->n = init_texture(p->mlx, ft_strtrim(tokenized_line[1], "\n"));
		else if (!p->s && !ft_strcmp(tokenized_line[0], SO))
			p->s = init_texture(p->mlx, ft_strtrim(tokenized_line[1], "\n"));
		else if (!p->w && !ft_strcmp(tokenized_line[0], WE))
			p->w = init_texture(p->mlx, ft_strtrim(tokenized_line[1], "\n"));
		else if (!p->e && !ft_strcmp(tokenized_line[0], EA))
			p->e = init_texture(p->mlx, ft_strtrim(tokenized_line[1], "\n"));
		else
			return (free_split(tokenized_line), free(line), 0);
		free_split(tokenized_line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	return (p->e && p->w && p->s && p->n);
}

/**
 * @brief This function checks if the map file is valid.
 * @param fname The file name to check.
 * @return 1 if the map file is valid, 0 otherwise.
 * @note removed the condition to free the line because it caused double free.
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
	if (!check_textures(fd, line, p))
		return (close(fd), 0);
	if (!p->e || !p->w || !p->s || !p->n)
		return (close(fd), 0);
	line = NULL;
	if (!check_colors(fd, line, p))
		return (close(fd), 0);
	if (!p->floor || !p->ceiling)
		return (close(fd), 0);
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
		return (disp_err(MAP_FORMAT), 0);
	return (1);
}
