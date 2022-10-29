/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 12:47:22 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/10/30 00:00:59 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void error(char *text)
{
    ft_printf("Error\n");
    ft_printf("%s", text);
    exit(0);
}

void error_free_m(t_tudo *tudo, char *text)
{
    ft_printf("Error\n");
    ft_printf("%s", text);
    free(tudo->mlx_init);
    free_map(tudo->map.full_map);
    //free_map(tudo->map.tmp_grid);
    exit(0);
}



void check_map(t_tudo *tudo)
{
    check_chars(tudo, tudo->map.full_map);
    check_number_of_sprites(tudo);
    wall_check(tudo);
    
}
    
void wall_check(t_tudo *tudo)
 {  
    int i;
    int j;
    
    i = 0;
    j = 0;    
    while(i < tudo->map.height)
    {         
        j = 0;
        if  (tudo->map.full_map[i][0] != '1' || tudo->map.full_map[i][tudo->map.width - 1] != '1')
         error_free_m(tudo, "Map must be surrounded by walls\n");        
        while(j < tudo->map.width)
        {
            if  (tudo->map.full_map[0][j] != '1' || tudo->map.full_map[tudo->map.height - 1][j] != '1')
                error_free_m(tudo, "Map must be surrounded by walls\n");   
            j++;
        }
        i++;
    }
    if  (tudo->map.width == tudo->map.height)
        error_free_m(tudo, "Map cannot be a square!\n");
}

void check_number_of_sprites(t_tudo *tudo)
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


void check_valid_path(t_tudo *tudo)
{
    int x;
    int y;    
    
    loop_grid(tudo);
    loop_grid_collectible(tudo);    
    y = tudo->indexs.i;
    x = tudo->indexs.j;    
    tudo->collectible_debug_count = tudo->collectible_total;
    ft_validmap_check(tudo, x, y);     
    ft_printf("Collectible debug: %d\n", tudo->collectible_debug_count);
    ft_printf("exit debug total: %d\n", tudo->exit_count);    
    if (tudo->collectible_debug_count != 0 || tudo->exit_count != 1)
    {
        free_map(tudo->map.tmp_grid);
        free_map(tudo->map.full_map);
		error("There isn't a valid way to go exit.\n");
    }
      else
        ft_printf("valid path\n");
    free_map(tudo->map.tmp_grid);
    ft_printf("counts: %d\n", tudo->exit_count);
    tudo->collectible_total = 0;    
}

void	ft_validmap_check(t_tudo *tudo, int x, int y)
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
			ft_validmap_check(tudo, x + 1, y);
		if (tudo->map.tmp_grid[y][x - 1] != '1' &&
			tudo->map.tmp_grid[y][x - 1] != 'V')
			ft_validmap_check(tudo, x - 1, y);
		if (tudo->map.tmp_grid[y - 1][x] != '1' &&
			tudo->map.tmp_grid[y - 1][x] != 'V')
			ft_validmap_check(tudo, x, y - 1);
		if (tudo->map.tmp_grid[y + 1][x] != '1' &&
			tudo->map.tmp_grid[y + 1][x] != 'V')
			ft_validmap_check(tudo, x, y + 1);
	}
}

/* void	ft_validmap_check(t_tudo *tudo, int x, int y)
{
	char	*p;

	p = &tudo->map.full_map[y][x];
	if (*p == 'E')
		tudo->exit_count = 1;
	if (*p != 'E' && *p != '1')
	{
		if (*p == 'C')
			tudo->collectible_debug_count--;
		*p = '.';
		if (tudo->map.full_map[y][x + 1] != '1' &&
			tudo->map.full_map[y][x + 1] != '.')
			ft_validmap_check(tudo, x + 1, y);
		if (tudo->map.full_map[y][x - 1] != '1' &&
			tudo->map.full_map[y][x - 1] != '.')
			ft_validmap_check(tudo, x - 1, y);
		if (tudo->map.full_map[y - 1][x] != '1' &&
			tudo->map.full_map[y - 1][x] != '.')
			ft_validmap_check(tudo, x, y - 1);
		if (tudo->map.full_map[y + 1][x] != '1' &&
			tudo->map.full_map[y + 1][x] != '.')
			ft_validmap_check(tudo, x, y + 1);
	}
} */

/* oid	ft_path_check(t_map *data)
{
	int	i;

	i = 0;
	while (data->maps2[i])
	{
		free(data->maps2[i]);
		i++;
	}
	free(data->maps2);
	if (data->collect_algo != 0 || data->valid_e != 1)
		ft_error("Error! There isn't valid way to go exit.");
} */


/* int paint_next_step(int x, int y, t_tudo *tudo)
{
	tudo->map.full_map[x][y] = ' ';
	if (x + 1 < tudo->map.height - 1)
	{
        ft_printf("entrou em x + 1\n");
		if (check_next_step(tudo, x + 1, y) == 1)
			paint_next_step(x + 1, y, tudo);
            
	}
	if (x - 1 > 0)
	{
        ft_printf("entrou em x - 1\n");
		if (check_next_step(tudo, x - 1, y) == 1)
			paint_next_step(x - 1, y, tudo);
            
	}
	if (y + 1 < tudo->map.width - 1)
	{
        ft_printf("entrou em y + 1\n");
		if (check_next_step(tudo, x, y + 1) == 1)
			paint_next_step(x, y + 1, tudo);
            
	}
	if (y - 1 > 0)
	{
        ft_printf("entrou em y - 1\n");
		if (check_next_step(tudo, x, y - 1) == 1)
			paint_next_step(x, y - 1, tudo);
            
	}
	return (0);
}

int	check_next_step(t_tudo *tudo, int x, int y)
{
	if (tudo->map.full_map[x][y] == 'C')
	{
		tudo->collectible_debug_count++;
		return (1);
	}
	else if (tudo->map.full_map[y][x] == 'E' && tudo->exit_count < 1)
	{
		tudo->exit_count++;
		return (0);
	}
	else if (tudo->map.full_map[y][x] == '0')
	{
		return (1);
	}
	return (0);
} */

/* int	check_path(t_data *game)
{
	t_check	valid_path;

	set_path_check(game, &valid_path);
	if (valid_path.coins != game->map->objects->n_collectibles)
		set_shutdown(0, game, "Error\nThere's something in the way.\n");
	if (valid_path.exit != game->map->objects->n_exits)
		set_shutdown(0, game, "Error\nThere's something in the way.\n");
	return (0);
} */

/* int	i;
    
	i = 0;
    tudo->map.tmp_grid = (char **)malloc(sizeof(char *) * tudo->map.height * tudo->map.width);
	while (i < tudo->map.height)
	{
		tudo->map.tmp_grid[i] = ft_strdup(tudo->map.full_map[i]);
        ft_memcpy(tudo->map.tmp_grid[i], tudo->map.full_map[i], tudo->map.width);
        
		i++;
	}    */