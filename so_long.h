/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:12:20 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/10/03 17:51:20 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H 

#include <mlx.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h> 

#define X_EVENT_KEY_PRESS 3
#define X_EVENT_KEY_EXIT 0

#define LIGHT_GREY 0xd3d3d3
#define GOLD 0xffd700
#define RED 0xf90808

/* #define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600 */

#define BUFFER_COUNT 5000

#define sapinho "./sprites_Solong/player_64px.xpm"
#define grass "./sprites_Solong/grass_64px.xpm"
#define wall "./sprites_Solong/wall_64px.xpm"
#define player_exit "./sprites_Solong/exit.xpm"
#define player_collectible "./sprites_Solong/collectible.xpm"
#define polluted_lake "./sprites_Solong/lake_polluted.xpm"

typedef struct s_sprites
{
    
    void *sapo1;
    void *grass1;
    void *wall1;
    void *exit1;
    void *collectible1;
    void *polluted_water;
        
}   t_sprites;

typedef struct s_grid
{
    int width;
    int height;
    int fd;

    char *new_line;
    char **map_grid;

    int collectible_total;

    int move_count;
    
}   t_grid;

typedef struct s_indexs
{
    int i;
    int j;

    int exit_i;
    int exit_j;

    int mouse_x;
    int mouse_y;

}   t_indexs;


typedef struct s_img
{
    void        *mlx_img;
    char        *pixels;
    int         bits_per_pixel;
    int         line_size;
    int         endian;
    
    int         squareX;
    int         squareY;
    
}   t_img;

typedef struct s_rect
{
    int x;
    int y;

    int width;
    int height;

    int color;
    
}   t_rect;

typedef struct s_tudo
{
    void *mlx_init;
    void *mlx_window;   

    t_sprites sprites;

    t_img   img;

    t_indexs indexs;
   
    
    int tela_x;
    int tela_y;
    
    int position_x;
    int position_y;

    t_grid grid;

    int sapo_x;
    int sapo_y;    
    
}   t_tudo;

size_t	ft_strlen_long(const char *s);
int	nbr_tokens(char const *s, char delimeter);
char	*token(const char *s, int columns, int index);
char	**words_divider(char const *s, char **words, char delimeter, int len);
char	**ft_split(char const *s, char delimeter);

char	*ft_strdup(const char *s);
int	itoa_size(int n);
char	*convertion(char *str, int n, int len, int j);
char	*ft_itoa(int n);

int keyboard(int keycode, t_tudo *tudo);
void put_string(t_tudo *tudo);
void mouse_input(t_tudo *tudo);
int main (int argc, char **argv);

void move_to_the_right(t_tudo *tudo);
void move_to_the_left(t_tudo *tudo);
void move_up(t_tudo *tudo);
void move_down(t_tudo *tudo);

void loop_map_grid(t_tudo *tudo);
void loop_grid(t_tudo *tudo);
void loop_grid_collectible(t_tudo *tudo);

void create_map(char *filename, t_grid *map);
void create_sprites(t_tudo *tudo);
void insert_sprites(t_tudo *tudo, int i, int j);

void not_rect(t_grid *map);

#endif