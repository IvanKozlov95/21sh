# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/08 23:39:38 by ivankozlov        #+#    #+#              #
#    Updated: 2019/09/02 23:33:48 by ikozlov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 21sh

# compiler
CC = gcc

C_ENV ?= PROD
ifeq (${C_ENV}, DEV)
	FLAGS = -g
else ifeq (${C_ENV}, PROD)
	FLAGS = -Wall -Wextra -Werror
endif

# directories
OBJ_DIR = obj/
SRC_DIR = src/
INC_DIR = includes/
LIBFT_DIR = libft/

# files
SRC := $(wildcard $(SRC_DIR)*.c)
SRC += $(wildcard $(SRC_DIR)**/*.c)
SRC += $(wildcard $(SRC_DIR)/**/**/*.c)
OBJ := $(SRC:$(SRC_DIR)%=%)
OBJ := $(patsubst %, $(OBJ_DIR)%, $(OBJ:.c=.o))

# libft
LIBFT = $(LIBFT_DIR)libft.a

# libs
LIB = -L $(LIBFT_DIR) -lft -ltermcap

# includes
INCLUDES = -I $(LIBFT_DIR)$(INC_DIR) -I $(INC_DIR)

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)command_line/
	mkdir -p $(OBJ_DIR)termconfig/
	mkdir -p $(OBJ_DIR)signal/
	mkdir -p $(OBJ_DIR)lexer/
	mkdir -p $(OBJ_DIR)lexer/rules
	mkdir -p $(OBJ_DIR)parser/
	mkdir -p $(OBJ_DIR)executor/
	mkdir -p $(OBJ_DIR)builtins/
	mkdir -p $(OBJ_DIR)keys/

$(NAME): $(OBJ_DIR) $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(LIB) -o $(NAME) $(OBJ)
	@echo "[INFO] $(NAME) executable created"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	@make -C $(LIBFT_DIR) clean
	@if [ -d "./$(OBJ_DIR)" ]; then\
		/bin/rm -rf $(OBJ_DIR);\
		/bin/echo "[INFO] Objects removed.";\
	fi;

fclean: clean
	@if test -e $(NAME); then\
		/bin/rm $(NAME);\
		/bin/echo "[INFO] $(NAME) executable deleted";\
	fi;

re: fclean all

.PHONY: all clean fclean re
