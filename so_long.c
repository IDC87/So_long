/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:30:43 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/10/19 21:37:16 by ivda-cru         ###   ########.fr       */
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
    else if (keycode == 65307) //TECLA ESCAPE
            exit(0);         
    return(0);
    
}

int exit_game(t_tudo *tudo)
{
    mlx_destroy_display(tudo->mlx_init);
	exit(0);
}

int main (int argc, char **argv)
{
    t_tudo *tudo; 

     tudo = malloc(sizeof(t_tudo));  
     
    printf("SIZEOF THE MEGA STRUCT %ld\n", sizeof(t_tudo));

    if (argc != 2 )
    {        
        printf("Error\n Map file missing in argument!\n");
        exit(-1);        
    }
    else    
        create_map(argv[1], tudo);   

    tudo->grid.collectible_total = 0;
    tudo->grid.collectible_count = 0;
    tudo->grid.move_count = 0;
    tudo->grid.exit_count = 0;
    tudo->grid.player_count = 0;
    tudo->grid.empty_spaces = 0;

    tudo->tela_x =  tudo->grid.width * 44;
    tudo->tela_y = tudo->grid.height * 44 + 44;

    tudo->mlx_init = mlx_init();
    tudo->mlx_window = mlx_new_window(tudo->mlx_init, tudo->tela_x, tudo->tela_y, "So_long");

    loop_grid_collectible(tudo);
    create_sprites(tudo);       
    loop_map_grid(tudo);     
    
    mlx_key_hook(tudo->mlx_window, &keyboard, tudo);
    mlx_hook(tudo->mlx_window, X_EVENT_KEY_EXIT, 0, &exit_game, tudo);
    
    mlx_loop(tudo->mlx_init);
       


    return(0);
}

