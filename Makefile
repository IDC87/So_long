# -*- Makefile -*-

CC =	gcc

CFLAGS = -Wall -Wextra -Werror

MLX = -lbsd -lmlx -lXext -lX11

SRCS =	utils.c\
		create_map_sprites.c\
		loop_map.c\
		keyboard_logic.c\
		so_long.c\

MAPS = Maps/map1.ber	

OBJS =	$(SRCS:.c=.o)

Solong:	$(SRC)
	$(CC) $(CFLAGS) $(SRCS) $(MLX) && ./a.out $(MAPS)


 

.PHONY: all clean fclean re