CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = philo_three
SRCS = do.c main.c setting.c time.c clear.c\
		ft_atoi.c ft_itoa.c
OBJS = $(SRCS:%.c=%.o)

all : $(NAME)
%.o : %.c
	$(CC) -c $< -o $@
$(NAME) : $(OBJS)
	$(CC) $(SRCS) -o $(NAME);
	
.PHONY: clean bonus re fclean all

clean :
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re : fclean all
