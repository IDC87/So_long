/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:30:43 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/09/22 17:15:08 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int keyboard(int keycode, t_tudo *tudo)
{     
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

int main (int argc, char **argv)
{
    t_tudo tudo;

    if (argc == 2 )
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

    mlx_loop(tudo.mlx_init);


    return(0);
}