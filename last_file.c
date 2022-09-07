/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 17:08:56 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/09/07 17:45:10 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
//#include <X11/X.h>
//#include <X11/keysym.h>
#include <stdlib.h>
#include "./Get_next_line/get_next_line.h"

#define LIGHT_GREY 0xd3d3d3
#define GOLD 0xffd700
#define RED 0xf90808

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600


typedef struct s_sprites
{
    void *xpm_og;
    void *xpm1;
    void *xpm2;
    void *xpm3;
    void *xpm4;
    void *xpm5;
    void *xpm6;
        
}   t_sprites;

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
    
    /* else
        printf("TECLA NAO REGISTADA: %d\n", keycode); */    
    //mlx_put_image_to_window(tudo->mlx_init, tudo->mlx_window, tudo->sprites.xpm1, tudo->position_x, tudo->position_y);    
    return(0);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char    *pixel;
	int		i;

	i = img->bits_per_pixel - 8;
    pixel = img->pixels + (y * img->line_size + x * (img->bits_per_pixel / 8));
	while (i >= 0)
	{
		/* big endian, MSB is the leftmost bit */
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		/* little endian, LSB is the leftmost bit */
		else
			*pixel++ = (color >> (img->bits_per_pixel - 8 - i)) & 0xFF;
		i -= 8;
	}
}

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			img_pix_put(img, j++, i, color);
		}
		++i;
	}
}

void render_square(t_img *img, int color, int i, int j)
{
     i = img->squareX;
     //j = img->squareY; 

     int y = 0; 
       

    while (i < WINDOW_WIDTH / 6 + img->squareX)
    {
        j = 0;
        while ( j < WINDOW_HEIGHT / 6 )
        {
            img_pix_put(img, i, j, color);  
            j++;  
        }
        i++;
    }
    
}

int render_rect(t_img *img, t_rect rect)
{
	int	i;
	int j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			img_pix_put(img, j++, i, rect.color);
		++i;
	}
	return (0);
}

void *render_sprite(t_tudo *tudo)
{
    //mlx_clear_window(tudo->mlx_init, tudo->mlx_window);
    
    
    mlx_put_image_to_window(tudo->mlx_init, tudo->mlx_window, 
         tudo->sprites.xpm1, tudo->position_x, tudo->position_y);
    return (tudo->sprites.xpm1);
}

int	render(t_tudo *data)
{
	render_background(&data->img, GOLD);
    render_square(&data->img, LIGHT_GREY, 10, 10);
    render_rect(&data->img, (t_rect){WINDOW_WIDTH - data->img.squareX, WINDOW_HEIGHT - 100, 100, 100, RED});
    render_sprite(data);	

	mlx_put_image_to_window(data->mlx_init, data->mlx_window, data->img.mlx_img, 0, 0);

	return (0);
}


int main()
{
   t_tudo tudo;    

    tudo.tela_x = WINDOW_WIDTH;
    tudo.tela_y = WINDOW_HEIGHT;

    tudo.position_x = 50;
    tudo.position_y = 100;
    
    tudo.mlx_init = mlx_init();
    tudo.mlx_window = mlx_new_window(tudo.mlx_init, tudo.tela_x, tudo.tela_y, "Ivo" );
    // inicio da tela
    tudo.sprites.xpm1 = mlx_xpm_file_to_image(tudo.mlx_init, "./Sapinho/sapinho5.xpm", 
            &tudo.sapo_x, &tudo.sapo_y);

    tudo.img.mlx_img = mlx_new_image(tudo.mlx_init, tudo.tela_x, tudo.tela_y);

    tudo.img.pixels = mlx_get_data_addr(tudo.img.mlx_img, &tudo.img.bits_per_pixel, 
            &tudo.img.line_size, &tudo.img.endian);
    
   mlx_loop_hook(tudo.mlx_init, &render, &tudo);
       

    mlx_key_hook(tudo.mlx_window, &keyboard, &tudo);
    
    
    mlx_loop(tudo.mlx_init);

    

    //mlx_destroy_display(tudo.mlx_init);
    //free(tudo.mlx_window);

    return(0);   
    
}