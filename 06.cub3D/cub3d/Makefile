NAME = libcub3d.a
CFLAG = -Wall -Wextra -Werror
CMLX = -Iopengl -lmlx -L./opengl
CLIBFT_PLUS = -Ilibft_plus -lft_plus -L./libft_plus -Ilibft_plus/gnl
CCUB3D = -I. -L. -lcub3d
CFRAMEWORK = -framework OpenGL -framework Appkit


SRCS = cub_default.c \
		./mlx_hook/character_move.c ./mlx_hook/character_rotate.c ./mlx_hook/character_keypress.c \
		./mlx_loop_hook/walls_raycasting.c ./mlx_loop_hook/sprites_raycasting.c ./mlx_loop_hook/raycasting.c ./mlx_loop_hook/sprites_arrange.c \
		./non_mlx/getdata_from_file.c ./non_mlx/getdata_from_file_sub.c ./non_mlx/getdata_num.c ./non_mlx/getdata_num_sub.c ./non_mlx/getdata_nswes.c ./non_mlx/getdata_map.c 
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
	rm -f ./mlx_hook/*.o
	rm -f ./mlx_loop_hook/*.o
	rm -f ./non_mlx/*.o
fclean : clean
	rm -f ./libft_plus/libft_plus.a
	rm -f libft_plus.a
	rm -f ./opengl/libmlx.a
	rm -f ./cub3D
	rm -f ./a.out
	rm -f ./libcub3d.a
re : fclean all

.PHONY : all fclean clean re gcc gg
