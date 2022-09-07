/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   another_version.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 11:30:09 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/09/07 17:44:18 by ivda-cru         ###   ########.fr       */
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

#define LIGHT_GREY 0xd3d3d3
#define GOLD 0xffd700
#define RED 0xf90808

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#define sapinho "./sprites_Solong/sapinho3.xpm"
#define grass "./sprites_Solong/grass.xpm"


typedef struct s_sprites
{
    
    void *sapo1;
    void *grass1;
    void *xpm3;
    void *xpm4;
    void *xpm5;
    void *xpm6;
        
}   t_sprites;

typedef struct s_map
{
    int map_width;
    int map_height;
    
}   t_map;

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
    t_map   map;
    
    int tela_x;
    int tela_y;
    
    int position_x;
    int position_y;

    int sapo_x;
    int sapo_y;    
    
}   t_tudo;

int keyboard(int keycode, t_tudo *tudo)
{     
   //mlx_clear_window(tudo->mlx_init, tudo->mlx_window);  
    
    if (keycode == 119)
    {
        printf("TECLA 'W'\n");
        tudo->position_y = tudo->position_y - tudo->sapo_y;                  
    }
    else if (keycode == 97)
    {
        printf("TECLA 'A'\n");
        tudo->img.squareX  = tudo->img.squareX  - 150;        
    }    
    else if (keycode == 115) 
    {
        printf("TECLA 'S'\n");       
        tudo->img.squareY = tudo->img.squareY + 50; 
    }  
    else if (keycode == 100)
    {
        printf("TECLA 'D'\n");
        tudo->img.squareX = tudo->img.squareX + 150; 
    }
    else if (keycode == 65293)
        printf("TECLA 'ENTER'\n");
    else if (keycode == 65307)
        {
            printf("TECLA 'ESCAPE'\n");
            exit(0);
            
        }
    return(0);
}

/* void read_map(char *filename, t_tudo *tudo)
{
    int fd;
    char *line;

    fd = open(filename, O_RDONLY);
    line = get_next_line(fd);
    
    printf("lina e: %s", line);
    return (0);
} */


int main (int argc, char **argv)
{
    t_tudo tudo;

    tudo.tela_x =  WINDOW_WIDTH;
    tudo.tela_y = WINDOW_HEIGHT;

    tudo.mlx_init = mlx_init();
    tudo.mlx_window = mlx_new_window(tudo.mlx_init, tudo.tela_x, tudo.tela_y, "Ivo");

    tudo.sprites.sapo1 = mlx_xpm_file_to_image(tudo.mlx_init, sapinho, 
            &tudo.sapo_x, &tudo.sapo_y);
    tudo.sprites.grass1 = mlx_xpm_file_to_image(tudo.mlx_init, grass, 
            &tudo.sapo_x, &tudo.sapo_y);
            
    mlx_key_hook(tudo.mlx_window, &keyboard, &tudo);
    
    
    //read_map(argv[1], &tudo);

    mlx_loop(tudo.mlx_init);


    return(0);
}

