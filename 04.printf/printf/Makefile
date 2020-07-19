NAME = libftprintf.a
CFLAG = -Wall -Wextra -Werror

SRCS_PRINTF = s_flag_test.c ft_printf.c ft_printf_sub.c csdiu_specifier.c pxX%_specifier.c pxX%_specifier_sub.c c_specifier_flag.c specifier_flag_common.c s_specifier_flag.c
OBJS_PRINTF = $(SRCS_PRINTF:.c=.o)
WHERE_OBJS_PRINTF = $(addprefix ./printf_src/, $(OBJS_PRINTF))

SRCS_LIBFT_PLUS = ft_utoa.c
OBJS_LIBFT_PLUS = $(SRCS_LIBFT_PLUS:.c=.o)
WHERE_OBJS_LIBFT_PLUS = $(addprefix ./libft_plus/, $(OBJS_LIBFT_PLUS))

# $(subst .c, .o, $(SRCS_PRINFT)) == $(SRCS_LIBFT_PLUS:.c=.o)

WHERE_LIBFT = ./libft/libft.a

all : $(NAME)

$(NAME) : ./libft_plus/libft_plus.a $(WHERE_OBJS_PRINTF)
#	ar -x ./libft_plus/libft_plus.a
	ar rcs $(NAME) ./libft_plus/*.o ./libft/*.o $(WHERE_OBJS_PRINTF)

./libft_plus/libft_plus.a : ./libft/libft.a $(WHERE_OBJS_LIBFT_PLUS)
#	ar -x ./libft/libft.a
	ar rcs ./libft_plus/libft_plus.a ./libft/*.o $(WHERE_OBJS_LIBFT_PLUS)

./libft/libft.a :
	$(MAKE) -C ./libft all

%.o : %.c
	gcc  -o $@ -c $<
#	gcc $(CFLAG) -o $@ -c $<

#./libft_plus/%.o : ./libft_plus/%.c
#	gcc $(CFLAG) -o $@ -c $<

#./libft_plus/ft_utoa.o : ./libft_plus/ft_utoa.c
#	gcc $(CLFAG) -o $@ -c $< -I./libft_plus

#./printf_src/%.o : ./printf_src/%.c
#	gcc $(CFLAG) -o $@ -c $<

clean :
	rm -f ./libft_plus/*.o
	rm -f ./libft/*.o
	rm -f ./printf_src/*.o
fclean : clean
	rm -f ./libft/libft.a
	rm -f ./libft_plus/libft_plus.a
	rm -f ./libftprintf.a
re : fclean all

.PHONY : all fclean clean re
