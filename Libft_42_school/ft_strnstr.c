/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:44:24 by ivda-cru          #+#    #+#             */
/*   Updated: 2021/12/10 15:54:56 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)hay);
	while (hay[i] != '\0')
	{
		j = 0;
		while (hay[i + j] == needle[j] && (i + j) < len)
		{
			if (hay[i + j] == '\0' && needle[j] == '\0')
				return ((char *)&hay[i]);
			j++;
		}
		if (needle[j] == '\0')
			return ((char *)hay + i);
		i++;
	}
	return (0);
}
