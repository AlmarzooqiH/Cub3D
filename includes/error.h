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

/*  Input failure messages  */
# define WRONG_INPUT "Input must be ./cub3D *.cub file.\n\0"
# define INVALID_FILE "File must be *.cub file\n\0"
# define FILE_DOESNT_EXSIST "File does not exists\n\0"

/*  Memorey allocation failure messages.  */
# define FTCM "Failed to calloc memorey\n\0"
# define FTIT "Failed to init texture\n\0"
# define FTIC "Failed to init color\n\0"
/*      Mlx failure messages        */
# define FTIM "Failed to init mlx\n\0"
# define FTIW "Failed to init the window\n\0"
# define FTCI "Failed to create an image\n\0"
# define FTGID "Failed to get the image data\n\0"
# define FTF "Failed to open the file\n\0"
#endif