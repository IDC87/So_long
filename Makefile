# -*- Makefile -*-

CC =	gcc

valgrind = valgrind

CFLAGS = -Wall -Wextra -Werror

MLX = -lbsd -lmlx -lXext -lX11

MLX_42 = -L./minilibx-linux -lbsd -lmlx -lXext -lX11

FT_PRINTF = ./ft_printf/libftprintf.a

SRCS =	utils.c\
		utils_2.c\
		create_map_sprites.c\
		loop_map.c\
		check_map.c\
		so_long.c\

valgrind = --leak-check=full \
			--error-limit=yes \
		--show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=valgrind-out.txt \
         

MAPS = Maps/map3.ber	

OBJS =	$(SRCS:.c=.o)

compile: 
	rm -rf valgrind-out.txt

Solong:	compile $(SRC)
	 $(CC) -g -std=c11 $(CFLAGS) -ggdb3 $(SRCS) $(FT_PRINTF) $(MLX_42) && valgrind $(valgrind) ./a.out $(MAPS)


 

.PHONY: all clean fclean re