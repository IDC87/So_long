/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 12:47:22 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/11/03 00:40:50 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_map(t_tudo *tudo)
{
	check_chars(tudo, tudo->map.full_map);
	check_number_of_sprites(tudo);
	wall_check(tudo);
}

void	wall_check(t_tudo *tudo)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < tudo->map.height)
	{
		j = 0;
		if (tudo->map.full_map[i][0] != '1' || \
		tudo->map.full_map[i][tudo->map.width - 1] != '1')
			error_and_free(tudo, "Map must be surrounded by walls\n");
		while (j < tudo->map.width)
		{
			if (tudo->map.full_map[0][j] != '1' || \
			tudo->map.full_map[tudo->map.height - 1][j] != '1')
				error_and_free(tudo, "Map must be surrounded by walls\n");
			j++;
		}
		i++;
	}
	if (tudo->map.width == tudo->map.height)
		error_and_free(tudo, "Map cannot be a square!\n");
}

void	check_number_of_sprites(t_tudo *tudo)
{
	loop_number_of_sprites(tudo);
	loop_grid(tudo);
	if (tudo->exit_count != 1)
	{
		free_map(tudo->map.full_map);
		free_map(tudo->map.tmp_grid);
		error("Must have only one exit\n");
	}
	if (tudo->player_count != 1)
	{
		free_map(tudo->map.full_map);
		free_map(tudo->map.tmp_grid);
		error("Must have only 1 Player start\n");
	}
	if (tudo->collectible_count == 0)
	{
		free_map(tudo->map.full_map);
		free_map(tudo->map.tmp_grid);
		error("Must have at least one collectible\n");
	}
}

void	check_valid_path(t_tudo *tudo)
{
	int	x;
	int	y;

	loop_grid(tudo);
	loop_grid_collectible(tudo);
	y = tudo->indexs.i;
	x = tudo->indexs.j;
	tudo->collectible_debug_count = tudo->collectible_total;
	nodes_vector(tudo, x, y);
	if (tudo->collectible_debug_count != 0 || tudo->exit_count != 1)
	{
		free_map(tudo->map.tmp_grid);
		free_map(tudo->map.full_map);
		error("There isn't a valid way to go exit.\n");
	}
	free_map(tudo->map.tmp_grid);
	tudo->collectible_total = 0;
}

void	nodes_vector(t_tudo *tudo, int x, int y)
{
	if (tudo->map.tmp_grid[y][x] == 'E')
		tudo->exit_count = 1;
	if (tudo->map.tmp_grid[y][x] != 'E' && tudo->map.tmp_grid[y][x] != '1')
	{
		if (tudo->map.tmp_grid[y][x] == 'C')
			tudo->collectible_debug_count--;
		tudo->map.tmp_grid[y][x] = 'V';
		if (tudo->map.tmp_grid[y][x + 1] != '1' &&
			tudo->map.tmp_grid[y][x + 1] != 'V')
			nodes_vector(tudo, x + 1, y);
		if (tudo->map.tmp_grid[y][x - 1] != '1' &&
			tudo->map.tmp_grid[y][x - 1] != 'V')
			nodes_vector(tudo, x - 1, y);
		if (tudo->map.tmp_grid[y - 1][x] != '1' &&
			tudo->map.tmp_grid[y - 1][x] != 'V')
			nodes_vector(tudo, x, y - 1);
		if (tudo->map.tmp_grid[y + 1][x] != '1' &&
			tudo->map.tmp_grid[y + 1][x] != 'V')
			nodes_vector(tudo, x, y + 1);
	}
}
