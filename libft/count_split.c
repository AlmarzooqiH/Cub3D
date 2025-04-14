/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:31:04 by hamad             #+#    #+#             */
/*   Updated: 2025/04/14 11:31:50 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_split(char **argv)
{
	int	count;

	if (!argv || !argv[0])
		return (0);
	count = 0;
	while (argv[count])
		count++;
	return (count);
}