NAME = libcub3d.a

CFLAG = -Wall -Wextra -Werror
CMLX = -Iopengl -lmlx -L./opengl
CLIBFT_PLUS = -Ilibft_plus -lft_plus -L./libft_plus -Ilibft_plus/gnl
CCUB3D = -I. -L. -lcub3d
CFRAMEWORK = -framework OpenGL -framework Appkit


SRCS = cub_utility.c save_bmp.c error.c\
		./mlx_hook/character_move.c ./mlx_hook/character_rotate.c ./mlx_hook/character_keypress.c \
		./mlx_loop_hook/walls_raycasting.c ./mlx_loop_hook/sprites_raycasting.c ./mlx_loop_hook/raycasting.c ./mlx_loop_hook/sprites_arrange.c \
		./non_mlx/getdata_from_file.c ./non_mlx/getdata_from_file_sub.c ./non_mlx/getdata_num.c ./non_mlx/getdata_num_sub.c ./non_mlx/getdata_nswes.c ./non_mlx/getdata_map.c ./non_mlx/getdata_map_sub.c ./non_mlx/map_valid.c ./non_mlx/getimg_xpm.c ./non_mlx/error_doublekey.c
OBJS = $(SRCS:.c=.o)

SRCS_BONUS = ./non_mlx/map_valid_bonus.c cub_utility_bonus.c cub_utility_sub_bonus.c \
		cub_utility.c save_bmp.c error.c \
		./mlx_hook/character_move.c ./mlx_hook/character_rotate.c ./mlx_hook/character_keypress.c \
		./mlx_loop_hook/walls_raycasting.c ./mlx_loop_hook/sprites_raycasting.c ./mlx_loop_hook/raycasting.c ./mlx_loop_hook/sprites_arrange.c \
		./non_mlx/getdata_from_file.c ./non_mlx/getdata_from_file_sub.c ./non_mlx/getdata_num.c ./non_mlx/getdata_num_sub.c ./non_mlx/getdata_nswes.c ./non_mlx/getdata_map.c ./non_mlx/getdata_map_sub.c ./non_mlx/getimg_xpm.c ./non_mlx/error_doublekey.c
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all : $(NAME) ./libft_plus/libft_plus.a ./opengl/libmlx.a
	gcc $(CFLAG) $(CMLX) $(CLIBFT_PLUS) $(CFRAMEWORK) $(CCUB3D) main.c -o cub3D

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

NAME_BONUS = libcub3d_bonus.a
CCUB3D_BONUS = -I. -L. -lcub3d_bonus
bonus : $(NAME_BONUS) ./libft_plus/libft_plus.a ./opengl/libmlx.a
	gcc $(CFLAG) $(CMLX) $(CLIBFT_PLUS) $(CFRAMEWORK) $(CCUB3D_BONUS) main.c -o cub3D

$(NAME_BONUS) : $(OBJS_BONUS)
	ar rc $(NAME_BONUS) $(OBJS_BONUS)
	ranlib $(NAME_BONUS)

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
	rm -f ./cub3D.bmp
	rm -f ./a.out
	rm -f ./libcub3d.a
	rm -f ./libcub3d_bonus.a
re : fclean all

.PHONY : all fclean clean re gcc gg
