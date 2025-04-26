/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 18:11:32 by hamalmar          #+#    #+#             */
/*   Updated: 2025/04/04 18:11:32 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define WIN_EXIT 17

# ifdef __linux__
#  include "../minilibx-linux/mlx.h"
#  define ESC 65307
#  define W 119
#  define A 97
#  define S 115
#  define D 100
#  define LK 65361
#  define RK 65363
# endif
# ifdef __APPLE__
#  include "../minilibx/mlx.h"
#  define ESC 53
#  define W 13
#  define A 0
#  define S 1
#  define D 2
#  define LK 123
#  define RK 124
# endif

/**
 * @brief This struct will hold color values.
 * @var	r red color, ranges from 0 - 255.
 * @var	g green color, ranges from 0 - 255.
 * @var	b blue color, ranges from 0 - 255.
 * @note We will get those values from the map input file.
 */
typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

/**
 * @brief This struct will hold the texture information.
 * @var	width This will store the width of the image.
 * @var	height This will store the width of the image.
 * @var	img	This will hold the pointer of the image data.
 * @note We will get those data from mlx mlx_xpm_file_to_image().
 */
typedef struct s_texture
{
	int		width;
	int		height;
	void	*img;
}	t_texture;

typedef struct s_player
{
	double	x;       // Player X position
	double	y;       // Player Y position
	double	dir_x;   // Direction X
	double	dir_y;   // Direction Y
	double	plane_x; // Camera plane X
	double	plane_y; // Camera plane Y
}	t_player;

/**
 * @brief This is where the window data will be stored at.
 * @var	mlx The mlx connection to the mlx libarary.
 * @var win The window data.
 * @var	img This will hold the image pointer.
 * @var	edn This will store if the system uses Small/Big endian.
 * @var	imgd This will hold the image data. This variable will be used to mani-
 * -pulate what is displayed.
 * @var	map This is where the map will be stored in.
 * @var	bpp bits per pixel will be  filled  with  the  number of bits needed t-
 * -represent a pixel color (also called the depth of the  image).
 * @var	sl Size line is  the number  of  bytes  used to store one line of the
 * image in memory.
 * @var	e Will hold the texture of the east wall.
 * @var	w Will hold the texture of the west wall.
 * @var	s Will hold the texture of the south wall.
 * @var	n Will hold the texture of the north wall.
 * @var	floor Will hold the color of the floors.
 * @var	ceiling Will hold the color of the ceiling.
 */
typedef struct s_2d
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*imgd;
	char		**map;
	int			map_size;
	int			edn;
	int			bpp;
	int			sl;
	t_texture	*e;
	t_texture	*w;
	t_texture	*s;
	t_texture	*n;
	t_color		*floor;
	t_color		*ceiling;
	t_player	player;
}	t_d;

#endif