# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/06 20:37:19 by ivda-cru          #+#    #+#              #
#    Updated: 2021/11/09 21:26:29 by ivda-cru         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*- Makefile -*-




#  ---- NOTES ----

#OPTIONS
 #@ - to not display in console the command forwarded by this char
 #$ - like a variable declaration
 #$@ is the NAME of the target being generated
 #$< the NAME of the first prerequisite (usually a source file) (dependencies)
 #.PHONY: - one that is not really the name of a file; rather it is just a name for a recipe to be executed
 #gcc -c - compiles to the .o files
 #:= variable evaluated once at assignment time 
 #= evaluated each time it's used (for reference)
 #wildcard -  wildcard card function in make file is to list all the source files with a particular extension
 #patsubst - function to rewrite file names
 # -f to use a makefile with a different name
 # "%.o: %.c" means that any file ending in .o depends on the same filename ending in .c to be present.
 # PS1="\W >" -trims the terminal command prompt 
 # PROMPT_DIRTRIM=2 -also trims terminal (number can be changed acording to desire)
 # CTRL + K and then press S - saves all projects at once in VScode
 # sudo apt-get install -y ascii - instalar tabela ascii no bash (melhor que a por defeito)
 # shell find . -type f -name '*.c') - the basic syntax to find stuff

 #SHELL TERMINAL OPTIONS ENV
 # Trimming and colorful terminal - PS1='\e[33;1m\u@\h: \e[31m\W\e[0m\$ '
 #color options:
 #export COLOR_NC='\e[0m' # No Color
 #export COLOR_BLACK='\e[0;30m'
 #export COLOR_GRAY='\e[1;30m'
 #export COLOR_RED='\e[0;31m'
 #export COLOR_LIGHT_RED='\e[1;31m'
 #export COLOR_GREEN='\e[0;32m'
 #export COLOR_LIGHT_GREEN='\e[1;32m'
 #export COLOR_BROWN='\e[0;33m'
 #export COLOR_YELLOW='\e[1;33m'
 #export COLOR_BLUE='\e[0;34m'
 #export COLOR_LIGHT_BLUE='\e[1;34m'
 #export COLOR_PURPLE='\e[0;35m'
 #export COLOR_LIGHT_PURPLE='\e[1;35m'
 #export COLOR_CYAN='\e[0;36m'
 #export COLOR_LIGHT_CYAN='\e[1;36m'
 #export COLOR_LIGHT_GRAY='\e[0;37m'
 #export COLOR_WHITE='\e[1;37m'

 #COMPLILING OPTIONS
 #gcc -WALL -WEXTRA -WERROR
 # -WALL (Enable all warning messages)
 # -WERROR (Make all warnings into erros)
 # -WEXTRA (enable extra warnings)
 # -E (Preprocessor), -S (compiler), -c (assembler)
 # gcc -c name.c && mv name.o folder/ (compiles then move to another folder)
 #gcc -WALL -WEXTRA -WERROR -c nome.c (para compilar o objecto .o)
 # -I (flag that indicates the libft.h)

#FUNCTIONS
 #$(shell date) - show the current time and date
 #$(shell sleep 'time')

#GIT UPLOAD COMMANDS (as they appear in the beginning of a new repo):
 #echo "# Repo_test" >> README.md
 #git init
 #git add README.md
 #git commit -m "first commit"
 #git branch -M main
 #git remote add origin https://github.com/IDC87/Repo_test.git
 #git push -u origin main



 # UPDATING CREDENTIALS ON GIT

# !!!!Nao esquecer de ir aos credentials manager em control options no PC primeiro!!!!!

 # git config --global credential.helper cache //////IMPORTANTE! keeps cache token in the computer when using https method
 # git config --unset credential.helper 'cache'
 # git config --global --unset credential.helper 'cache'
 # git config --system --unset credential.helper 'cache'

# git config --set credential.helper 'cache --timeout=600'
# git config --global --set credential.helper 'cache --timeout=600'
# git config --system --set credential.helper 'cache --timeout=600'

# FIM das Credentials


 #…or push an existing repository from the command line
 #git remote add origin https://github.com/IDC87/Repo_test.git
 #git branch -M main
 #git push -u origin main

#GIT GENERAL COMMANDS:
 # git rev-parse HEAD - shows the last sha key 
 # git remote get-url origin - shows my current url origin
 # git remote show origin - almost the same, with more details
 # git remote -v - view all the remotes of current repository
 # git remote rm origin/upstream - remove current git url in origin/upstream
 # git push --set-upstream origin master - set the current url as upstream


 #target: dependencies
#	action

#MAKEFILE MUST CONTAIN RULES: $(NAME), all, clean, fclean, re.
#BONUSES MUST BE IN _bonus.{c/h}

#A FAZER:
 #ler ficheiros executaveis com todas as opcoes


 # VER LINKs (Importante) : https://cs.colby.edu/maxwell/courses/tutorials/maketutor/

 


#  /---- END OF NOTES ----/

NAME = libft.a
OBJS = $(SRCS:.c=.o) #Apenas este comando chega como suficiente para criar os objects files
BOBJS = $(BONUS:.c=.o)
RM = rm -f

#TESTS	= tests/test1.c
#TNAME	= test
#TOBJS	= ${TESTS:.c=.o}

#COMPILING VARIABLES
CC = gcc
CCmove = $(CC) -c $(SRCS) && mv
CFLAGS = -Wall -Wextra -Werror #-I #-g #--save --temps
HEADER = libft.h

#TARGET PROGRAM
TARGET = program

