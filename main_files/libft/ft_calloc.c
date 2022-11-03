/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:34:38 by marvin            #+#    #+#             */
/*   Updated: 2021/12/08 15:34:27 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	byte;

	byte = count * size;
	if (byte && (byte < count || byte < size))
		return (NULL);
	ptr = malloc(byte);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, byte);
	return (ptr);
}
