CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libtest.a
SRCS = sub1.c sub2.c sub3.c
OBJS = $(SRCS:%.c=%.o)
TEST = $(addsuffix " i'm making library!\n",$(OBJS))
#addprefix testing
all : $(NAME)
	@echo $(TEST)

%.o : %.c
	gcc -Wall -Wextra -Werror -o $@ -c $<

$(OBJS) :
	$(CC) $(CFLAGS) -c $(SRCS)

$(NAME) : $(OBJS)
	ar -rc $(NAME) $(OBJS)


add : add.o libtest.a
	ar -x libtest.a
	ar -rc libadd.a *.o

.PHONY: all clean fclean
clean :
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
	rm -f a.out
	rm -f add.o
	rm -f libadd.a
	rm -f __.SYMDEF\ SORTED 
re : fclean all;