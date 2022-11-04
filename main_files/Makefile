# -*- Makefile -*-

CC =	gcc

NAME = so_long

#valgrind = valgrind

CFLAGS = -Wall -Wextra -Werror

SRCS =	so_long.c\
		utils.c\
		exit_game.c\
		create_map_sprites.c\
		loop_map.c\
		check_map.c\

BONUS = ./so_long_bonus/so_long_bonus.c\
		./so_long_bonus/utils_bonus.c\
		./so_long_bonus/exit_game_bonus.c\
		./so_long_bonus/create_map_sprites_bonus.c\
		./so_long_bonus/loop_map_bonus.c\
		./so_long_bonus/check_map_bonus.c\

valgrind = --leak-check=full \
		--error-limit=yes \
		--show-leak-kinds=all \
        --track-origins=yes \
        --verbose \
        --log-file=valgrind-out.txt \


MLX_HOME = -lbsd -lmlx -lXext -lX11

MLX_42 = -L../minilibx-linux -lbsd -lmlx -lXext -lX11

INCLUDES = -I ./libft -I ./mlx

I_BONUS = so_long_bonus.h

MLX_LIB = ../minilibx-linux

LIBFT_A = ./libft/libft.a

LIBFT_DIR = ./libft

MAPS = Maps/map2.ber	

BOLD	:= \033[1m
BLACK	:= \033[30;1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
BLUE	:= \033[34;1m
MAGENTA	:= \033[35;1m
CYAN	:= \033[36;1m
WHITE	:= \033[37;1m
RESET	:= \033[0m

OBJS = $(SRCS:%.c=%.o)
BOBJS = $(BONUS:%.c=%.o)       

all: $(NAME)

$(NAME) : $(OBJS)
	@make all -C $(LIBFT_DIR) --no-print-directory
	@make -C $(MLX_LIB) --no-print-directory
	@$(CC) -o $(NAME) $(OBJS) $(LIBFT_A) $(MLX_42)

bonus : $(BOBJS)
	@make all -C $(LIBFT_DIR) --no-print-directory
	@make -C $(MLX_LIB) --no-print-directory
	@$(CC) -o $(NAME) $(BOBJS) $(LIBFT_A) $(MLX_42)

install : $(BOBJS)
	@sudo apt update && sudo apt install build-essential libx11-dev libglfw3-dev libglfw3 xorg-dev -y
	@make all -C $(LIBFT_DIR) --no-print-directory
	@make -C $(MLX_LIB) --no-print-directory
	@$(CC) -o $(NAME) $(BOBJS) $(LIBFT_A) $(MLX_42)
	@make clean
	@echo
	@echo "$(GREEN)>>>>SOURCE FILES, $(NAME) EXEC AND X11 PACKAGES SUCESSUFUL INSTALLED!<<<<"
	@echo "$(MAGENTA)made by IDC87"
	@echo

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@  $<
#	$(CC) $(CFLAGS) -c -o $@ -I./ $<
	@echo ">>>>FILE $(NAME) CREATED!<<<<"

clean:
	@rm -f $(OBJS)
	@rm -f $(BOBJS)
	@make clean -C $(MLX_LIB) --no-print-directory
	@make clean -C $(LIBFT_DIR) --no-print-directory

fclean:	clean
		@rm -f $(NAME)		
		@make fclean -C $(LIBFT_DIR) --no-print-directory
		@echo ">>>>FILE $(NAME) & Objects DELETED!<<<<"

re: fclean all

compile: 
	rm -rf valgrind-out.txt

valgrind:	$(NAME)
		valgrind $(valgrind) ./$(NAME) $(MAPS)
		

play:
	./so_long Maps/map2.ber

#$(shell find ./mainfiles/ -name "*.c")
#$(CC) -g -std=c11 $(CFLAGS) -ggdb3 $(INCLUDES) $(SRCS) $(LIBFT) $(MLX) && valgrind $(valgrind) ./a.out $(MAPS)
 

.PHONY: all clean fclean re