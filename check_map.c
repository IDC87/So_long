/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 12:47:22 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/10/14 17:57:08 by ivda-cru         ###   ########.fr       */
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
      printf("Exits total = [%d]\n", tudo->grid.exit_count);
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

void enqueue(t_tudo *tudo, int r, int c)
{
   tudo->queue.rq[tudo->queue.count] = r;
   tudo->queue.cq[tudo->queue.count] = c;
    tudo->queue.count++;    
    printf("Current queue with 5 values in index %d x[%d] y[%d]\n", tudo->queue.count, tudo->queue.rq[tudo->queue.count], tudo->queue.cq[tudo->queue.count]);  
} 

void dequeue(t_tudo *tudo)
{
    int i;

    tudo->queue.size_of_queue = tudo->grid.empty_spaces + tudo->grid.collectible_count;
   tudo->queue.rq = (int *)malloc(sizeof(int) * (tudo->queue.size_of_queue + 1000));
    tudo->queue.rq = (int *)malloc(sizeof(int) * (tudo->queue.size_of_queue + 1000));
    
    i = 0;
    tudo->queue.rq[tudo->queue.count] = tudo->queue.rq[0];
    tudo->queue.cq[tudo->queue.count] = tudo->queue.cq[0];

    while(i < tudo->queue.count - 1)
    {
        tudo->queue.rq[i] = tudo->queue.rq[i + 1];
        tudo->queue.cq[i] = tudo->queue.cq[i + 1];
        i++;
        
    }
    tudo->queue.count--;
    
}

void check_valid_path(t_tudo *tudo)
{    
     
        
    
    int R = tudo->grid.height;
    int C = tudo->grid.width; // grid dimensions

    int rr = 0;
    int cc = 0;  

    int sr = tudo->indexs.player_start_i;
    int sc = tudo->indexs.player_start_j; // Player start positions in x and y
    int r = tudo->indexs.player_start_i;
    int c = tudo->indexs.player_start_j;

    int dr[4] = {-1, 1, 0, 0}; 
    int dc[4] = {0, 0, 1, -1}; //direction vectors for adjacent cells

    

    int move_count = 0;
    int nodes_left_in_layer = 1;
    int nodes_left_next_layer = 0;     

     int i = 0;
     tudo->queue.count = 0;  

    
     /* while (i < tudo->queue.size_of_queue - 2)
    {
        tudo->queue.rq[i] = 0;
        tudo->queue.cq[i] = 0;
        i++;
    }    */
       printf("starting row and col %d %d\n", sr, sc);
       printf("Queue count %d\n", tudo->queue.count);
       printf("RQ[0] is %d\n", tudo->queue.rq[0]);
   enqueue(tudo, 4, 3);
    i = 0;

    //tudo->grid.temp_grid[sr][sc] = 'V'; // fills the map with V of visited

    

    /* while (i < 12 ) //tudo->queue.size_of_queue > 0
    {
        dequeue(tudo);
        r = tudo->queue.rq[0];
        c = tudo->queue.cq[0];
        if (tudo->grid.temp_grid[r][c] == 'E')
        {
            printf("EXIT FOUND");
            break;
        }
        
     //explore neighbours. to put in another function later
        i = 0;
        while (i < 4) // 4 because of the four adjacent positions
        {
            if ((rr < 0 || cc < 0) && (rr >= R || cc >= C))
            {
                if (tudo->grid.temp_grid[rr][cc] != '1' && tudo->grid.temp_grid[rr][cc] != 'V')
                {
                    rr = r + dr[i];
                    cc = c + dc[i];
                    enqueue(tudo, rr, cc);
                    tudo->grid.temp_grid[rr][cc] = 'V';
                    nodes_left_next_layer++;
                }
                
            }
            i++;       
        
        }
        nodes_left_in_layer--;
        if (nodes_left_in_layer == 0)
        {
            nodes_left_in_layer = nodes_left_next_layer;
            nodes_left_next_layer = 0;
            move_count++;
        }

        //free(tudo->grid.temp_grid);

        i = 0;
    while(i < 5)
    {
        printf("Current queue with 5 values in index %d x[%d] y[%d]\n", i, tudo->queue.rq[i], tudo->queue.cq[i]);
        i++;
    }

    i = 0;
    while(i < 5)
    {
        printf("dequeing 2 values in index %d x[%d] y[%d]\n", i, tudo->queue.rq[i], tudo->queue.cq[i]);
        i++;
    }      

    

    }
     */

    
    
    
    

    
    

    

    

    
}

    


 


 
