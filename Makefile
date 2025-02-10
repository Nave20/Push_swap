SOURCES =	push_swap.c 		\
			push_swap_algo.c	\
			push_swap_algo2.c	\
			push_swap_cost.c	\
			push_swap_error.c	\
			push_swap_logic.c	\
			push_swap_m1.c		\
			push_swap_m2.c		\
			push_swap_m3.c		\
			push_swap_moves.c	\
			push_swap_stack.c	\
			push_swap_target.c	\
			push_swap_utils.c

OBJS	=	${SOURCES:%.c=${OBJDIR}%.o}

HEADER	=	push_swap.h

LIB = libft/libft.a

NAME	=	push_swap

CC	=	cc

FLAGS	=	-Wall -Wextra -Werror

OBJDIR	= OBJS/

all	:	${NAME}

${OBJDIR}%.o	:	%.c ${HEADER}
	mkdir -p ${OBJDIR}
	${CC} ${FLAGS} -c $< -o $@

${NAME}	:	${OBJS} ${LIB}  Makefile
	cp libft/libft.a libft.a
	${CC} ${FLAGS}  -o $@ ${OBJS} ${LIB}

${LIB} : FORCE
	make bonus -C libft/

FORCE:

clean	:
	rm -rf ${OBJDIR}
	make fclean -C libft/

fclean	:	clean
	rm -f ${NAME}
	make fclean -C libft/

re	:	fclean all

.PHONY	:	all clean fclean re bonus FORCE