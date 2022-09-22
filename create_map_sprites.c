/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   another_version.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 11:30:09 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/09/22 16:43:21 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void create_map(char *filename, t_grid *map)
{
    size_t bytes_read;
    char *buf;
    
    int i;
    int j;

    map->width = 0;
    map->height = 0;
    
    map->fd = open(filename, O_RDONLY);
    buf = (char *)malloc(sizeof(char) * BUFFER_COUNT);
    bytes_read = read(map->fd, buf, BUFFER_COUNT);
    buf[bytes_read] = '\0';

    map->map_grid = ft_split(buf, '\n');
    map->width = ft_strlen_long(map->map_grid[0]);

    map->height = bytes_read / map->width; 

    if (map->width < map->height)
        map->height--;

    i = 0;
    j = 0;
    
    printf("\n");    
    
    printf("MAP DIMENSION: [%d] X [%d]\n", map->width, map->height);
    while(i < map->height)//quando este valor e superior ao width da seg fault
    {
        j = 0;
        while(j < map->width)
        {
            printf("[%c]", map->map_grid[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    printf("\n");
    printf("bytes of the file are: %ld\n", bytes_read);
    free(buf);
    
}

void create_sprites(t_tudo *tudo)
{
    tudo->sprites.sapo1 = mlx_xpm_file_to_image(tudo->mlx_init, sapinho, 
            &tudo->sapo_x, &tudo->sapo_y);
    tudo->sprites.grass1 = mlx_xpm_file_to_image(tudo->mlx_init, grass, 
            &tudo->sapo_x, &tudo->sapo_y);
    tudo->sprites.wall1 = mlx_xpm_file_to_image(tudo->mlx_init, wall, 
            &tudo->sapo_x, &tudo->sapo_y);
    tudo->sprites.exit1 = mlx_xpm_file_to_image(tudo->mlx_init, player_exit, 
            &tudo->sapo_x, &tudo->sapo_y);
    tudo->sprites.collectible1 = mlx_xpm_file_to_image(tudo->mlx_init, player_collectible, 
            &tudo->sapo_x, &tudo->sapo_y);
    tudo->sprites.polluted_water = mlx_xpm_file_to_image(tudo->mlx_init, polluted_lake, 
            &tudo->sapo_x, &tudo->sapo_y);
}

void insert_sprites(t_tudo *tudo, int i, int j)
{    
    if (tudo->grid.map_grid[i][j] == '1')
        mlx_put_image_to_window(tudo->mlx_init, tudo->mlx_window, 
        tudo->sprites.wall1, j * 44, i * 44);
    else if (tudo->grid.map_grid[i][j] == '0')
        mlx_put_image_to_window(tudo->mlx_init, tudo->mlx_window, 
        tudo->sprites.grass1, j * 44, i * 44); 
    else if(tudo->grid.map_grid[i][j] == 'P')
        mlx_put_image_to_window(tudo->mlx_init, tudo->mlx_window, 
        tudo->sprites.sapo1, j * 44, i * 44);
    else if (tudo->grid.map_grid[i][j] == 'C')
        mlx_put_image_to_window(tudo->mlx_init, tudo->mlx_window, 
        tudo->sprites.collectible1, j * 44, i * 44);
    else if (tudo->grid.map_grid[i][j] == 'E')
    {
     mlx_put_image_to_window(tudo->mlx_init, tudo->mlx_window, 
        tudo->sprites.polluted_water, j * 44, i * 44);
        tudo->indexs.exit_i = i;
        tudo->indexs.exit_j = j;        
    }
    else if (tudo->grid.map_grid[i][j] == 'F')
        mlx_put_image_to_window(tudo->mlx_init, tudo->mlx_window,
        tudo->sprites.exit1, tudo->indexs.exit_j * 44, tudo->indexs.exit_i * 44);
} 


