/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_sprites.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 11:30:09 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/10/25 22:31:19 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int create_map(char *filename, t_tudo *tudo)
{
    size_t bytes_read;
    char *buf;
    int fd;
    
    fd = open(filename, O_RDONLY);    
    if (fd == -1)
        {
            perror("Error\n");
            exit(0);            
        }
    buf = (char *)malloc(sizeof(char) * BUFFER_COUNT);
    if(!buf)
        return (0);
    bytes_read = read(fd, buf, BUFFER_COUNT);
    if (bytes_read <= 0)
	    free(buf);
    buf[bytes_read] = '\0'; 
   
    tudo->map.full_map = ft_split(buf, '\n');    
    tudo->map.width = ft_strlen_long(tudo->map.full_map[0]);
    tudo->map.height  = bytes_read / tudo->map.width;
    if (tudo->map.width < tudo->map.height )
        tudo->map.height --;
    free(buf);
    close(fd);
    return(1);      
}

t_sprites create_sprites(void *mlx_init)
{
    int x;
    int y;
    t_sprites img;
    
    img.sapo1 = mlx_xpm_file_to_image(mlx_init, sapinho, &x, &y);
    img.grass1 = mlx_xpm_file_to_image(mlx_init, grass, &x, &y);
    img.wall1 = mlx_xpm_file_to_image(mlx_init, wall, &x, &y);
    img.exit1 = mlx_xpm_file_to_image(mlx_init, player_exit, &x, &y);
    img.collectible1 = mlx_xpm_file_to_image(mlx_init, player_collectible, &x, &y);
    img.polluted_water = mlx_xpm_file_to_image(mlx_init, polluted_lake, &x, &y);
    return (img);
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



