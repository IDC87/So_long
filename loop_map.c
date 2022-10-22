/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:41:16 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/10/19 21:38:24 by ivda-cru         ###   ########.fr       */
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
        i++;
    }   
    
}

void loop_grid(t_tudo *tudo)
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
            if (tudo->grid.map_grid[i][j] == 'P') 
            {
                tudo->indexs.i = i; 
                tudo->indexs.j = j;
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