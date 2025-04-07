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
# endif

/**
 * @brief This is where the window data will be stored at.abort
 * @var	mlx The mlx connection to the mlx libarary.
 * @var win The window data.
 * @var	img This will hold the image pointer.
 * @var	edn This will store if the system uses Small/Big endian.
 * @var	imgd This will hold the image data. This variable will be used to mani-
 * -pulate what is displayed.
 * @var	bpp bits per pixel will be  filled  with  the  number of bits needed t-
 * -represent a pixel color (also called the depth of the  image).
 * @var	sl Size line is  the number  of  bytes  used to store one line of the
 * image in memory.
 */
typedef struct s_2d
{
	void	*mlx;
	void	*win;
	void	*img;
	int		edn;
	char	*imgd;
	int		bpp;
	int		sl;
}	t_d;

#endif