/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:12:20 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/10/26 20:02:07 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H 

#include "./minilibx-linux/mlx.h"
#include "./ft_printf/ft_printf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h> 

#define X_EVENT_KEY_PRESS 2
//#define X_EVENT_KEY_EXIT 0
#define X_EVENT_KEY_EXIT 17
#define SPRITE_RES_X_Y 44

#define LIGHT_GREY 0xd3d3d3
#define GOLD 0xffd700
#define RED 0xf90808

//#define LIST_QUEUE 20

/* #define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600 */

#define BUFFER_COUNT 7000

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

typedef struct s_indexs
{
    int i;
    int j;
    int exit_i;
    int exit_j;
    int player_start_i;
    int player_start_j;     

}   t_indexs;

typedef struct s_map
{
    int height;
    int width;
    char **full_map;      
    
}   t_map;

typedef struct s_tudo
{
    t_sprites sprites;
    t_map map;
    t_indexs indexs; 
    
    void *mlx_init;
    void *mlx_window;
    char *str_put;
    int collectible_total;
    int collectible_count;
    int exit_count;
    int player_count;
    int empty_spaces;
    int move_count;
    int sprite_x;
    int sprite_y;    
    
}   t_tudo;

size_t	ft_strlen_long(const char *s);
int	nbr_tokens(char const *s, char delimeter);
char	*token(const char *s, int columns, int index);
char	**words_divider(char const *s, char **words, char delimeter, int len);
char	**ft_split(char const *s, char delimeter);

int		len(long nb);
char	*ft_itoa(int nb);
char	*ft_strstr(char *str, char *to_find);
void	ft_bzero(void *s, size_t n);

int keyboard(int keycode, t_tudo *tudo);
void put_string(t_tudo *tudo);
void mouse_input(t_tudo *tudo);
int main (int argc, char **argv);

void move_sprite(t_tudo *tudo, int x, int y);
void error(char *text);
void error_free_m(t_tudo *tudo, char *text);
void	ft_bzero(void *s, size_t n);

void loop_map_grid(t_tudo *tudo);
void loop_grid(t_tudo *tudo);
void loop_grid_collectible(t_tudo *tudo);

void create_map(char *filename,int fd, t_tudo *tudo);
void check_map(t_tudo *tudo);
int exit_game(t_tudo *tudo);
void free_map(char **map);
t_sprites create_sprites(void *mlx_init);
void insert_sprites(t_tudo *tudo, int i, int j);

void loop_number_of_sprites(t_tudo *tudo);
void check_number_of_sprites(t_tudo *tudo);
void wall_check(t_tudo *tudo);
void enqueue(t_tudo *tudo, int r, int c);
void dequeue(t_tudo *tudo);
void check_valid_path(t_tudo *tudo);

#endif