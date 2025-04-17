/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chartrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaes <lmaes@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:37:21 by lmaes             #+#    #+#             */
/*   Updated: 2024/04/23 10:55:51 by lmaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_chartrim(char *s, char set)
{
	char	*start;
	char	*end;
	char	*new_str;

	if (!s)
		return (NULL);
	start = s;
	end = s + ft_strlen(s) - 1;
	while (*start == set)
		start++;
	while (end > start && *end == set)
		end--;
	new_str = ft_strndup(start, end - start + 1);
	return (new_str);
}
