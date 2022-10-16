# -*- Makefile -*-

CC =	gcc

CFLAGS = -Wall -Wextra -Werror

MLX = -lbsd -lmlx -lXext -lX11

SRCS =	utils.c\
		utils_2.c\
		create_map_sprites.c\
		loop_map.c\
		keyboard_logic.c\
		put_string_display.c\
		check_map.c\
		so_long.c\

MAPS = Maps/map2.ber	

OBJS =	$(SRCS:.c=.o)

Solong:	$(SRC)
	$(CC)  $(SRCS) $(MLX) 


 

.PHONY: all clean fclean re