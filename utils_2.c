/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:32:39 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/10/29 17:30:14 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] != '\0' && str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
				return (&str[i]);
			++j;
		}
		++i;
	}
	return (0);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*tempdst;
	const char	*tempsrc;

	if (dst == 0 && src == 0)
		return (0);
	i = 0;
	tempdst = dst;
	tempsrc = src;
	while (i < n)
	{
		tempdst[i] = tempsrc[i];
		i++;
	}
	return (dst);
}

/* char	*ft_strdup(const char *s)
{
	int		i;
	char	*str;

	str = NULL;
	i = 0;
	str = (char *)malloc(sizeof(*s) * ft_strlen(s) + 1);
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
} */

