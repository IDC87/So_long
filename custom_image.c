/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:30:14 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/06/30 18:28:50 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <unistd.h>
#include <X11/keysym.h>
#include <X11/X.h>

typedef struct s_vars
{
    void *mlx;
    void *win;
} t_vars;

typedef struct s_vector
{
    int x;
    int y;
} t_vector;

typedef struct s_image
{
    void        *reference;
    t_vector    size;
    char        *pixels;
    int         bits_per_pixel;
    int         line_size;
    int         endian;
} t_image;

t_vars vars;
t_image img;

int close_window(int keysym, t_vars *data)
        {
            if (keysym == XK_Escape)
            {
                mlx_destroy_window(vars.mlx, vars.win);  
                mlx_destroy_display(vars.mlx);  
            }

            printf("Keypress: %d\n", keysym);
            return (0);
        }


int main()
{
    
    void *xpm_pointer;
   
    char sapinhos[6][23] = {{"./Sapinho/sapinho1.xpm"}, {"./Sapinho/sapinho2.xpm"}, {"./Sapinho/sapinho3.xpm"}, 
                             {"./Sapinho/sapinho4.xpm"}, {"./Sapinho/sapinho5.xpm"}, {"./Sapinho/sapinho6.xpm"}};
    int width = 800;
    int height = 600;     
        
        vars.mlx = mlx_init();
        vars.win = mlx_new_window(vars.mlx, width, height, "Ivo");              
        
         int i = 0;
         int j = 0;
         int sleep = 50000;
        
        int	handle_no_event(void *t_vars)
        {
	        //printf("NO EVENT DETECTED! %p\n", vars.mlx);
	        return (0);
        }        
        
        int	handle_keyrelease(int keysym, void *vars)
        {
	        printf("Keyrelease: %d\n", keysym);
	        return (0);
        }       
        
        while(i < 7)
        {             
            xpm_pointer = mlx_xpm_file_to_image(vars.mlx, sapinhos[i], &img.size.x, &img.size.y);               
            mlx_put_image_to_window(vars.mlx, vars.win, xpm_pointer, 700 - (55), 40);
            printf("image n[%d] updated: %p\n", i, xpm_pointer);
            usleep(sleep);  
            mlx_clear_window(vars.mlx, vars.win);
            mlx_destroy_image(vars.mlx, xpm_pointer);
                       
            i++;
            j++;
            printf("j: %d\n", j);
            if (sleep / 1000 == j)
            break;            
            if (i == 6)
                i = 0;            
        }        
                       
    printf("\n-----Identificador de ligacao, Pointer: %p-----\n", vars.mlx);
    printf("\n///////FINAL DO CICLO, devia terminar a tela\\\\\\\n");
    mlx_key_hook(vars.win, *close_window, &vars);
    //if (j != sleep / 1000)
    mlx_loop(vars.mlx); 
    
    //free(vars.mlx);   
   

   return (0);
}