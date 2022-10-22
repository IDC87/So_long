/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_sprites.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 11:30:09 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/10/22 19:48:55 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void create_map(char *filename, t_map *map)
{
    size_t bytes_read;
    char *buf;
    int fd;


    map->height = 0;
    map->width = 0;    
    
    fd = open(filename, O_RDONLY);
    if (fd == -1)
        {
            perror("Error\n");
            exit(0);            
        }
    buf = (char *)malloc(sizeof(char) * BUFFER_COUNT);
    bytes_read = read(fd, buf, BUFFER_COUNT);
    if (bytes_read <= 0)
	    free(buf);
    buf[bytes_read] = '\0';    
    map->full_map = ft_split(buf, '\n');
    
    free(buf);
    close(fd);
    map->width = ft_strlen_long(map->full_map[0]);
    map->height  = bytes_read / map->width;
    if (map->width < map->height )
        map->height --;    
        
    
    //not_rect(tudo);
    //check_number_of_sprites(tudo);
    //loop_surrounded_by_walls(tudo);  
     
}

/* char	*read_file(int32_t fd)
{
	int32_t	buflen;
	char	*line;
	char	*buf;

	buflen = 1;
	line = ft_calloc(1, 1);
	buf = malloc(BUFFERSIZE + 1 * sizeof(char));
	while (buflen > 0)
	{
		buflen = read(fd, buf, BUFFERSIZE);
		if (buflen <= 0)
			free (buf);
		if (buflen == 0)
			return (line);
		if (buflen < 0)
			return (NULL);
		buf[buflen] = '\0';
		line = gnl_strjoin(line, buf);
	}
	close(fd);
	return (line);
} */

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


