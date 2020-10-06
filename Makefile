# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oem <oem@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/16 23:38:13 by oem               #+#    #+#              #
#    Updated: 2020/10/06 12:24:50 by oem              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the program
PROGRAM := fillit

# Name of the library.
LIBFT	:= Libft/libft.a

# Name of the directories.
INC_DIR := includes
SRC_DIR := srcs
OBJ_DIR := objs

# Path of the directories.
INCLS	:= $(INC_DIR)
SRCS	:= $(wildcard $(SRC_DIR)/*.c)
OBJS	:= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Define all the compiling flags.
CC		:= gcc
CFLAGS	:= -Wall -Werror -Wextra

# Makes sure that gnu make will still run even if files called
# clean / fclean / all and re already exist in the directory
.PHONY: all clean fclean re

# Compile and create everything.
all:	obj
		$(MAKE) $(PROGRAM)

# Creates the object files' directory.
obj:
		mkdir $(OBJ_DIR)

# This won't run if the object files don't exist or are not modified.
$(PROGRAM): $(LIBFT) ${OBJS}
	${CC} $(CFLAGS) ${OBJS} -o $@ -L Libft/ -lft

# Compiling the library
$(LIBFT):
	make -C Libft/

# This won't run if the source files don't exist or are not modified.
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		$(CC) $(CFLAGS) -g -MD -c $< -o $@ -I./$(INCLS)
include $(wildcard *.d)

# Rule to remove all the object files and directory.
clean:
	rm -rf $(OBJS) $(OBJ_DIR) && make clean -C Libft/

# Rule to remove everything that has been created by the makefile.
fclean: clean
	rm -rf $(PROGRAM) && make fclean -C Libft/

# Rule to re-make everything.
re: fclean all
