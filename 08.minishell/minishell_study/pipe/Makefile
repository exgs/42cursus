NAME			=	result
LIBFT			=	libft.a
LIBFT_DIR		=	../../libft

SRCS			=	main.c\
					../../gnl/get_next_line.c\
					../../gnl/get_next_line_utils.c

OBJS			=	$(SRCS:.c=.o)

CC				=	gcc

CFLAG			=	-g

RM				=	rm -f

all				:	$(NAME)

fclean			:	clean
					$(RM) $(NAME)

clean			:
					$(RM) $(OBJS) *.gch a.out

re				:	fclean all

$(NAME)			:	$(OBJS)
					$(CC) $(CFLAG) -o $(NAME) -L $(LIBFT_DIR) $(OBJS) -lft

.PHONY			:	all clean fclean re
