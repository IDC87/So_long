# -*- Makefile -*-

CC =	gcc

MLX = -lbsd -lmlx -lXext -lX11

SRCS =	Get_next_line/get_next_line.c\
		Get_next_line/get_next_line_utils.c\
		another_version.c\
	

OBJS =	$(SRCS:.c=.o)

Solong:	$(SRC)
	$(CC) $(SRCS) $(MLX) && ./a.out map1.ber


 

.PHONY: all clean fclean re