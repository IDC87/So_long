/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serious_business.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:08:39 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/07/14 18:06:12 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

#define LIGHT_GREY 0xd3d3d3
#define GOLD 0xffd700
#define RED 0xf90808

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

typedef struct arr_sprites
{
    char *xpm[6];
} arr_sprites;

typedef struct s_tudo
{
    void *mlx_init;
    void *mlx_window;
    void *mlx_window2;

    t_sprites sprites;
    
    int tela_x;
    int tela_y;
    
    int position_x;
    int position_y;

    int sapo_x;
    int sapo_y;
    
    char        *pixels;
    int         bits_per_pixel;
    int         line_size;
    int         endian;
    
}   t_tudo;

int	itoa_size(int n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	n = -n;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*convertion(char *str, int n, int len, int j)
{
	int	z;

	z = 0;
	while (len-- != j)
	{
		str[len] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{	
	int		len;
	int		j;
	char	*str;

	/* if (n == -2147483648)
		return (ft_strdup("-2147483648")); */
	j = 0;
	if (n < 0)
		j = 1;
	len = itoa_size(n) + j;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	str[len] = '\0';
	n = n * (((n < 0) * -2) + 1);
	convertion(str, n, len, j);
	return (str);
}

void change_background(t_tudo *tudo)
{
    int i;
    int j;

    i = 0;
    while (i < tudo->tela_y)
    {
        j = 0;
        while (j < tudo->tela_x)
           mlx_pixel_put(tudo->mlx_init, tudo->mlx_window, j++, i, LIGHT_GREY);
        i++;
    }
    
}

void render_fps(t_tudo *tudo)
{
    static long int frames;
    char *framesString;
    framesString = ft_itoa(frames / 1000);
    printf("frameString %s\n", framesString);
    mlx_string_put(tudo->mlx_init, tudo->mlx_window, 50, 20, RED, framesString);
    frames++;
    
}

int animated_sprite(t_tudo *tudo)
{
    
    static int i = 0;
    

    arr_sprites sprites_arr = {"./Sapinho/sapinho1.xpm", "./Sapinho/sapinho2.xpm", "./Sapinho/sapinho3.xpm", 
                   "./Sapinho/sapinho4.xpm", "./Sapinho/sapinho5.xpm", "./Sapinho/sapinho6.xpm"};    

    tudo->sprites.xpm_og = mlx_xpm_file_to_image(tudo->mlx_init, sprites_arr.xpm[i], &tudo->sapo_x, &tudo->sapo_y);
    mlx_put_image_to_window(tudo->mlx_init, tudo->mlx_window, tudo->sprites.xpm_og, tudo->position_x, tudo->position_y);
    //mlx_clear_window(tudo->mlx_init, tudo->mlx_window);
    i++;
    if (i > 5)
    i = 0;   

    render_fps(tudo);

    
    /* tudo->sprites.xpm1 = mlx_xpm_file_to_image(tudo->mlx_init, "./Sapinho/sapinho1.xpm", &tudo->sapo_x, &tudo->sapo_y);
    tudo->sprites.xpm2 = mlx_xpm_file_to_image(tudo->mlx_init, "./Sapinho/sapinho2.xpm", &tudo->sapo_x, &tudo->sapo_y);
    tudo->sprites.xpm3 = mlx_xpm_file_to_image(tudo->mlx_init, "./Sapinho/sapinho3.xpm", &tudo->sapo_x, &tudo->sapo_y);
    tudo->sprites.xpm4 = mlx_xpm_file_to_image(tudo->mlx_init, "./Sapinho/sapinho4.xpm", &tudo->sapo_x, &tudo->sapo_y);
    tudo->sprites.xpm5 = mlx_xpm_file_to_image(tudo->mlx_init, "./Sapinho/sapinho5.xpm", &tudo->sapo_x, &tudo->sapo_y);
    tudo->sprites.xpm6 = mlx_xpm_file_to_image(tudo->mlx_init, "./Sapinho/sapinho6.xpm", &tudo->sapo_x, &tudo->sapo_y);
    
    mlx_put_image_to_window(tudo->mlx_init, tudo->mlx_window, tudo->sprites.xpm1, tudo->position_x, tudo->position_y);
    mlx_clear_window(tudo->mlx_init, tudo->mlx_window);
    mlx_put_image_to_window(tudo->mlx_init, tudo->mlx_window, tudo->sprites.xpm2, tudo->position_x, tudo->position_y);
    mlx_clear_window(tudo->mlx_init, tudo->mlx_window);
    mlx_put_image_to_window(tudo->mlx_init, tudo->mlx_window, tudo->sprites.xpm3, tudo->position_x, tudo->position_y);
    mlx_clear_window(tudo->mlx_init, tudo->mlx_window);
    mlx_put_image_to_window(tudo->mlx_init, tudo->mlx_window, tudo->sprites.xpm4, tudo->position_x, tudo->position_y);
    mlx_clear_window(tudo->mlx_init, tudo->mlx_window);
    mlx_put_image_to_window(tudo->mlx_init, tudo->mlx_window, tudo->sprites.xpm5, tudo->position_x, tudo->position_y);
    mlx_clear_window(tudo->mlx_init, tudo->mlx_window);
    mlx_put_image_to_window(tudo->mlx_init, tudo->mlx_window, tudo->sprites.xpm6, tudo->position_x, tudo->position_y);
    mlx_clear_window(tudo->mlx_init, tudo->mlx_window);    */
    
    return(1);
}


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
        tudo->position_x = tudo->position_x - tudo->sapo_x;        
    }    
    else if (keycode == 115) 
    {
        printf("TECLA 'S'\n");       
        tudo->position_y = tudo->position_y + tudo->sapo_y; 
    }  
    else if (keycode == 100)
    {
        printf("TECLA 'D'\n");
        tudo->position_x = tudo->position_x + tudo->sapo_x; 
    }
    else if (keycode == 65293)
        printf("TECLA 'ENTER'\n");
    else if (keycode == 65307)
        {
            printf("TECLA 'ESCAPE'\n");
            mlx_clear_window(tudo->mlx_init, tudo->mlx_window);                      
            mlx_destroy_image(tudo->mlx_init, tudo->sprites.xpm1);            
            mlx_destroy_display(tudo->mlx_init);
            tudo->mlx_window = NULL;
            return(0);            
        }
    else if (keycode == 32)
        return(2);    
    else
        printf("TECLA NAO REGISTADA: %d\n", keycode);    
    mlx_put_image_to_window(tudo->mlx_init, tudo->mlx_window, tudo->sprites.xpm1, tudo->position_x, tudo->position_y);    
    return(1);
}

int main()
{
   t_tudo tudo;    

    tudo.tela_x = 800;
    tudo.tela_y = 600;
    
    tudo.mlx_init = mlx_init();
    tudo.mlx_window = mlx_new_window(tudo.mlx_init, tudo.tela_x, tudo.tela_y, "Ivo" );
    // inicio da tela
    
    tudo.sprites.xpm1 = mlx_xpm_file_to_image(tudo.mlx_init, "./Sapinho/sapinho5.xpm", &tudo.sapo_x, &tudo.sapo_y);
    change_background(&tudo);
    tudo.pixels = mlx_get_data_addr(tudo.sprites.xpm1, &tudo.bits_per_pixel, &tudo.line_size, &tudo.endian);
    tudo.position_x = (tudo.tela_x / 2) - (tudo.sapo_x / 2);
    tudo.position_y = tudo.tela_y / 2 - (tudo.sapo_y / 2); 
     render_fps(&tudo);
     
  
    mlx_put_image_to_window(tudo.mlx_init, tudo.mlx_window, tudo.sprites.xpm1, tudo.position_x, tudo.position_y);
    // por o sprite no ecra (a meio)      
    
  
    mlx_key_hook(tudo.mlx_window, &keyboard, &tudo);
    //mlx_clear_window(tudo.mlx_init, tudo.mlx_window);

    mlx_loop_hook(tudo.mlx_init, &animated_sprite, &tudo);
   
    mlx_loop(tudo.mlx_init);

    

    //mlx_destroy_display(tudo.mlx_init);
    //free(tudo.mlx_window);

    return(0);   
    
}