/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 05:28:53 by hamad             #+#    #+#             */
/*   Updated: 2025/04/07 05:33:41 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/error.h"

/**
 * @brief This function will display and error followed by an error message.
 * @param	error An error message from includes/error.h. (Can be NULL)
 * @return (void)
 */
void	disp_err(const char *error)
{
	printf("Error\n");
	if (error != NULL)
		printf("%s", error);
}
