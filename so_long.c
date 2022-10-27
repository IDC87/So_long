/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:30:43 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/10/27 18:13:13 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



int keyboard(int keycode, t_tudo *tudo)
{      
    if (keycode == 119) //TECLA W 119
        move_sprite(tudo, -1, 0);                  
    else if (keycode == 97) //TECLHA A
        move_sprite(tudo, 0, -1);          
    else if (keycode == 115) //TECLA S
        move_sprite(tudo, 1, 0);        
    else if (keycode == 100) //TECLA D
        move_sprite(tudo, 0, 1); 
    else if (keycode == 65307) //TECLA ESCAPE 65307
            exit_game(tudo);        
    return(0);    
}

int exit_game(t_tudo *tudo)
{    
    mlx_destroy_image(tudo->mlx_init, tudo->sprites.sapo1);
    mlx_destroy_image(tudo->mlx_init, tudo->sprites.grass1);
    mlx_destroy_image(tudo->mlx_init, tudo->sprites.wall1);
    mlx_destroy_image(tudo->mlx_init, tudo->sprites.exit1);
    mlx_destroy_image(tudo->mlx_init, tudo->sprites.collectible1);
    mlx_destroy_image(tudo->mlx_init, tudo->sprites.polluted_water);    
    mlx_destroy_window(tudo->mlx_init, tudo->mlx_window);
    mlx_destroy_display(tudo->mlx_init);
    free(tudo->mlx_init);
    free_map(tudo->map.full_map);    
	exit(0);
}

void free_map(char **map)
{
    int i;

    i = 0;
    while (map[i] != NULL)
    {
        free(map[i++]);        
    }
    free(map);    
}

void initialize_game(t_tudo *tudo)
{
    int window_x;
    int window_y;
    
    window_x = tudo->map.width * SPRITE_RES_X_Y;
    window_y = tudo->map.height * SPRITE_RES_X_Y + SPRITE_RES_X_Y;
    tudo->mlx_init = mlx_init();
    tudo->mlx_window = mlx_new_window(tudo->mlx_init, window_x, window_y, "So_long");
    loop_grid_collectible(tudo);
    tudo->sprites = create_sprites(tudo->mlx_init);       
    loop_map_grid(tudo);     
}

void initialize_variables(t_tudo *tudo)
{
    tudo->map.height = 0;
    tudo->map.width = 0;       
    tudo->collectible_total = 0;
    tudo->collectible_count = 0;
    tudo->collectible_debug_count = 0;
    tudo->move_count = 0;
    tudo->exit_count = 0;
    tudo->player_count = 0;
    tudo->empty_spaces = 0; 
}

int main (int argc, char **argv)
{
    t_tudo tudo;
    
    if (argc == 2)
    {
        if (!ft_strstr(argv[1], ".ber"))
            error("Map must have a .ber extension\n");        
    }
    else         
        error("Map file missing in argument, or too many arguments\n");
    initialize_variables(&tudo); 
    create_map(argv[1], 0, &tudo);
    check_map(&tudo);
    check_valid_path(&tudo);
    initialize_game(&tudo);
    mlx_key_hook(tudo.mlx_window, &keyboard, &tudo);
    mlx_hook(tudo.mlx_window, X_EVENT_KEY_EXIT, 0, &exit_game, &tudo);
    mlx_loop(tudo.mlx_init);
    return(0);
}

