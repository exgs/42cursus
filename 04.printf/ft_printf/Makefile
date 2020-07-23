NAME = libftprintf.a
CFLAG = -Wall -Wextra -Werror
COPTION = -I./printf_src -L. -lftprintf

SRCS_PRINTF = ft_printf.c ft_printf_sub.c csdiu_specifier.c pxX%_specifier.c decimal_to_hexa_conversion.c c_specifier_flag.c \
				specifier_flag_common.c s_specifier_flag.c p_specifier_flag.c x_specifier_flag.c x_specifier_flag_sub.c \
					percent_specifier_flag.c d_specifier_flag.c d_specifier_flag_sub.c
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
	@ar rcs $(NAME) ./libft_plus/*.o ./libft/*.o $(WHERE_OBJS_PRINTF)

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

gg :
	gcc $(CFLAG) $(COPTION) test.c
gcc:
	gcc $(COPTION) test.c

clean :
	rm -f ./libft_plus/*.o
	rm -f ./libft/*.o
	rm -f ./printf_src/*.o
fclean : clean
	rm -f ./libft/libft.a
	rm -f ./libft_plus/libft_plus.a
	rm -f ./libftprintf.a
	rm -f ./a.out
re : fclean all

.PHONY : all fclean clean re gcc gg
