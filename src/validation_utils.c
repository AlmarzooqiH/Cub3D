/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 00:53:59 by hamad             #+#    #+#             */
/*   Updated: 2025/04/14 11:30:49 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief This function will check if prefix in s.
 * @param	s The strnig that we want to check the prefix.
 * @param	prefix The prefix that we want to check in s.
 * @return	1 if prefix is in s. 0 othrewise.
 */
int	ft_isprefix(const char *s, const char *prefix)
{
	size_t	i;

	if (!s || !prefix || (ft_strlen(s) < ft_strlen(prefix)))
		return (0);
	i = 0;
	while ((s[i] != '\0' && prefix[i] != '\0') && prefix[i] == s[i])
		i++;
	return (!prefix[i]);
}

/**
 * @brief	This function will check if the string has the correct suffix.
 * @param	s The string we want to check.
 * @param	suffix The suffix we want to check
 * @return 1 if the file name is valid, 0 otherwise.
 */
int	is_suffix(const char *s, const char *suffix)
{
	int	i;
	int	j;

	if (!s || !suffix || (ft_strlen(s) < ft_strlen(suffix)))
		return (0);
	i = 0;
	while (s[i] != '\0' && s[i] != suffix[0])
		i++;
	if (s[i] == '\0')
		return (0);
	j = 0;
	while ((s[i] != '\0' && suffix[j] != '\0') && (s[i] == suffix[j]))
	{
		i++;
		j++;
	}
	return (s[i] == '\0' && suffix[j] == '\0');
}
