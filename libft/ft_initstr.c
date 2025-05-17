/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 02:50:12 by hamad             #+#    #+#             */
/*   Updated: 2025/05/18 02:57:18 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_str	*ft_initstr(const char *str)
{
	t_str	*new_s;

	if (!str)
		return (NULL);
	new_s = (t_str *)ft_calloc(1, sizeof(t_str));
	if (!new_s)
		return (NULL);
	new_s->s = ft_strdup(str);
	if (!new_s->s)
		return (free(new_s), NULL);
	new_s->length = ft_strlen(str);
	return (new_s);
}
