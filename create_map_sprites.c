/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_sprites.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 11:30:09 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/11/03 13:25:18 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keyboard(int keycode, t_tudo *tudo)
{
	if (keycode == 119)
		move_sprite(tudo, -1, 0);
	else if (keycode == 97)
		move_sprite(tudo, 0, -1);
	else if (keycode == 115)
		move_sprite(tudo, 1, 0);
	else if (keycode == 100)
		move_sprite(tudo, 0, 1);
	else if (keycode == 65307)
		exit_game(tudo);
	return (0);
}

t_sprites	create_sprites(void *mlx_init)
{
	int			x;
	int			y;
	t_sprites	img;

	img.sapo1 = mlx_xpm_file_to_image(mlx_init, "./sprites/player.xpm", &x, &y);
	img.grass1 = mlx_xpm_file_to_image(mlx_init, "./sprites/grass.xpm", &x, &y);
	img.wall1 = mlx_xpm_file_to_image(mlx_init, "./sprites/wall.xpm", &x, &y);
	img.exit1 = mlx_xpm_file_to_image(mlx_init, "./sprites/exit.xpm", &x, &y);
	img.collectible1 = \
	mlx_xpm_file_to_image(mlx_init, "./sprites/collectible.xpm", &x, &y);
	img.polluted_water = \
	mlx_xpm_file_to_image(mlx_init, "./sprites/lake_pollu.xpm", &x, &y);
	return (img);
}

void	insert_sprites(t_tudo *tudo, int i, int j)
{
	if (tudo->map.full_map[i][j] == '1')
		mlx_put_image_to_window(tudo->mlx_init, tudo->mlx_window, \
		tudo->sprites.wall1, j * 44, i * 44);
	else if (tudo->map.full_map[i][j] == '0')
		mlx_put_image_to_window(tudo->mlx_init, tudo->mlx_window, \
		tudo->sprites.grass1, j * 44, i * 44);
	else if (tudo->map.full_map[i][j] == 'P')
		mlx_put_image_to_window(tudo->mlx_init, tudo->mlx_window, \
		tudo->sprites.sapo1, j * 44, i * 44);
	else if (tudo->map.full_map[i][j] == 'C')
		mlx_put_image_to_window(tudo->mlx_init, tudo->mlx_window, \
		tudo->sprites.collectible1, j * 44, i * 44);
	else if (tudo->map.full_map[i][j] == 'E')
	{
		mlx_put_image_to_window(tudo->mlx_init, tudo->mlx_window, \
		tudo->sprites.polluted_water, j * 44, i * 44);
		tudo->indexs.exit_i = i;
		tudo->indexs.exit_j = j;
	}
	else if (tudo->map.full_map[i][j] == 'F')
		mlx_put_image_to_window(tudo->mlx_init, tudo->mlx_window, \
		tudo->sprites.exit1, tudo->indexs.exit_j * 44, \
		tudo->indexs.exit_i * 44);
}

void	move_sprite(t_tudo *tudo, int x, int y)
{
	loop_grid(tudo);
	if (tudo->map.full_map[tudo->indexs.i + x][tudo->indexs.j + y] != '1' && \
	tudo->map.full_map[tudo->indexs.i + x][tudo->indexs.j + y] != 'E')
	{
		tudo->move_count++;
		ft_printf("Number of moves: %d\n", tudo->move_count);
		if (tudo->map.full_map[tudo->indexs.i + x][tudo->indexs.j + y] == 'F')
		{
			ft_printf("//////Congratulations, you finish the game with");
			ft_printf(" %d moves\\\\\\\\\\ \n", tudo->move_count);
			exit_game(tudo);
		}
		if (tudo->map.full_map[tudo->indexs.i + x][tudo->indexs.j + y] == 'C')
			tudo->collectible_total--;
		tudo->map.full_map[tudo->indexs.i + x][tudo->indexs.j + y] = 'P';
		tudo->map.full_map[tudo->indexs.i][tudo->indexs.j] = '0';
		if (tudo->collectible_total == 0)
			tudo->map.full_map[tudo->indexs.exit_i][tudo->indexs.exit_j] = 'F';
		loop_map_grid(tudo);
	}
}
