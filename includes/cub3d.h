/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 18:13:39 by hamalmar          #+#    #+#             */
/*   Updated: 2025/04/04 18:13:39 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "struct.h"
# include "error.h"
# include "../libft/libft.h"

# define CUBE "Cub3D"
# define DOT_CUB ".cub\0"
# define NO "NO\0"
# define SO "SO\0"
# define WE "WE\0"
# define EA "EA\0"
# define WIDTH 800
# define HEIGHT 800

/*			Clean up functions				*/
int			free_p(t_d *p);
void		free_texture(t_texture *t, void *mlx);

/*			Initalization functions			*/
t_d			*init(void);
// void		init2(t_d *p);
t_texture	*init_texture(void *mlx, char *img_path);
t_color		*init_color(void);
int			key_hook(int key_num, void *p);

/*			Error functions					*/
void		disp_err(const char *error);

/*			Parsing functions				*/
int			is_valid_parsing(int ac,char **av, t_d *p);
int			is_suffix(const char *s, const char *suffix);
int			ft_isprefix(const char *s, const char *prefix);
char		*skip_empty_line(int fd, char *line);
#endif