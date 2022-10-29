/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:41:16 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/10/30 00:03:57 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void loop_map_grid(t_tudo *tudo)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(i < tudo->map.height)
    {
        j = 0;
        while(j < tudo->map.width)
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
    while(i < tudo->map.height)
    {
        j = 0;
        while(j < tudo->map.width)
        {
            if (tudo->map.full_map[i][j] == 'P') 
            {
                tudo->indexs.i = i; 
                tudo->indexs.j = j;
                tudo->player_count++;
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
    while(i < tudo->map.height)
    {
        j = 0;
        while(j < tudo->map.width)
        {
            if (tudo->map.full_map[i][j] == 'C')
                tudo->collectible_total++;            
            j++;
        }       
        i++;
    }                         
}

void loop_number_of_sprites(t_tudo *tudo)
{
    int i;
    int j;
    
    i = 0;
    j = 0;    
    while(i < tudo->map.height)
    {
        j = 0;
        while(j < tudo->map.width)
        {
            if (tudo->map.full_map[i][j] == 'E')
            {
                tudo->indexs.exit_i = i;
                tudo->indexs.exit_j = j;
                tudo->exit_count++;
            }
            else if (tudo->map.full_map[i][j] == 'C')
                tudo->collectible_count++;
            else if (tudo->map.full_map[i][j] == '0')
                tudo->empty_spaces++;
            j++;
        }
        i++;
    }
}

void check_chars(t_tudo *tudo, char **s)
{
    int i;
    int j;    

    i = 0;
    j = 0; 
    while(i < tudo->map.height)
    {
        j = 0;        
        while(j < tudo->map.width)
        {            
                if(s[i][j] != '1' && s[i][j] != '0' && s[i][j] != 'C' && s[i][j] != 'E' && \
                s[i][j] != 'P')
                {
                    free_map(tudo->map.full_map);
                    free_map(tudo->map.tmp_grid);
                    error("Invalid character detected!!\n");                    
                }       
            
            j++;
        }
        i++;
    } 
}  