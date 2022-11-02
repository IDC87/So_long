/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:12:20 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/11/02 14:45:18 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H 

//# include "./minilibx-linux/mlx.h"
# include <mlx.h>
# include "./libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h> 

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_EXIT 17
# define SPRITE_RES_X_Y 44

# define LIGHT_GREY 0xd3d3d3
# define GOLD 0xffd700
# define RED 0xf90808
# define BUFFER_COUNT 5000

typedef struct s_sprites
{
	void	*sapo1;
	void	*grass1;
	void	*wall1;
	void	*exit1;
	void	*collectible1;
	void	*polluted_water;

}	t_sprites;

typedef struct s_indexs
{
	int	i;
	int	j;
	int	exit_i;
	int	exit_j;

}	t_indexs;

typedef struct s_map
{
	int		height;
	int		width;
	char	**full_map;
	char	**tmp_grid;

}	t_map;

typedef struct s_tudo
{
	t_sprites	sprites;
	t_map		map;
	t_indexs	indexs;
	void		*mlx_init;
	void		*mlx_window;
	char		*str_put;
	int			collectible_total;
	int			collectible_count;
	int			collectible_debug_count;
	int			exit_count;
	int			player_count;
	int			empty_spaces;
	int			move_count;
	int			sprite_x;
	int			sprite_y;

}	t_tudo;

void		check_map(t_tudo *tudo);
void		wall_check(t_tudo *tudo);
void		check_number_of_sprites(t_tudo *tudo);
void		check_valid_path(t_tudo *tudo);
void		nodes_vector(t_tudo *tudo, int x, int y);

int			keyboard(int keycode, t_tudo *tudo);
t_sprites	create_sprites(void *mlx_init);
void		insert_sprites(t_tudo *tudo, int i, int j);
void		move_sprite(t_tudo *tudo, int x, int y);
void		put_string(t_tudo *tudo);

void		check_gaps( char *buf, int bytes);
int			exit_game(t_tudo *tudo);
void		free_map(char **map);
void		error(char *text);
void		error_free_m(t_tudo *tudo, char *text);

void		loop_map_grid(t_tudo *tudo);
void		loop_grid(t_tudo *tudo);
void		loop_grid_collectible(t_tudo *tudo);
void		loop_number_of_sprites(t_tudo *tudo);
void		check_chars(t_tudo *tudo, char **s);

void		process_map(t_tudo *tudo, char *buf, size_t bytes);
void		import_map(char *filename, int fd, t_tudo *tudo);
void		initialize_game(t_tudo *tudo);
void		initialize_variables(t_tudo *tudo);
int			main(int argc, char **argv);

char		*ft_strstr(char *str, char *to_find);
void		error_and_free(t_tudo *tudo, char *text);

#endif