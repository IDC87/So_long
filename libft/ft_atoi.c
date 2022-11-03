/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 10:26:15 by ivda-cru          #+#    #+#             */
/*   Updated: 2021/12/13 17:35:21 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	sig;
	int	j;

	sig = 1;
	j = 0;
	while ((str[j] == ' ' || (str[j] >= '\t' && str[j] <= '\r')) && str[j])
		j++;
	if ((str[j] == '+' || str[j] == '-') && str[j] != '\0')
	{
		if (str[j] == '-')
			sig = sig * (-1);
		j++;
	}
	res = 0;
	while ((str[j] >= '0' && str[j] <= '9') && str[j] != '\0')
	{
		res = res * 10;
		res = res + (str[j] - '0');
		j++;
	}
	return (res * sig);
}
