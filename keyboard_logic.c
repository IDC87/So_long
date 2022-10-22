/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_logic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:37:36 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/10/19 18:21:15 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// the gross code of each of these functions can be put in one function itself

void move_to_the_right(t_tudo *tudo)
{
    loop_grid(tudo);  // this function represents where player starts
    
    if (tudo->grid.map_grid[tudo->indexs.i][tudo->indexs.j + 1] != '1' && tudo->grid.map_grid[tudo->indexs.i][tudo->indexs.j + 1] != 'E')
    {
        tudo->grid.move_count++;
        put_string(tudo);
        if (tudo->grid.map_grid[tudo->indexs.i][tudo->indexs.j + 1] == 'F')
            {
                mlx_destroy_display(tudo->mlx_init);
                exit(0);
            }
        if(tudo->grid.map_grid[tudo->indexs.i][tudo->indexs.j + 1] == 'C')
            tudo->grid.collectible_total--;            
        tudo->grid.map_grid[tudo->indexs.i][tudo->indexs.j + 1] = 'P';
        tudo->grid.map_grid[tudo->indexs.i][tudo->indexs.j] = '0';
                
    }
    if (tudo->grid.collectible_total == 0)
        tudo->grid.map_grid[tudo->indexs.exit_i][tudo->indexs.exit_j] = 'F';
    loop_map_grid(tudo);
}

void move_to_the_left(t_tudo *tudo)
{
    loop_grid(tudo);  // this function represents where player starts
    
    if (tudo->grid.map_grid[tudo->indexs.i][tudo->indexs.j - 1] != '1' && tudo->grid.map_grid[tudo->indexs.i][tudo->indexs.j - 1] != 'E')
    {
        tudo->grid.move_count++;
        put_string(tudo);
        if (tudo->grid.map_grid[tudo->indexs.i][tudo->indexs.j - 1] == 'F')
            {
                mlx_destroy_display(tudo->mlx_init);
                exit(0);
            }
        if(tudo->grid.map_grid[tudo->indexs.i][tudo->indexs.j - 1] == 'C')
            tudo->grid.collectible_total--;
        tudo->grid.map_grid[tudo->indexs.i][tudo->indexs.j - 1] = 'P';
        tudo->grid.map_grid[tudo->indexs.i][tudo->indexs.j] = '0';  
              
    }
    if (tudo->grid.collectible_total == 0)
        tudo->grid.map_grid[tudo->indexs.exit_i][tudo->indexs.exit_j] = 'F';
    loop_map_grid(tudo);
}

void move_up(t_tudo *tudo)
{
    loop_grid(tudo);  // this function represents where player starts
    
    if (tudo->grid.map_grid[tudo->indexs.i - 1][tudo->indexs.j] != '1' && tudo->grid.map_grid[tudo->indexs.i - 1][tudo->indexs.j] != 'E')
    {
        tudo->grid.move_count++;
        put_string(tudo);
        if (tudo->grid.map_grid[tudo->indexs.i - 1][tudo->indexs.j] == 'F')
            {
                mlx_destroy_display(tudo->mlx_init);
                exit(0);
            }
        if(tudo->grid.map_grid[tudo->indexs.i - 1][tudo->indexs.j] == 'C')
            tudo->grid.collectible_total--;
        tudo->grid.map_grid[tudo->indexs.i - 1][tudo->indexs.j] = 'P';
        tudo->grid.map_grid[tudo->indexs.i][tudo->indexs.j] = '0';
                
    }
    if (tudo->grid.collectible_total == 0)
        tudo->grid.map_grid[tudo->indexs.exit_i][tudo->indexs.exit_j] = 'F';
    loop_map_grid(tudo);
}

void move_down(t_tudo *tudo)
{
    loop_grid(tudo);  // this function represents where player starts
    
    if (tudo->grid.map_grid[tudo->indexs.i + 1][tudo->indexs.j] != '1' && tudo->grid.map_grid[tudo->indexs.i + 1][tudo->indexs.j] != 'E')
    {
        tudo->grid.move_count++;
        put_string(tudo); 
        if (tudo->grid.map_grid[tudo->indexs.i + 1][tudo->indexs.j] == 'F')
            {
                mlx_destroy_display(tudo->mlx_init);
                exit(0);
            }        
        if(tudo->grid.map_grid[tudo->indexs.i + 1][tudo->indexs.j] == 'C')
            tudo->grid.collectible_total--;
        tudo->grid.map_grid[tudo->indexs.i + 1][tudo->indexs.j] = 'P';
        tudo->grid.map_grid[tudo->indexs.i][tudo->indexs.j] = '0';
               
    }
    if (tudo->grid.collectible_total == 0)
        tudo->grid.map_grid[tudo->indexs.exit_i][tudo->indexs.exit_j] = 'F';
    loop_map_grid(tudo);
}