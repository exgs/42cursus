NAME = libftprintf.a
file = up.c down.c
file_object = $(file:%.c=%.o)

test_file = sub1.c sub2.c sub3.c
test_file_object = $(test_file:%.c=%.o)

all : $(NAME)

%.o : %.c
	gcc -Wall -Wextra -Werror -c $< -o $@


$(NAME) : ./src/libtest.a $(file_object)
	ar rcs $(NAME) ./src/*.o $(addprefix ./, $(file_object))
#	ar rcs $(NAME) $(addprefix ./src/, $(test_file_object)) $(addprefix ./, $(file_object))
#	@echo $(addprefix ./src/, libtest.a)

./src/libtest.a : test_make

test_make :
	$(MAKE) -C ./src add

test_clean :
	$(MAKE) -C ./src fclean

all_clean : test_clean
	rm -f up.o down.o libftprintf.a