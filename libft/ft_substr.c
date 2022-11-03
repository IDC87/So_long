/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 21:14:46 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/10/30 12:16:50 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*result;
	unsigned int	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len <= start || !len)
		return (ft_strdup(""));
	if (s_len - start < len)
		result = (char *)malloc(s_len - start + 1);
	else
		result = (char *)malloc(len + 1);
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, &s[start], len + 1);
	return (result);
}
