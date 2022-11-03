/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:31:55 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/11/02 22:00:55 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_gaps( char *buf, int bytes)
{
	int	i;

	i = 0;
	while (i < bytes)
	{
		if ((buf[i] == '\n' && buf[i + 1] == '\n') \
		|| buf[0] == '\n' || buf[bytes - 1] == '\n')
		{
			free(buf);
			error("Map cannot have gaps &/or empty lines!\n");
		}
		i++;
	}
}

int	exit_game(t_tudo *tudo)
{
	mlx_destroy_image(tudo->mlx_init, tudo->sprites.sapo1);
	mlx_destroy_image(tudo->mlx_init, tudo->sprites.grass1);
	mlx_destroy_image(tudo->mlx_init, tudo->sprites.wall1);
	mlx_destroy_image(tudo->mlx_init, tudo->sprites.exit1);
	mlx_destroy_image(tudo->mlx_init, tudo->sprites.collectible1);
	mlx_destroy_image(tudo->mlx_init, tudo->sprites.polluted_water);
	mlx_destroy_window(tudo->mlx_init, tudo->mlx_window);
	mlx_destroy_display(tudo->mlx_init);
	free(tudo->mlx_init);
	free_map(tudo->map.full_map);
	exit(0);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i++]);
	}
	free(map);
}

void	error(char *text)
{
	ft_printf("Error\n");
	ft_printf("%s", text);
	exit(0);
}

void	error_free_m(t_tudo *tudo, char *text)
{
	ft_printf("Error\n");
	ft_printf("%s", text);
	free(tudo->mlx_init);
	free_map(tudo->map.full_map);
	exit(0);
}
