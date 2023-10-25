SRCS	=	SRCS/GET_NEXT_LINE/get_next_line.c	SRCS/GET_NEXT_LINE/get_next_line_utils.c	\
		cub3d.c	check_map.c exits.c

LIBFT	=	SRCS/LIBFT/libft.a

OBJS	=	$(SRCS:.c=.o)

NAME	=	cub3D

CC		=	gcc #-Wall -Wextra -Werror

RM		=	rm -rf


all:	$(NAME)

$(NAME):	$(OBJS) $(LIBFT)
				$(CC) $(OBJS) $(LIBFT) -o $(NAME)

clean:
			$(RM) $(OBJS)
			make clean -C ./SRCS/libft

$(LIBFT):
			make bonus -C ./SRCS/libft

fclean:
			$(RM) $(OBJS) $(NAME)
			make fclean -C ./SRCS/libft

re:			fclean all

.PHONY:		all clean fclean re