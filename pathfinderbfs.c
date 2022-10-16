/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinderbfs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 20:12:11 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/10/16 17:37:03 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>
#include <errno.h>


#define BUFFER_COUNT 5000

int count = 0;
int size_of_queue = 15;

int rq[15];
int cq[15];

size_t	ft_strlen_long(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}


 int	nbr_tokens(char const *s, char delimeter)
{
	int	i;
	int	len;
	int	token_count;

	i = 0;
	len = 0;
	if (!(*s))
		return (0);
	token_count = 0;
	while (s[i])
	{
		if (s[i] == delimeter)
			len = 0;
		else if (++len == 1)
			token_count++;
		i++;
	}
	return (token_count);
}

 char	*token(const char *s, int columns, int index)
{
	char	*token;
	int		i;
	int		token_pos;

	i = 0;
	token_pos = index - columns;
	token = (char *)malloc(sizeof(char) * (columns + 1));
	while (i < columns)
	{
		token[i] = s[token_pos];
		i++;
		token_pos++;
	}
	token[i] = '\0';
	return (token);
}

char	**words_divider(char const *s, char **words, char delimeter, int len)
{
	int		rows;
	int		columns;
	size_t	i;

	rows = 0;
	columns = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] == delimeter)
			len = 0;
		else if (++len == 1)
		{
			while (s[i] != delimeter && s[i] != '\0')
			{
				columns++;
				i++;
			}
			words[rows++] = token(s, columns, i);
			columns = 0;
			i--;
		}
	}
	words[rows] = NULL;
	return (words);
}

char	**ft_split(char const *s, char delimeter)
{
	char	**words;
	char	**str;
	int		len;

	len = 0;
	if (!s)
		return (0);
	words = (char **)malloc(sizeof(char *) * (nbr_tokens(s, delimeter) + 1));
	if (words == NULL)
		return (NULL);
	str = words_divider(s, words, delimeter, len);
	return (str);
}

void enqueue(int r, int c)
{
   rq[count] = r;
   cq[count] = c;
    count++;    
    
} 

void dequeue()
{
    int i;
    
    i = 0;
    rq[count] = rq[0];
    cq[count] = cq[0];

    while(i < count)
    {
        rq[i] = rq[i + 1];
        cq[i] = cq[i + 1];
        i++;
        
    }
    count--;
    
}

void check_valid_path(char **grid_map, int sr, int sc, int R, int C)
{        

    int rr = 0;
    int cc = 0;  

    int r;
    int c;

    int dr[4] = {-1, 1, 0, 0}; 
    int dc[4] = {0, 0, 1, -1}; //direction vectors for adjacent cells

    

    int move_count = 0;
    int nodes_left_in_layer = 1;
    int nodes_left_next_layer = 0;     

     int i = 0;
     count = 0;  

    
     
       printf("starting row and col %d %d\n", sr, sc);
       
    enqueue(sr, sc);
    printf("RQ[0] is %d\n", rq[0]);
    i = 0;

    grid_map[sr][sc] = 'V'; // fills the map with V of visited

    printf("V is: %c\n", grid_map[1][6]);

    printf("move count %d\n", size_of_queue);
    int j = 0;
    while (j < (R  * C)) //size_of_queue > 0
    {
        r = rq[0];
        c = cq[0];
        dequeue();
        if (grid_map[r][c] == 'E')
        {
            printf("EXIT FOUND in coordinate r[%d] c[%d]", r, c);
            break;
        }
        
     //explore neighbours. to put in another function later
        i = 0;
        while (i < 4) // 4 because of the four adjacent positions
        {
            rr = r + dr[i];
            cc = c + dc[i];
            
            if ((rr > 0 || cc > 0) && (rr <= R || cc <= C))
            {
                if (grid_map[rr][cc] != '1' && grid_map[rr][cc] != 'V')
                {    
                    enqueue(rr, cc);  
                    if (grid_map[rr][cc] == 'E')
                        break;              
                    grid_map[rr][cc] = 'V';
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
            printf("MOVE COUNT %d\n", move_count);
        } 
        j++;      
           

    }
}

int main (int arcg, char **argv)
{
    
    int fd;
    char *buf;
    int bytes_read;
    char **grid_map;
    
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        {
            perror("Error\n");
            exit(0);            
        }
    buf = (char *)malloc(sizeof(char) * BUFFER_COUNT);
    bytes_read = read(fd, buf, BUFFER_COUNT);
    buf[bytes_read] = '\0';

    grid_map = ft_split(buf, '\n');

    free(buf);

    check_valid_path(grid_map, 4, 3, 7, 8);
    
    return 0;
}
    