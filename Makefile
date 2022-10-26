# -*- Makefile -*-

CC =	gcc

valgrind = valgrind

CFLAGS = -Wall -Wextra -Werror

MLX = -lbsd -lmlx -lXext -lX11

MLX_42 = -L./minilibx-linux -lbsd -lmlx -lXext -lX11

SRCS =	utils.c\
		utils_2.c\
		create_map_sprites.c\
		loop_map.c\
		check_map.c\
		so_long.c\

valgrind = --leak-check=full \
		--show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=valgrind-out.txt \
         

MAPS = Maps/map2.ber	

OBJS =	$(SRCS:.c=.o)

compile: 
	rm -rf valgrind-out.txt

Solong:	compile $(SRC)
	 $(CC) -g -std=c11 $(CFLAGS) -ggdb3 $(SRCS) $(MLX_42) && valgrind $(valgrind) ./a.out $(MAPS)


 

.PHONY: all clean fclean re