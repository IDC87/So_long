/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   another_version.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 11:30:09 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/09/21 20:41:12 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
//#include <X11/X.h>
//#include <X11/keysym.h>
#include <stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h> 
#include "./Get_next_line/get_next_line.h"
#include "./Libft_42_school/libft.h"
#define X_EVENT_KEY_PRESS 3
#define X_EVENT_KEY_EXIT 0

#define LIGHT_GREY 0xd3d3d3
#define GOLD 0xffd700
#define RED 0xf90808

/* #define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600 */

#define BUFFER_COUNT 5000

#define sapinho "./sprites_Solong/player_64px.xpm"
#define grass "./sprites_Solong/grass_64px.xpm"
#define wall "./sprites_Solong/wall_64px.xpm"
#define player_exit "./sprites_Solong/exit.xpm"
#define player_collectible "./sprites_Solong/collectible.xpm"
#define polluted_lake "./sprites_Solong/lake_polluted.xpm"

typedef struct s_sprites
{
    
    void *sapo1;
    void *grass1;
    void *wall1;
    void *exit1;
    void *collectible1;
    void *polluted_water;
        
}   t_sprites;

typedef struct s_grid
{
    int width;
    int height;
    int fd;

    char *new_line;
    char **map_grid;

    int collectible_total;
    
}   t_grid;

typedef struct s_indexs
{
    int i;
    int j;

    int exit_i;
    int exit_j;

}   t_indexs;


typedef struct s_img
{
    void        *mlx_img;
    char        *pixels;
    int         bits_per_pixel;
    int         line_size;
    int         endian;
    
    int         squareX;
    int         squareY;
    
}   t_img;

typedef struct s_rect
{
    int x;
    int y;

    int width;
    int height;

    int color;
    
}   t_rect;

typedef struct s_tudo
{
    void *mlx_init;
    void *mlx_window;   

    t_sprites sprites;

    t_img   img;

    t_indexs indexs;
   
    
    int tela_x;
    int tela_y;
    
    int position_x;
    int position_y;

    t_grid grid;

    int sapo_x;
    int sapo_y;    
    
}   t_tudo;

size_t	ft_strlen_long(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup_long(const char *s)
{
	int		i;
	char	*str;

	str = NULL;
	i = 0;
	str = (char *)malloc(sizeof(*s) * ft_strlen_long(s) + 1);
	if (str == NULL)
		return (NULL);
	while (s[i] && s[i]!= '\n')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strncpy_long(char *dst, const char *src, size_t len)
{
	size_t i;

	i = 0;
	while ((src[i] != '\0') && (i < len))
	{
		dst[i] = src[i];
		i++;
	}
	while (i < len)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}

static int	nbr_tokens(char const *s, char delimeter)
{
	int	i;
	int	j;
	int	len;
	int	token_count;

	i = 0;
	j = 0;
	len = 0;
	if (!(*s))
		return (0);
	token_count = 0;
	while (s[i])
	{
		if (s[i] == delimeter)
			len = 0;
		else if (++len == 1)
			token_count++;
		i++;
	}
	return (token_count);
}

static char	*token(const char *s, int columns, int index)
{
	char	*token;
	int		i;
	int		token_pos;

	i = 0;
	token_pos = index - columns;
	token = (char *)malloc(sizeof(char) * (columns + 1));
	while (i < columns)
	{
		token[i] = s[token_pos];
		i++;
		token_pos++;
	}
	token[i] = '\0';
	return (token);
}

char	**words_divider(char const *s, char **words, char delimeter, int len)
{
	int		rows;
	int		columns;
	size_t	i;

	rows = 0;
	columns = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] == delimeter)
			len = 0;
		else if (++len == 1)
		{
			while (s[i] != delimeter && s[i] != '\0')
			{
				columns++;
				i++;
			}
			words[rows++] = token(s, columns, i);
			columns = 0;
			i--;
		}
	}
	words[rows] = NULL;
	return (words);
}

char	**ft_split(char const *s, char delimeter)
{
	char	**words;
	char	**str;
	int		len;

	len = 0;
	if (!s)
		return (0);
	words = (char **)malloc(sizeof(char *) * (nbr_tokens(s, delimeter) + 1));
	if (words == NULL)
		return (NULL);
	str = words_divider(s, words, delimeter, len);
	return (str);
}

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
    /* else if (tudo->grid.map_grid[i][j] == 'E')
        mlx_put_image_to_window(tudo->mlx_init, tudo->mlx_window, 
        tudo->sprites.exit1, j * 44, i * 44); */
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

void loop_map_grid(t_tudo *tudo)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(i < tudo->grid.height)
    {
        j = 0;
        while(j < tudo->grid.width)
        {
            insert_sprites(tudo, i, j);
            j++;
        }
        //printf("\n");
        i++;
    }   
    
}

void collectible_is_zero(t_tudo *tudo)
{
   
    
    
}

void loop_grid(t_tudo *tudo)
{
    int i;
    int j;
    int k;

    i = 0;
    j = 0;
    k = 0;

    if (tudo->grid.collectible_total == 0)
        tudo->grid.map_grid[tudo->indexs.exit_i][tudo->indexs.exit_j] = 'F';
    
    while(i < tudo->grid.height)
    {
        j = 0;
        while(j < tudo->grid.width)
        {
            if (tudo->grid.map_grid[i][j] == 'P') 
            {
                tudo->indexs.i = i; 
                tudo->indexs.j = j;
                exit;
            } 
            j++;
        }       
        i++;
    }  
    
}

