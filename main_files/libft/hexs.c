/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:31:34 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/05/26 15:31:34 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	hex_converter(unsigned long long n)
{
	int	ret;

	ret = 0;
	if (n == 0)
		return (write(1, "0", 1));
	if (n >= 16)
	{
		hex_converter(n / 16);
		hex_converter(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar(n + '0');
		else
			ft_putchar(n - 10 + 'a');
	}
	ret = ret + len_n16(n);
	return (ret);
}

int	hex_converter_lower(unsigned int n)
{
	int	ret;

	ret = 0;
	if (n == 0)
		return (write(1, "0", 1));
	if (n >= 16)
	{
		hex_converter(n / 16);
		hex_converter(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar(n + '0');
		else
			ft_putchar(n - 10 + 'a');
	}
	ret = ret + len_n16(n);
	return (ret);
}

int	hex_converter_upper(unsigned int n)
{
	int	ret;

	ret = 0;
	if (n == 0)
		return (write(1, "0", 1));
	if (n >= 16)
	{
		hex_converter_upper(n / 16);
		hex_converter_upper(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar(n + '0');
		else
			ft_putchar(n - 10 + 'A');
	}
	ret = ret + len_n16(n);
	return (ret);
}

int	put_hex_p(unsigned long long n)
{
	int	ret;

	ret = 0;
	ret = ret + write(1, "0x", 2);
	if (n == 0)
		ret = ret + (write(1, "0", 1));
	else
	{
		hex_converter(n);
		ret = ret + len_n16(n);
	}
	return (ret);
}
//done
