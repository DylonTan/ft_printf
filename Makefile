NAME = libftprintf.a

FILES = ft_printf.c ft_parser.c ft_out_char.c ft_out_str.c ft_out_int.c ft_out_hex.c ft_out_align.c ft_utoa.c ft_itoa_base.c
SRCS = $(addprefix srcs/, $(FILES))
OBJS = $(FILES:.c=.o)

CC = gcc
FLAGS = -Wall -Wextra -Werror

INCS = includes
LIBFT = libft
OPTIONS = -I$(INCS)

all: $(NAME)

$(NAME):
	@cd libft; make re; cd ..;
	$(CC) -c $(FLAGS) $(OPTIONS) $(SRCS)
	ar rcs $(NAME) $(OBJS) $(LIBFT)/*.o

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

bonus: $(NAME)

.PHONY: all clean fclean re bonus
