/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 18:48:01 by ivda-cru          #+#    #+#             */
/*   Updated: 2021/12/10 19:34:04 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* unsigned int	ft_strlen(char *len)
{
	int	j;

	j = 0;
	while (len[j] != '\0')
	{
		j++;
	}
	return (j);
} */

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	j = 0;
	if (size <= ft_strlen(dst))
		return (size + ft_strlen(src));
	i = ft_strlen(dst);
	while (src[j] != '\0' && i + 1 < size)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[j]));
}
/* #include <stdio.h>
int main()
  {
      char str1 [] = "it is \0 everything sucks";
      char str2 [] = "what it is";
 
      printf("%d\n", ft_strlcat(str1, str2, 26));
      printf("%s\n", str1);
     char str0 [] ="it is \0 everything sucks";
     printf("%u\n", ft_strlcat(str0, str2, 26));
     printf("%s\n", str0);
     return (0);
 } */
