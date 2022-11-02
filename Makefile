# -*- Makefile -*-

CC =	gcc

valgrind = valgrind

CFLAGS = -Wall -Wextra -Werror

MLX = -lbsd -lmlx -lXext -lX11

MLX_42 = -L./minilibx-linux -lbsd -lmlx -lXext -lX11

INCLUDES = -I ./libft -I ./mlx

LIBFT = ./libft/libft.a

SRCS =	so_long.c\
		utils_2.c\
		exit_game.c\
		create_map_sprites.c\
		loop_map.c\
		check_map.c\
		
		

valgrind = --leak-check=full \
			--error-limit=yes \
		--show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=valgrind-out.txt \
         

MAPS = Maps/bfs_map.ber	

OBJS =	$(SRCS:.c=.o)

compile: 
	rm -rf valgrind-out.txt

Solong:	compile #$(SRCS)
	$(CC) -g -std=c11 $(CFLAGS) -ggdb3 $(INCLUDES) $(SRCS) $(LIBFT) $(MLX) && valgrind $(valgrind) ./a.out $(MAPS)	

test:
	$(CC) $(CFLAGS) $(SRCS) $(MLX) $(LIBFT) #&& ./a.out Maps/map2.ber


#$(CC) -g -std=c11 $(CFLAGS) -ggdb3 $(INCLUDES) $(SRCS) $(LIBFT) $(MLX) && valgrind $(valgrind) ./a.out $(MAPS)
 

.PHONY: all clean fclean re