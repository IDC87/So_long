/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:30:43 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/10/03 18:25:55 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int keyboard(int keycode, t_tudo *tudo)
{
    mlx_mouse_get_pos(tudo->mlx_init, tudo->mlx_window, &tudo->indexs.mouse_x, &tudo->indexs.mouse_y);
    
    
     
    if (keycode == 119) //TECLA W
        move_up(tudo);                  
    else if (keycode == 97) //TECLHA A
        move_to_the_left(tudo);          
    else if (keycode == 115) //TECLA S
        move_down(tudo);        
    else if (keycode == 100) //TECLA D
        move_to_the_right(tudo); 
    else if (keycode == 65307)
            exit(0); 
        
    return(0);

    
}

/* int mouse(int mouse_key, t_tudo *tudo)
{
    printf("%d", mouse_key);
    printf("Mouse position is: %d %d\n", tudo->indexs.mouse_x, tudo->indexs.mouse_y);
    exit(0);
    
    
    return(0);
} */

int main (int argc, char **argv)
{
    t_tudo tudo;

    if (argc != 2 )
    {        
        printf("Error\n Map file missing in argument!\n");
        exit(-1);        
    }
    else
        create_map(argv[1], &tudo.grid);
        

    tudo.tela_x =  tudo.grid.width * 44;
    tudo.tela_y = tudo.grid.height * 44 + 44;
    tudo.grid.collectible_total = 0;
    tudo.grid.move_count = 0;
    tudo.indexs.mouse_x = 0;
    tudo.indexs.mouse_y = 0;

    tudo.mlx_init = mlx_init();
    tudo.mlx_window = mlx_new_window(tudo.mlx_init, tudo.tela_x, tudo.tela_y, "So_long");

    loop_grid_collectible(&tudo);
    create_sprites(&tudo);       
    loop_map_grid(&tudo); 
     
    //mlx_mouse_hook(tudo.mlx_window, &mouse, &tudo);  to be continued
    
    mlx_key_hook(tudo.mlx_window, &keyboard, &tudo);
    //mouse_input(&tudo);
    

     printf("POSIX of EXIT is: %d %d\n", tudo.indexs.exit_i, tudo.indexs.exit_j);  
    
    mlx_loop(tudo.mlx_init);


    return(0);
}