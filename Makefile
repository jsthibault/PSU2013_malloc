##
## Makefile for Makefile in /home/thibauj/rendu/Git_perso/PSU2013_malloc
## 
## Made by thibau_j
## Login   <thibau_j@epitech.net>
## 
## Started on  Mon Mar 10 18:19:24 2014 thibau_j
## Last update Mon Mar 10 18:19:25 2014 thibau_j
##

SRC=		malloc.c \
		realloc.c \
		calloc.c \
		free.c \
		show_alloc_mem.c

OBJ=		$(SRC:.c=.o)

NAME=		libmy_malloc_$(HOSTTYPE).so

LIB=		libmy_malloc.so

$(NAME):	$(SRC)
		gcc -c -Wall -Wextra -Werror -fpic $(SRC)
		gcc -shared -o $(NAME) $(OBJ)
		ln -fs $(NAME) $(LIB)

all:		$(NAME)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)
		rm -f $(LIB)

re:		fclean all
