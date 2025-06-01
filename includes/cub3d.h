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
# include <math.h>
# include "struct.h"
# include "error.h"
# include "../libft/libft.h"

# define CUBE "Cub3D"
# define DOT_CUB ".cub\0"
# define NO "NO\0"
# define SO "SO\0"
# define WE "WE\0"
# define EA "EA\0"
# define F "F\0"
# define C "C\0"
# define WIDTH 800
# define HEIGHT 800
# define TEX_WIDTH 64
# define TEX_HEIGHT 64
# define TILE_SIZE 64

/*			Clean up functions				*/
int			free_p(t_d *p);
void		free_texture(t_texture *t, void *mlx);
void		free_color(t_color *c);
void		free_player(t_player *p);

/*			Initalization functions			*/
t_d			*init(void);
t_texture	*init_texture(void *mlx, char *img_path);
t_color		*init_color(char *color);
void		init_player(t_d *p);
t_color		*init_player_color(void);

/*			Event handlers					*/
void        update_player(t_player *p);
int			key_press(int keycode, void *p);
int			key_release(int keycode, void *p);


/*			Error functions					*/
void		disp_err(const char *error);

/*			Parsing functions				*/
int			is_valid_parsing(int ac, char **av, t_d *p);
int			is_suffix(const char *s, const char *suffix);
int			is_valid_key(int keycode);
int			ft_isprefix(const char *s, const char *prefix);
int			validate_map(int fd, t_d *p);

/*			Rendering related functions				*/
int			game_loop(t_d *p);
void		put_pixel(t_d *p, int x, int y, int color);
int			rgb_to_int(t_color *c);
void		render_map(t_d *p);
void		draw_grid(t_d *p, int x, int y, t_color *c);
void		render_player(t_d *p);
void		clear_image_buffer(t_d *p);
void        render_direction(t_d *p, int pw, int ph);
void        raycast_in_2d(t_d *p);
void        get_inital_dist(float *stepx, float *stepy, float rdx, float rdy);

/*			Map related functions				*/
char		**read_map(int fd, t_d *p);
size_t		get_max_width(char **map);
char		set_direction(char c);
void		normalize_map_2(char **om, char **nm, size_t mw, size_t mh);
char		**normalize_map_1(char **om);
#endif