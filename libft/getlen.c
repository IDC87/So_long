/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_getLen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:31:26 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/05/26 15:31:26 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	len_n16(unsigned long long n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

int	len_n10(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

int	ft_putchar_rev(unsigned long long n, int len)
{
	while (len >= 0)
	{
		ft_putchar(n);
		len--;
	}
	return (1);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putchar_num(int n)
{
	char	*str;
	int		len;	

	str = ft_itoa(n);
	if (!str)
		return (0);
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	return (len);
}
