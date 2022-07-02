/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:51:25 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/06/27 15:27:30 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <unistd.h>

#define Xres 800
#define Yres 600
#define LIGHT_GREY 0xd3d3d3
#define GOLD 0xffd700

typedef struct s_data
{
    void *img;
    char *addr;
    char *frog;
    int bits_per_pixel;
    int line_length;
    int endian;
}   t_data;

typedef struct rect
{
    int x;
    int y;
    int width;
    int height;
    int color;
} t_rect;

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst; 
   // data->bits_per_pixel = 64000;   pixel a meio da tela
    
        //printf("esta a correr\n");
        dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
        *(unsigned int*)dst = color;       
    
}

void create_rect(t_data *data, int x, int height)
{
    t_rect rect;
   int i;
   // int j;
    
    rect.width = 300;
    rect.height = height;
    //rect.x = Xres / 2;
    i = 0;
   // j = 0;
    rect.x = x;

    while (i < rect.width)
    {
       /*  while (j < rect.height)
        { */
            my_mlx_pixel_put(data, rect.x++, rect.height, GOLD);
            
            //j++;
       // }        
        i++;                
    }    
}

void create_square(t_data *data, int x, int y)
{
    int height;
    int width;
   
    height = y;
    width = x;
    while (height > 0)
        create_rect(data, width, height--);
}

int main(void)
{
    void *mlx;
    void *mlx_win;
    t_data img; 

    char *frog = "./Sapinho/sapinho1.xpm";
   // int sapo_width = 400;
    int sapo_height = 150;

    
    
    //!!!!!  *mlx_ptr e igual ao mlx  !!!!!
    //!!!!!win_ptr e igual o mlx_win!!!!!
    //!!!!! a -> b is equivalent to (*a).b!!!!!!! -> is for convenience

    mlx = mlx_init();                       
    // serve para estabelecer a ligacao ao gui(autorizar)
    
    mlx_win = mlx_new_window(mlx, Xres, Yres, "JOGUITO DO IVO"); 
    // cria a tela inical com titulo
    
    img.img = mlx_new_image(mlx, Xres/4, Yres/4);
    // cria uma nova imagem na memoria, retorna um void* para ser manipulada mais tarde
    
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    //retorna info sobre a imagem criada, permintido a ser modificada mais tarde

    printf("BITS PER PIXEL is: %d\n", img.bits_per_pixel);
    printf("LINE LENGTH is: %d\n", img.line_length);
      
    
   // my_mlx_pixel_put(&img, Xres/2, Yres/2, 0x0045E95B);
   // my_mlx_pixel_put(&img, 6, 5, 0x00FF0000);
    //my_mlx_pixel_put(&img, 7, 5, 0x00144CE6);
    
    //create_square(&img, Xres / 2, Yres);
    
    //mlx_string_put(mlx, mlx_win, Xres/3, Yres/3, 0x0045E95B, "TESTE"); //output da string na tela

    
    img.frog = mlx_xpm_file_to_image(mlx, frog, &img.line_length, &sapo_height);
    if (img.frog == NULL)
        printf("sapinho nao lido");
    else
        printf("sapinho is present");

    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    
    /* //Seccao dedicada a custom images
    void *mlx_new_image(void *mlx_ptr, int width, int height);
     //cria uma nova imagem na memoria
    int mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);
     //adiciona a imagem na tela
    char *mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian);
     //retorna a info sobre a imagem, que pode ser edited depois */
    
    //mlx_string_put(&img, 6, 5, 0x00FF0000, "TESTE");
    
    printf("\n-----Identificador de ligacao, Pointer: %p-----\n", mlx);
    printf("\n------Identificador da tela, Pointer %p------\n", mlx_win);
    mlx_loop(mlx);

    

    return(0);
}