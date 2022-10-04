/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 12:47:22 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/10/04 12:04:49 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void not_rect(t_grid *map)
{
    if (map->width == map->height)
    {
        printf("ERROR\n Map cannot be a square!\n");
        exit(0);
    }
    
}

void loop_surrounded_by_walls(t_grid *map)
{
    int i;
    int j;
    
    i = 0;
    j = 0;
    
    while(i < map->height)
    {   
        
        j = 0;
        if (map->map_grid[i][0] != '1' || map->map_grid[i][map->width - 1] != '1')
        {
            printf("ERROR\n Map must be surrounded by walls\n");
            exit(0);
        }
        
        while(j < map->width)
        {
            if (map->map_grid[0][j] != '1' || map->map_grid[map->height - 1][j] != '1')
            {
                printf("ERROR\n Map must be surrounded by walls\n");
                exit(0);
            }            
            j++;
        }
        i++;
    }
}

void loop_number_of_sprites(t_grid *map)
{
    int i;
    int j;
    
    i = 0;
    j = 0;
    
    while(i < map->height)
    {
        j = 0;
        while(j < map->width)
        {
            if (map->map_grid[i][j] == 'E')
                map->exit_count++;
            else if (map->map_grid[i][j] == 'P')
                map->player_count++;
            else if (map->map_grid[i][j] == 'C')
                map->collectible_count++;
            j++;
        }
        i++;
    }
}

void check_number_of_sprites(t_grid *map)
{
    loop_number_of_sprites(map);
    
    if (map->exit_count != 1)
    {
      printf("ERROR\n Wrong number of Exits\n");
      printf("Exits total = [%d]\n", map->exit_count);
        exit(0);  
    }
    if (map->player_count != 1)
    {
      printf("ERROR\n Must have at least(or not above) 1 Player start\n");
        exit(0);  
    }
    if (map->collectible_count < 1)
    {
      printf("ERROR\n Must have at least one collectible\n");
        exit(0);  
    }
}
