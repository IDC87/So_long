/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 12:47:22 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/10/22 18:06:59 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void not_rect(t_tudo *tudo)
{
    if  (tudo->grid.width == tudo->grid.height)
    {
        printf("ERROR\n Map cannot be a square!\n");
        exit(0);
    }
    
}



void loop_surrounded_by_walls(t_tudo *tudo)
 {  
    int i;
    int j;
    
    i = 0;
    j = 0;
    
    while(i < tudo->grid.height)
    {   
        
        j = 0;
        if  (tudo->grid.map_grid[i][0] != '1' || tudo->grid.map_grid[i][tudo->grid.width - 1] != '1')
        {
            printf("ERROR\n Map must be surrounded by walls\n");
            exit(0);
        }
        
        while(j < tudo->grid.width)
        {
            if  (tudo->grid.map_grid[0][j] != '1' || tudo->grid.map_grid[tudo->grid.height - 1][j] != '1')
            {
                printf("ERROR\n Map must be surrounded by walls\n");
                exit(0);
            }            
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
    
    while(i < tudo->grid.height)
    {
        j = 0;
        while(j < tudo->grid.width)
        {
            if (tudo->grid.map_grid[i][j] == 'E')
            {
                tudo->indexs.exit_i = i;
                tudo->indexs.exit_j = j;
                tudo->grid.exit_count++;
            }
            else if (tudo->grid.map_grid[i][j] == 'P')
            {
                tudo->indexs.player_start_i = i;
                tudo->indexs.player_start_j = j;
                tudo->grid.player_count++;
            }
            else if (tudo->grid.map_grid[i][j] == 'C')
                tudo->grid.collectible_count++;
            else if (tudo->grid.map_grid[i][j] == '0')
                tudo->grid.empty_spaces++;
            j++;
        }
        i++;
    }
}

void check_number_of_sprites(t_tudo *tudo)
{
    loop_number_of_sprites(tudo);
    
    if (tudo->grid.exit_count != 1)
    {
      printf("ERROR\n Wrong number of Exits\n");
      mlx_destroy_display(tudo->mlx_init);
        exit(0);  
    }
    if (tudo->grid.player_count != 1)
    {
      printf("ERROR\n Must have 1 Player start\n");
        exit(0);  
    }
    if (tudo->grid.collectible_count < 1)
    {
      printf("ERROR\n Must have at least one collectible\n");
        exit(0);  
    }
}

/* void enqueue(t_tudo *tudo, int r, int c)
{
   tudo->queue.rq[tudo->queue.count] = r;
   tudo->queue.cq[tudo->queue.count] = c;
    tudo->queue.count++;    
    printf("SIZE OF QUEUE: %d\n", tudo->queue.count);
    
} 

void dequeue(t_tudo *tudo)
{
    int i;
    
    i = 0;
    tudo->queue.rq[tudo->queue.count] = tudo->queue.rq[0];
    tudo->queue.cq[tudo->queue.count] = tudo->queue.cq[0];

    while(i < tudo->queue.count)
    {
        tudo->queue.rq[i] = tudo->queue.rq[i + 1];
        tudo->queue.cq[i] = tudo->queue.cq[i + 1];
        i++;
        
    }
    tudo->queue.count--;
    
}

void check_valid_path(t_tudo *tudo)
{
   int dr[4] = {-1, 1, 0, 0};
   int dc[4] = {0, 0, 1, -1};
   int i;
   int r;
   int c;
   int rr;
   int cc;
    

    tudo->queue.size_of_queue = tudo->grid.empty_spaces + tudo->grid.collectible_count;
    tudo->queue.rq = (int *)malloc(sizeof(tudo->queue) * (5));
    tudo->queue.cq = (int *)malloc(sizeof(tudo->queue) * (5));
    
    while (i < tudo->queue.size_of_queue)
    {
       tudo->queue.cq[i] = 0;
       tudo->queue.cq[i] = 0;
       i++;
    }

   tudo->queue.move_count = 0;
    tudo->queue.nodes_left_in_layer = 1;
    tudo->queue.nodes_in_next_layer = 0; 
     tudo->queue.count = 0; 
       i = 0;
    enqueue(tudo, tudo->indexs.player_start_i, tudo->indexs.player_start_j);
    tudo->grid.temp_grid[tudo->indexs.player_start_i][tudo->indexs.player_start_j] = 'V'; 
     int j = 0;
    while (tudo->queue.count) 
    {
        
        r = tudo->queue.rq[0];
        c = tudo->queue.cq[0];
        dequeue(tudo);
        if (tudo->grid.temp_grid[r][c] == 'E')
        {
            printf("EXIT FOUND in coordinate r[%d] c[%d]\n\n", r, c);
            break;
        }
        
     //explore neighbours. to put in another function later
        i = 0;
        while (i < 4) // 4 because of the four adjacent positions
        {
            rr = r + dr[i];
            cc = c + dc[i];
            
            if ((rr > 0 || cc > 0) && (rr <= tudo->grid.width || cc <= tudo->grid.height))
            {
                if (tudo->grid.temp_grid[rr][cc] != '1' && tudo->grid.temp_grid[rr][cc] != 'V')
                {    
                    enqueue(tudo, rr, cc);  
                    if (tudo->grid.temp_grid[rr][cc] == 'E')
                        break;              
                    tudo->grid.temp_grid[rr][cc] = 'V';
                    tudo->queue.nodes_in_next_layer++;
                }                
            }
            i++;  
        
        }
        tudo->queue.nodes_left_in_layer--;
        if (tudo->queue.nodes_left_in_layer == 0)
        {
            tudo->queue.nodes_left_in_layer = tudo->queue.nodes_in_next_layer;
            tudo->queue.nodes_in_next_layer = 0;
            tudo->queue.move_count++;
        } 
        j++;  

          printf("ROW QUEUE %d\n\n", tudo->queue.rq[j]);  
           
        printf("WHILE SIZE OF QUEUE %d\n\n", tudo->queue.count);
        
    }
    free(tudo->queue.rq);
        free(tudo->queue.cq);
} */



/* void check_valid_path(t_tudo *tudo)
{
    int *row;
    int *col;
    int i;
    int j;
    int k;
    int new_row;
    int new_col;
    int walkable_slots;

    walkable_slots = tudo->grid.empty_spaces + tudo->grid.collectible_count;

    row = (int *)malloc(sizeof(int) * (walkable_slots));
    col = (int *)malloc(sizeof(int) * (walkable_slots));

    i = 0;
    k = 0;
    while(i < tudo->grid.height)
    {     
        j = 0;
        while(j < tudo->grid.width)
        {
           if(tudo->grid.temp_grid[i][j] == '0' || tudo->grid.temp_grid[i][j] == 'C' )
           {
            row[k] = i;
            col[k] = j;
            k++;
           }
            j++;
        }
        i++;
    }
    i = 0;
    while (i < (tudo->grid.empty_spaces + tudo->grid.collectible_count))
    {
        printf("row[%d] col[%d]\n", row[i], col[i]);
        i++;        
    }

    new_row = tudo->indexs.player_start_i;
    new_col = tudo->indexs.player_start_j;
    
    while (walkable_slots > 0)
    {
        i = 0;
        while (i < 4)
    }



    
} */