void loop_grid_collectible(t_tudo *tudo)
{
    int i;
    int j;

    i = 0;
    j = 0;
    
    while(i < tudo->grid.height)
    {
        j = 0;
        while(j < tudo->grid.width)
        {
            if (tudo->grid.map_grid[i][j] == 'C')
                tudo->grid.collectible_total++;            
            j++;
        }       
        i++;
    }                         
}



void move_to_the_right(t_tudo *tudo)
{
    loop_grid(tudo);  // this function represents where player starts
    
    if (tudo->grid.map_grid[tudo->indexs.i][tudo->indexs.j + 1] != '1')
    {
        if(tudo->grid.map_grid[tudo->indexs.i][tudo->indexs.j + 1] == 'C')
            tudo->grid.collectible_total--;            
        tudo->grid.map_grid[tudo->indexs.i][tudo->indexs.j + 1] = 'P';
        tudo->grid.map_grid[tudo->indexs.i][tudo->indexs.j] = '0';
        
    }
    loop_map_grid(tudo);
}

void move_to_the_left(t_tudo *tudo)
{
    loop_grid(tudo);  // this function represents where player starts
    
    if (tudo->grid.map_grid[tudo->indexs.i][tudo->indexs.j - 1] != '1')
    {
        if(tudo->grid.map_grid[tudo->indexs.i][tudo->indexs.j - 1] == 'C')
            tudo->grid.collectible_total--;
        tudo->grid.map_grid[tudo->indexs.i][tudo->indexs.j - 1] = 'P';
        tudo->grid.map_grid[tudo->indexs.i][tudo->indexs.j] = '0';        
    }
    loop_map_grid(tudo);
}

void move_up(t_tudo *tudo)
{
    loop_grid(tudo);  // this function represents where player starts
    
    if (tudo->grid.map_grid[tudo->indexs.i - 1][tudo->indexs.j] != '1')
    {
        if(tudo->grid.map_grid[tudo->indexs.i - 1][tudo->indexs.j] == 'C')
            tudo->grid.collectible_total--;
        tudo->grid.map_grid[tudo->indexs.i - 1][tudo->indexs.j] = 'P';
        tudo->grid.map_grid[tudo->indexs.i][tudo->indexs.j] = '0';        
    }
    loop_map_grid(tudo);
}

void move_down(t_tudo *tudo)
{
    loop_grid(tudo);  // this function represents where player starts
    
    if (tudo->grid.map_grid[tudo->indexs.i + 1][tudo->indexs.j] != '1')
    {
        if(tudo->grid.map_grid[tudo->indexs.i + 1][tudo->indexs.j] == 'C')
            tudo->grid.collectible_total--;
        tudo->grid.map_grid[tudo->indexs.i + 1][tudo->indexs.j] = 'P';
        tudo->grid.map_grid[tudo->indexs.i][tudo->indexs.j] = '0';        
    }
    loop_map_grid(tudo);
}

int keyboard(int keycode, t_tudo *tudo)
{     
   //mlx_clear_window(tudo->mlx_init, tudo->mlx_window);  
    
    if (keycode == 119)
    {
        printf("TECLA 'W'\n");
        move_up(tudo);
        tudo->position_y = tudo->position_y - tudo->sapo_y;                  
    }
    else if (keycode == 97)
    {
        printf("TECLA 'A'\n");
        move_to_the_left(tudo);
        tudo->img.squareX  = tudo->img.squareX  - 150;        
    }    
    else if (keycode == 115) 
    {
        printf("TECLA 'S'\n"); 
        move_down(tudo);      
        tudo->img.squareY = tudo->img.squareY + 50; 
    }  
    else if (keycode == 100)
    {
        printf("TECLA 'D'\n");
        move_to_the_right(tudo);
        
        tudo->img.squareX = tudo->img.squareX + 150; 
    }
    else if (keycode == 65293)
        printf("TECLA 'ENTER'\n");
    else if (keycode == 65307)
        {
            printf("TECLA 'ESCAPE'\n");
            printf("COLLECTIBLE COUNT TOTAL: %d\n", tudo->grid.collectible_total);
            exit(0);
            
        }
    return(0);
}



int main (int argc, char **argv)
{
    t_tudo tudo;

    create_map(argv[1], &tudo.grid);

    tudo.tela_x =  tudo.grid.width * 44;
    tudo.tela_y = tudo.grid.height * 44;

    tudo.grid.collectible_total = 0;

    tudo.mlx_init = mlx_init();
    tudo.mlx_window = mlx_new_window(tudo.mlx_init, tudo.tela_x, tudo.tela_y, "Ivo");

    loop_grid_collectible(&tudo);
    create_sprites(&tudo);       
    loop_map_grid(&tudo);    
     mlx_key_hook(tudo.mlx_window, &keyboard, &tudo); 

     printf("POSIX of EXIT is: %d %d\n", tudo.indexs.exit_i, tudo.indexs.exit_j);

    

    //mlx_key_hook(tudo.mlx_init, image_to_map, &tudo);
    //mlx_hook(tudo.mlx_window, X_EVENT_KEY_PRESS, 0, &keyboard, &tudo);    

    mlx_loop(tudo.mlx_init);


    return(0);
}

