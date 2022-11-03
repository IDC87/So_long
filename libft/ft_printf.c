/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:22:57 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/10/31 11:44:50 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*unsigned_func(unsigned int n)
{
	char	*num;
	int		len;

	len = len_n10(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (NULL);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (num);
}

int	unsigned_func_2(unsigned int n)
{
	char	*num;
	int		out_len;

	out_len = 0;
	if (n == 0)
		return (write(1, "0", 1));
	else
	{
		num = unsigned_func(n);
		out_len = out_len + ft_putstr(num);
	}
	free(num);
	return (out_len);
}

int	get_specifier(va_list arg, const char *string, int i)
{
	int	ret;

	ret = 0;
	if (string[i + 1] == 'c')
		ret = ret + ft_putchar(va_arg(arg, int));
	else if ((string[i + 1] == 'd') || (string[i + 1] == 'i'))
		ret = ret + ft_putchar_num(va_arg(arg, int));
	else if (string[i + 1] == 's')
		ret = ret + ft_putstr(va_arg(arg, char *));
	else if (string[i + 1] == 'p')
		ret = ret + put_hex_p(va_arg(arg, unsigned long long));
	else if (string[i + 1] == 'u')
		ret = ret + unsigned_func_2(va_arg(arg, unsigned int));
	else if (string[i + 1] == 'x')
		ret = ret + hex_converter_lower(va_arg(arg, unsigned long long));
	else if (string[i + 1] == 'X')
		ret = ret + hex_converter_upper(va_arg(arg, unsigned int));
	else if (string[i + 1] == '%')
		ret = ret + ft_putchar(string[i + 1]);
	return (ret);
}

int	ft_printf(const char *string, ...)
{
	va_list	arg;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	va_start(arg, string);
	while (string[i])
	{
		if (string[i] != '%')
			ret = ret + write(1, &string[i], 1);
		else
		{
			ret = ret + get_specifier(arg, string, i);
			i++;
		}
		i++;
	}
	va_end(arg);
	return (ret);
}
