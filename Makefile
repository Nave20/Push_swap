SOURCES =	\

OBJS	=	${SOURCES:.c=.o}

HEADER	=	push_swap.h

LIB = libft/libft.a

NAME	=	libft.a

CC	=	cc

AR	=	ar -rc

FLAGS	=	-Wall -Wextra -Werror

all	:	${NAME}

%.o	:	%.c ${HEADER}
	${CC} ${FLAGS} -c $< -o $@

${NAME}	:	${LIB} ${OBJS} Makefile
	cp libft/libft.a libft.a

${LIB} : FORCE
	make bonus -C libft/

FORCE:

clean	:
	rm -f ${OBJS}
	make fclean -C libft/

fclean	:	clean
	rm -f ${NAME}
	make fclean -C libft/

re	:	fclean all

.PHONY	:	all clean fclean re bonus FORCE