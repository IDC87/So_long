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

void	*ft_calloc(size_t nmeb, size_t size)
{
	char	*str;

	str = (void *)malloc(nmeb * size);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, nmeb * size);
	return (str);
}
/* void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(size * count);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
} */

//podera estar certo, verificar se e com o char nulo que se usa!

/* int main(int argc, char **argv)
{
    char *str = argv[1];
    printf("\nYour chosen string has: %ld chars\n\n", strlen(str));
     char * str2;     
     str2 = (char *)ft_calloc(strlen(str + 4), sizeof(char));
    memmove(str2, str, strlen(str));     

    printf("\nCopied string is: %s\n\n", str2 + 4);

    free(str2);

    return (0);
} */

// void *malloc(size_t n_bytes)
