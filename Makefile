CFLAGS:= -Wall -Wextra -Werror
SRCS:=	fillit.c\
		count_octothorpe.c\
		create_matrix.c\
		cut_tetramino.c\
		move_tetramino_to_zero.c\
		letter_replacement.c\
		algoritm.c
OBJ:= $(SRCS:c=o)
PROGRAM = fillit

.PHONY: all
all: $(PROGRAM)

$(PROGRAM): ${OBJ}
	make -C libft/
	${CC} $(CFLAGS) ${OBJ} -o $@ -L libft/ -lft

%.o: %.c
	${CC} ${CFLAGS} -c $<

clean:
	rm -f $(OBJ) && make clean -C libft/

fclean: clean
	rm -f $(PROGRAM) && make fclean -C libft/

re: fclean all
