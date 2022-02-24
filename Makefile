SRCS            = srcs/do_op.c srcs/do_op2.c

OBJS            = ${SRCS:.c=.o}

NAME            = do-op

RM              = rm -f

CFLAGS          = -Wall -Wextra -Werror

all:
		gcc ${SRCS} -o ${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY:	all clean fclean re

