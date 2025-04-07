/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 18:12:39 by hamalmar          #+#    #+#             */
/*   Updated: 2025/04/04 18:12:39 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
# include <stdio.h>
/*  Memorey allocation failure messages.  */
# define FTCM "Failed to calloc memorey\n\0"

/*      Mlx failure messages        */
# define FTIM "Failed to init mlx\n\0"
# define FTIW "Failed to init the window\n\0"
#endif