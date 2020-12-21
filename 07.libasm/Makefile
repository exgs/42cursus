NAME = libasm.a
SRCS = ft_strlen.s ft_read.s ft_write.s ft_strcmp.s ft_strcpy.s ft_strdup.s
OBJS = $(SRCS:%.s=%.o)

all: $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
	
%.o : %.s
	nasm -fmacho64 $<
clean:
	rm -rf *.o
	rm -rf a.out
fclean: clean
	rm -rf libasm.a
re : fclean all
