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