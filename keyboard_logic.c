/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_logic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:37:36 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/10/03 17:05:23 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void move_to_the_right(t_tudo *tudo)
{
    loop_grid(tudo);  // this function represents where player starts
    
    if (tudo->grid.map_grid[tudo->indexs.i][tudo->indexs.j + 1] != '1' && tudo->grid.map_grid[tudo->indexs.i][tudo->indexs.j + 1] != 'E')
    {
        tudo->grid.move_count++;
        put_string(tudo);
        if(tudo->grid.map_grid[tudo->indexs.i][tudo->indexs.j + 1] == 'C')
            tudo->grid.collectible_total--;            
        tudo->grid.map_grid[tudo->indexs.i][tudo->indexs.j + 1] = 'P';
        tudo->grid.map_grid[tudo->indexs.i][tudo->indexs.j] = '0';
                
    }
    loop_map_grid(tudo);
}

void move_to_the_left(t_tudo *tudo)
{
    loop_grid(tudo);  // this function represents where player starts
    
    if (tudo->grid.map_grid[tudo->indexs.i][tudo->indexs.j - 1] != '1' && tudo->grid.map_grid[tudo->indexs.i][tudo->indexs.j - 1] != 'E')
    {
        tudo->grid.move_count++;
        put_string(tudo);
        if(tudo->grid.map_grid[tudo->indexs.i][tudo->indexs.j - 1] == 'C')
            tudo->grid.collectible_total--;
        tudo->grid.map_grid[tudo->indexs.i][tudo->indexs.j - 1] = 'P';
        tudo->grid.map_grid[tudo->indexs.i][tudo->indexs.j] = '0';  
              
    }
    loop_map_grid(tudo);
}

void move_up(t_tudo *tudo)
{
    loop_grid(tudo);  // this function represents where player starts
    
    if (tudo->grid.map_grid[tudo->indexs.i - 1][tudo->indexs.j] != '1' && tudo->grid.map_grid[tudo->indexs.i - 1][tudo->indexs.j] != 'E')
    {
        tudo->grid.move_count++;
        put_string(tudo);
        if(tudo->grid.map_grid[tudo->indexs.i - 1][tudo->indexs.j] == 'C')
            tudo->grid.collectible_total--;
        tudo->grid.map_grid[tudo->indexs.i - 1][tudo->indexs.j] = 'P';
        tudo->grid.map_grid[tudo->indexs.i][tudo->indexs.j] = '0';
                
    }
    loop_map_grid(tudo);
}

void move_down(t_tudo *tudo)
{
    loop_grid(tudo);  // this function represents where player starts
    
    if (tudo->grid.map_grid[tudo->indexs.i + 1][tudo->indexs.j] != '1' && tudo->grid.map_grid[tudo->indexs.i + 1][tudo->indexs.j] != 'E')
    {
        tudo->grid.move_count++;
        put_string(tudo); //display the number of moves in the game
        
        if(tudo->grid.map_grid[tudo->indexs.i + 1][tudo->indexs.j] == 'C')
            tudo->grid.collectible_total--;
        tudo->grid.map_grid[tudo->indexs.i + 1][tudo->indexs.j] = 'P';
        tudo->grid.map_grid[tudo->indexs.i][tudo->indexs.j] = '0';
               
    }
    loop_map_grid(tudo);
}