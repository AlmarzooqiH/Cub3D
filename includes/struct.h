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
# include "../minilibx-linux/mlx.h"
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define LK 65361
# define RK 65363
# endif
# ifdef __APPLE__
#include "../minilibx/mlx.h"
# endif
typedef	struct s_2d
{
	void	*mlx;
	void	*win;
	int		endian;
} t_d;

#endif