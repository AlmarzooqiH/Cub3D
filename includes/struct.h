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
# include <stdio.h>

/*			Player Related Macros				*/
# define PLAYER_COLOR "203,10,8\0"
# define RAY_COLOR "46,90,192\0"
# define ROTATION_SPEED 0.05f
# define MOVEMENT_SPEED 0.2f
# define N_RAYS 120

typedef enum e_side
{
	EAST,
	WEST,
	SOUTH,
	NORTH
}	t_side;

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

/**
 * @brief This struct holds the data of the ray that we will be sending.
 * @var	hit We will use this to know when to end the loop of the digital diff-
 * -rential analysis for the ray casting.
 * @var mapx This will hold the X position of the wall that we hit. Inital val
 * ue will be ppx of the s_player struct.
 * @var mapy This will hold the Y position of the wall that we hit. Inital val
 * ue will be ppy of the s_player struct.
 * @var rdx This hold the ray direction in the X position. It is also the pdx
 * of the s_player struct.
 * @var rdy This hold the ray direction in the Y position. It is also the pdy
 * of the s_player struct.
 * @var rpx This holds the ray inital position.  It is also the ppx
 * of the s_player struct.
 * @var rpy This holds the ray inital position.  It is also the ppy
 * of the s_player struct.
 * @var ddx This is holds the inital distance that we want to travel in the X
 * axis.
 * @var ddy This is holds the inital distance that we want to travel in the Y
 * axis.
 * @var sdx This is holds the side distance that we want to travel in the X
 * axis.
 * @var sdy This is holds the side distance that we want to travel in the Y
 * axis.
 * @var step_x This will holds the steps that we need to travel in the X axis,
 * this will be used to increment mapx.
 * @var step_y This will holds the steps that we need to travel in the X axis,
 * this will be used to increment mapy.
 * @var dist The will hold the distance between point 1 to point 2.
 * @var angle this will be used to send the rays in multiple directions.
 * @var side This will store which direction that ray hits. Checkout the
 * side enum.
 * @var color The ray color.
*/
typedef struct s_ray
{
	int		hit;
	int		mapx;
	int		mapy;
	float	rdx;
	float	rdy;
	float	rpx;
	float	rpy;
	float	ddx;
	float	ddy;
	float	sdx;
	float	sdy;
	int		step_x;
	int		step_y;
	float	dist;
	float	angle;
	int		side;
	t_color	*color;
}	t_ray;

/**
 * @brief This struct holds the player information.
 * @var	ppx is the player X position in the map.
 * @var	ppy is the player Y position in the map.
 * @var	pdx is the player X direction.
 * @var	pdy is the player Y direction.
 * @var	angle is the player angle.
 * @var	camera_x is the camera X plane.
 * @var	camera_y is the camera Y plane.
 * @var rotate This will be set to 1 if the left key was pressed then will be
 * checked when we will draw the player to do rotation.
 * @var w_pressed This will hold if the W button was pressed to simulate conti
 * nues movement.
 * @var a_pressed This will hold if the A button was pressed to simulate conti
 * nues movement.
 * @var s_pressed This will hold if the S button was pressed to simulate conti
 * nues movement.
 * @var d_pressed This will hold if the D button was pressed to simulate conti
 * nues movement.
 * @var lk_pressed This will hold if the LK button was pressed to simulate con
 * tinues rotation.
 * @var rk_pressed This will hold if the RK button was pressed to simulate con
 * tinues rotation.
 * @var	color is the player color.
 * @var ray This will store the ray that we will send to raycast.
 */
typedef struct s_player
{
	double	ppx;
	double	ppy;
	double	pdx;
	double	pdy;
	double	angle;
	double	camera_x;
	double	camera_y;
	int		rotate;
	int		w_pressed;
	int		a_pressed;
	int		s_pressed;
	int		d_pressed;
	int		lk_pressed;
	int		rk_pressed;
	t_color	*color;
	t_ray	*ray;
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
 * @var	grid_width This holds the grid width relative to the map.
 * @var	grid_height This holds the grid height relative to the map.
 */
typedef struct s_2d
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*imgd;
	char		**map;
	size_t		map_width;
	size_t		map_height;
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
	t_player	*player;
	int			grid_width;
	int			grid_height;
}	t_d;

#endif