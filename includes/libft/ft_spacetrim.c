/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spacetrim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaes <lmaes@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:37:21 by lmaes             #+#    #+#             */
/*   Updated: 2024/04/23 10:55:51 by lmaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_spacetrim(char *s)
{
	char	*start;
	char	*end;
	char	*new_str;

	if (!s)
		return (NULL);
	start = s;
	end = s + ft_strlen(s) - 1;
	while (ft_isspace(*start))
		start++;
	while (end > start && ft_isspace(*end))
		end--;
	new_str = ft_strndup(start, end - start + 1);
	return (new_str);
}
