/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_sprites.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 11:30:09 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/10/30 00:42:57 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void process_map(t_tudo *tudo, char *buf, size_t bytes)
{
    tudo->map.full_map = ft_split(buf, '\n');
    tudo->map.tmp_grid = ft_split(buf, '\n');
    free(buf);      
    tudo->map.width = ft_strlen_long(tudo->map.full_map[0]);
    tudo->map.height  = bytes / tudo->map.width;
    if (tudo->map.width < tudo->map.height)
        tudo->map.height --;     
}

void import_map(char *filename, int fd, t_tudo *tudo)
{
    size_t bytes_read;
    char *buf;
    
    fd = open(filename, O_RDONLY); 
    buf = (char *)malloc(sizeof(char) * BUFFER_COUNT);
    if(!buf || fd <= 0)
    {
        free(buf);
        close(fd); 
        error("No such file or directory\n");       
    }
    bytes_read = read(fd, buf, BUFFER_COUNT);
    check_gaps( buf, bytes_read);
    ft_printf("ALARMA %d\n", bytes_read);
    if (bytes_read <= 14)
    {
        free(buf);
        close(fd); 
        error("File empty or too small to be aceptable\n");        
    }
    buf[bytes_read] = '\0';
    close(fd);    
    process_map(tudo, buf, bytes_read);    
}

void check_gaps( char *buf, int bytes)
{
    int i;

    i = 0;
    while(i < bytes)
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


t_sprites create_sprites(void *mlx_init)
{
    int x;
    int y;
    t_sprites sprite;
    
    sprite.sapo1 = mlx_xpm_file_to_image(mlx_init, sapinho, &x, &y);
    sprite.grass1 = mlx_xpm_file_to_image(mlx_init, grass, &x, &y);
    sprite.wall1 = mlx_xpm_file_to_image(mlx_init, wall, &x, &y);
    sprite.exit1 = mlx_xpm_file_to_image(mlx_init, player_exit, &x, &y);
    sprite.collectible1 = mlx_xpm_file_to_image(mlx_init, player_collectible, &x, &y);
    sprite.polluted_water = mlx_xpm_file_to_image(mlx_init, polluted_lake, &x, &y);
    return (sprite);
}

void insert_sprites(t_tudo *tudo, int i, int j)
{    
    if (tudo->map.full_map[i][j] == '1')
        mlx_put_image_to_window(tudo->mlx_init, tudo->mlx_window, 
        tudo->sprites.wall1, j * 44, i * 44);
    else if (tudo->map.full_map[i][j] == '0')
        mlx_put_image_to_window(tudo->mlx_init, tudo->mlx_window, 
        tudo->sprites.grass1, j * 44, i * 44); 
    else if(tudo->map.full_map[i][j] == 'P')
        mlx_put_image_to_window(tudo->mlx_init, tudo->mlx_window, 
        tudo->sprites.sapo1, j * 44, i * 44);
    else if (tudo->map.full_map[i][j] == 'C')
        mlx_put_image_to_window(tudo->mlx_init, tudo->mlx_window, 
        tudo->sprites.collectible1, j * 44, i * 44);
    else if (tudo->map.full_map[i][j] == 'E')
    {
     mlx_put_image_to_window(tudo->mlx_init, tudo->mlx_window, 
        tudo->sprites.polluted_water, j * 44, i * 44);
        tudo->indexs.exit_i = i;
        tudo->indexs.exit_j = j;        
    }
    else if (tudo->map.full_map[i][j] == 'F')
        mlx_put_image_to_window(tudo->mlx_init, tudo->mlx_window,
        tudo->sprites.exit1, tudo->indexs.exit_j * 44, tudo->indexs.exit_i * 44);
} 

void move_sprite(t_tudo *tudo, int x, int y)
{
    loop_grid(tudo);  // this function represents where player starts    
    if (tudo->map.full_map[tudo->indexs.i + x][tudo->indexs.j + y] != '1' && tudo->map.full_map[tudo->indexs.i + x][tudo->indexs.j + y] != 'E')
    {
        tudo->move_count++;
        put_string(tudo);
        if (tudo->map.full_map[tudo->indexs.i + x][tudo->indexs.j + y] == 'F')
        {
            ft_printf("//////Congratulations, you finish the game with");
            ft_printf(" %d moves\\\\\\\\\\ \n", tudo->move_count);
            exit_game(tudo);
        }
        if(tudo->map.full_map[tudo->indexs.i + x][tudo->indexs.j + y] == 'C')
            tudo->collectible_total--;            
        tudo->map.full_map[tudo->indexs.i + x][tudo->indexs.j + y] = 'P';
        tudo->map.full_map[tudo->indexs.i][tudo->indexs.j] = '0';                
    }
    if (tudo->collectible_total == 0)
        tudo->map.full_map[tudo->indexs.exit_i][tudo->indexs.exit_j] = 'F';
    loop_map_grid(tudo);
}

void put_string(t_tudo *tudo)
{    
    tudo->str_put = ft_itoa(tudo->move_count);
    if(tudo->move_count != 0)
    mlx_clear_window(tudo->mlx_init, tudo->mlx_window);    
    mlx_string_put(tudo->mlx_init, tudo->mlx_window, tudo->map.width, tudo->map.height * 44 + 22, 
    GOLD, "Number of moves:");
    mlx_string_put(tudo->mlx_init, tudo->mlx_window, tudo->map.width + 110, tudo->map.height * 44 + 22, 
    GOLD, tudo->str_put); 
    free(tudo->str_put);      
}



