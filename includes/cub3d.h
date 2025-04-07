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

# define WIDTH 800
# define HEIGHT 800

int		free_p(t_d *p);
t_d		*init(void);
void	disp_err(const char *error);
int		key_hook(int key_num, void *p);
#endif