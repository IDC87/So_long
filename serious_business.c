/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serious_business.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:08:39 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/07/01 16:10:20 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_vector
{
    int x;
    int y;
} t_vector;

typedef struct s_vars
{
    void *mlx_init;
    void *mlx_window;    
} t_vars;

typedef struct s_image
{
    void        *xpm;
    t_vector    size;
    char        *pixels;
    int         bits_per_pixel;
    int         line_size;
    int         endian;
} t_image;

int ft_input(int keypressed, t_vars *vars)
{
    //t_image *img = param;
    printf("key is:" );
    
    return(0);
}


int main()
{
    t_vars vars;
    t_vector vector;
    t_image img;
    t_vector sprite;

    vector.x = 800;
    vector.y = 600;
    
    vars.mlx_init = mlx_init();
    vars.mlx_window = mlx_new_window(vars.mlx_init, vector.x, vector.y, "Ivo" );
    // inicio da tela
    
    img.xpm = mlx_xpm_file_to_image(vars.mlx_init, "./Sapinho/sapinho5.xpm", &img.size.x, &img.size.y);
    img.pixels = mlx_get_data_addr(img.xpm, &img.bits_per_pixel, &img.line_size, &img.endian);
    sprite.x = vector.x / 2;
    sprite.y = vector.y / 2;    
    mlx_put_image_to_window(vars.mlx_init, vars.mlx_window, img.xpm, sprite.x, sprite.y);
    // por o sprite no ecra (a meio)

    mlx_key_hook(vars.mlx_window, ft_input, &vars);
    
    mlx_loop(vars.mlx_init);

    return(0);
    
    
}