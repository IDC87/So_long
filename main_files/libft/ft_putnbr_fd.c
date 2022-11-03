/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 19:58:45 by ivda-cru          #+#    #+#             */
/*   Updated: 2021/12/08 16:48:46 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	cv;

	if (n == -2147483648)
	{
		ft_putnbr_fd(-21, fd);
		ft_putnbr_fd(47483648, fd);
		return ;
	}
	if (n < 0)
	{
		write (fd, "-", 1);
		n = n * -1;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	cv = n % 10 + '0';
	write (fd, &cv, 1);
}
