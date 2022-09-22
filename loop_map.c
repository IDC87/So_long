/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:41:16 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/09/22 16:41:44 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void loop_map_grid(t_tudo *tudo)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(i < tudo->grid.height)
    {
        j = 0;
        while(j < tudo->grid.width)
        {
            insert_sprites(tudo, i, j);
            j++;
        }
        //printf("\n");
        i++;
    }   
    
}


void loop_grid(t_tudo *tudo)
{
    int i;
    int j;
    int k;

    i = 0;
    j = 0;
    k = 0;

    if (tudo->grid.collectible_total == 0)
        tudo->grid.map_grid[tudo->indexs.exit_i][tudo->indexs.exit_j] = 'F';
    
    while(i < tudo->grid.height)
    {
        j = 0;
        while(j < tudo->grid.width)
        {
            if (tudo->grid.map_grid[i][j] == 'P') 
            {
                tudo->indexs.i = i; 
                tudo->indexs.j = j;
                exit;
            } 
            j++;
        }       
        i++;
    }  
    
}

void loop_grid_collectible(t_tudo *tudo)
{
    int i;
    int j;

    i = 0;
    j = 0;
    
    while(i < tudo->grid.height)
    {
        j = 0;
        while(j < tudo->grid.width)
        {
            if (tudo->grid.map_grid[i][j] == 'C')
                tudo->grid.collectible_total++;            
            j++;
        }       
        i++;
    }                         
}