#Trim Terminal
Trim = PS1="\W >"
Trim2 = PS1="[\W]\\$ "
Trimlength = PROMPT_DIRTRIM=1


#EXTRAS
SHOUT = say
SHELL = /bin/sh
#SHELL := /bin/bash
count_message = Number of source files in folder

#DIRECTORIES FOR .o FILES
OBJDIR := OBJECTS/

MakefileREPO = git remote add origin https://github.com/IDC87/Makefile-WIP-.git
LibftREPO = git remote add origin https://github.com/IDC87/Libft_42_school.git
TestREPO = git remote add origin https://github.com/IDC87/Repo_test.git
DummyREPO = git remote add origin https://github.com/IDC87/Repo_test.git
GitPush = git push -u origin main
SetStream = git push --set-upstream origin master
CleanUrl = git remote rm origin

TESTS	= tests/test1.c
TNAME	= test
TOBJS	= ${TESTS:.c=.o}

SRCS = ft_bzero.c\
	ft_isalnum.c\
	ft_isalpha.c\
	ft_isascii.c\
	ft_isdigit.c\
	ft_isprint.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_memset.c\
	ft_strlen.c\
	ft_strlcpy.c\
	ft_strlcat.c\
	ft_toupper.c\
	ft_tolower.c\
	ft_strchr.c\
	ft_strrchr.c\
	ft_strncmp.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_strnstr.c\
	ft_atoi.c\
	ft_calloc.c\
	ft_strdup.c\
	ft_substr.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_itoa.c\
	ft_split.c\
	ft_strmapi.c\
	ft_striteri.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\

BONUS = ft_lstnew_bonus.c\
		ft_lstadd_front_bonus.c\
		ft_lstsize_bonus.c\
		ft_lstlast_bonus.c\
		ft_lstadd_back_bonus.c\
		ft_lstdelone_bonus.c\
		ft_lstclear_bonus.c\
		ft_lstiter_bonus.c\
	

#>>>>>NECESSARIO PARA ENTREGA<<<<<<

all: $(NAME)



$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	ranlib $(NAME)
# rcs means replace, create, sort
#	$(CC) -o $@ $^ $(CFLAGS)
	@echo ">>>>>>>>>THE END<<<<<<<<<<"
	@echo ">>>>FILE $(NAME) CREATED!<<<<"

# clean deletes all Emacs and Vim temporary files along with the executable
clean:
	$(RM) $(OBJS)
	$(RM) $(BOBJS)
#rm -rf ./$(OBJDIR)/*.o

# fclean deletes the Emacs temporary files, the executable, and the object files
fclean: clean
	$(RM) $(NAME)

# re forces recompilation of all source files
re: fclean all

bonus: $(BOBJS)
	ar rcs $(NAME) $(OBJS) $(BOBJS)
	ranlib $(NAME)

#test: re ${TOBJS}
#	${CC} -g ${CFLAGS} ${TOBJS} -L. -lft -o ${TNAME}

.PHONY: all clean fclean re

#>>>>>FIM DOS FICHEIROS OBRIGATORIOS<<<<<<

tclean:
	$(RM) $(OBJS) $(NAME)
	@echo ">>>>>ALL .o FILES AND .a ERASED<<<<<"


# COMPILE to .o and then moves to proper folder
Libft: $(SRC)
	$(CC) -c $(SRCS) && mv *.o $(OBJDIR)


#transform .c files in object files
#%.o : %.c $(HEADER)
#	$(CC) -c -o $@ $< $(CFLAGS)	


trim:
	$(Trim)
trim2:
	PS1='\e[36;1m\u@\h: \e[34m\W\e[0m\$ '

cfiles:
	@echo
	@echo "NUMBER OF SOURCE(.c) FILES ARE:"
	@ls -l *.c | wc -l
	@echo
	@echo "NUMBER OF OBJECT(.o) FILES ARE:"
	@ls -l *.o | wc -l
	@echo


#GIT BLOCK COMMANDS:

fetch: 
	@git fetch https://github.com/IDC87/Libft_42_school.git

pull:
	@git pull https://github.com/IDC87/Libft_42_school.git
GitCommit:
	@git add .
	@git commit -m "$(shell date)"
#	@git commit -m "$m"
REPOLibft:
	$(LibftREPO)
UploadGit:
	@$(SetStream)
CleanUrl: 
	@$(CleanUrl)
push: GitCommit REPOLibft UploadGit CleanUrl
	@echo
	@echo "UPDATE SUCCESSFUL! REPO CLEAN ALSO SUCCESSFUL!"
	@echo
#FINAL COMMAND should be: make Push m="message" 


#Dictate: 
#	$(SHOUT) executing makefile
loading:
	$(CC) $(CFLAGS) loading_bar.c -o loading && ./loading
#exec:
#	./loading


dir:	
	current_dir = $(shell pwd)

dir2:
	current_dir = $(notdir $(shell pwd))
test:
	@echo "test $<"


XX := $(shell date) 
tt1:
	@echo $(XX)
	$(shell sleep 2)
	@echo $(XX)

XX = $(shell date) // date will be executed every time you use XXx
tt2:
	@echo $(XX)
	$(shell sleep 0.5)
	@echo $(XX)

#(taken from a website. To edit laterzz)
#norminette:
#	@$(ECHO) "$(CYAN)\nChecking norm for libft...$(DEFAULT)"
#	@norminette -R CheckForbiddenSourceHeader $(SRC_DIR) $(SRCB_DIR) $(SRCA_DIR) inc/libft.h







