/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:12:32 by ivda-cru          #+#    #+#             */
/*   Updated: 2021/12/10 17:55:45 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*move_it(char *dst, const char *src, size_t len)
{
	char		*tempdst;
	const char	*tempsrc;
	size_t		i;

	tempdst = dst;
	tempsrc = src;
	i = 0;
	if (dst <= src)
	{		
		while (i < len)
		{
			tempdst[i] = tempsrc[i];
			i++;
		}
	}
	else
	{
		i = len - 1;
		while (i < len)
		{
			((unsigned char *)dst)[i] = tempsrc[i];
			i--;
		}
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*str;

	if (dst == 0 && src == 0)
		return (NULL);
	str = move_it(dst, src, len);
	return (str);
}
