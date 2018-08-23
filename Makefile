NAME = ft_ssl

SRCS = 	srcs/main.c							\
		srcs/md5/md5.c						\
		srcs/md5/md5_core.c					\
		srcs/md5/md5_process.c				\
		srcs/sha256/sha256.c				\
		srcs/sha256/sha256_core.c			\
		srcs/sha256/sha256_process.c		\
		srcs/sha512/sha512.c				\
		srcs/sha512/sha512_core.c			\
		srcs/sha512/sha512_process.c		\
		srcs/sha512/sha512_constants.c		\
		srcs/mdig_engine/mdig_engine.c		\
		srcs/mdig_engine/mdig_flags.c		\
		srcs/mdig_engine/mdig_init.c		\
		srcs/base64/base64.c				\
		srcs/base64/base64_init.c			\
		srcs/base64/base64_print.c			\
		srcs/input.c						\
		srcs/ssl.c							\


OBJS = $(SRCS:.c=.o)
INCLUDES =-I lib/libft/includes -I includes
LIBS = -L lib/libft/ -lft
FLAGS = -Wall -Wextra -Werror

$(NAME):	$(OBJS)
	@make -C lib/libft/ re
	@gcc -o $(NAME) $(OBJS) $(LIBS)
	@echo "Complitation ok"

$(OBJS): %.o: %.c
	@gcc $(FLAGS) $(INCLUDES) -c $< -o $@

all:		$(NAME)

clean:
	rm -f	$(OBJS)

fclean: clean
	rm -f	$(NAME)
	@make -C lib/libft/ fclean

norme42:
	norminette lib
	norm includes
	norme srcs
re: fclean all

.PHONY: all clean fclean re norme
