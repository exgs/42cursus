NAME = libcub3d.a
CFLAG = -Wall -Wextra -Werror
CMLX = -Iopengl -lmlx -L./opengl
CLIBFT_PLUS = -Ilibft_plus -lft_plus -L./libft_plus -Ilibft_plus/gnl
CCUB3D = -I. -L. -lcub3d
CFRAMEWORK = -framework OpenGL -framework Appkit


SRCS = config.c cub_default.c
OBJS = $(SRCS:.c=.o)

all : $(NAME) ./libft_plus/libft_plus.a ./opengl/libmlx.a

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

./libft_plus/libft_plus.a :
	$(MAKE) -C ./libft_plus bonus

./opengl/libmlx.a :
	$(MAKE) -C ./opengl all

%.o : %.c
	gcc -o $@ -c $<

gg :
	gcc $(CFLAG) $(CMLX) $(CLIBFT_PLUS) $(CFRAMEWORK) $(CCUB3D) main.c
gcc:
	gcc $(CMLX) $(CLIBFT_PLUS) $(CFRAMEWORK) $(CCUB3D) main.c

f_gcc :
	gcc -fsanitize=address -g3 $(CMLX) $(CLIBFT_PLUS) $(CFRAMEWORK) $(CCUB3D) main.c

clean :
	$(MAKE) -C ./libft_plus clean
	rm -f ./opengl/*.o
	rm -f ./*.o
fclean : clean
	rm -f ./libft_plus/libft_plus.a
	rm -f libft_plus.a
	rm -f ./opengl/libmlx.a
	rm -f ./a.out
	rm -f ./libcub3d.a
re : fclean all

.PHONY : all fclean clean re gcc gg
