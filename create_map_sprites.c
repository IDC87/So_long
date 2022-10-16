/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_sprites.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 11:30:09 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/10/14 17:56:52 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void create_map(char *filename, t_tudo *tudo)
{
    size_t bytes_read;
    char *buf;
    
    int i;
    int j;

    tudo->grid.width = 0;
    tudo->grid.height = 0;    
    
    tudo->grid.fd = open(filename, O_RDONLY);
    if (tudo->grid.fd == -1)
        {
            perror("Error\n");
            exit(0);            
        }
    buf = (char *)malloc(sizeof(char) * BUFFER_COUNT);
    bytes_read = read(tudo->grid.fd, buf, BUFFER_COUNT);
    buf[bytes_read] = '\0';

    tudo->grid.map_grid = ft_split(buf, '\n');
    tudo->grid.temp_grid = ft_split(buf, '\n');
    tudo->grid.width = ft_strlen_long(tudo->grid.map_grid[0]);

    tudo->grid.height = bytes_read / tudo->grid.width; 

    if (tudo->grid.width < tudo->grid.height)
        tudo->grid.height--;

    free(buf);

    printf("\n");    
    i = 0;
    j = 0;
    printf("MAP DIMENSION: Width[%d] X Height[%d]\n", tudo->grid.width, tudo->grid.height);
    while(i < tudo->grid.height)
    {
        j = 0;
        while(j < tudo->grid.width)
        {
            printf("[%c]", tudo->grid.map_grid[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    printf("\n");
    printf("bytes of the file are: %ld\n", bytes_read);

    

    not_rect(tudo);
    check_number_of_sprites(tudo);
    loop_surrounded_by_walls(tudo);

    
    
    printf("SIZE OF QUEUE: %d\n", tudo->queue.size_of_queue);
    check_valid_path(tudo);
      
    
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


