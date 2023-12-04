SRCS	=	SRCS/GET_NEXT_LINE/get_next_line.c	SRCS/GET_NEXT_LINE/get_next_line_utils.c	\
		cub3d.c	check_map.c exits.c get_info.c utils_info.c ft_split_special.c utils_check.c \


LIBFT	=	SRCS/LIBFT/libft.a

OBJS	=	$(SRCS:.c=.o)

NAME	=	cub3D

CC		=	gcc #-Wall -Wextra -Werror

RM		=	rm -rf


all:	$(NAME)

$(NAME):	$(OBJS) $(LIBFT)
				$(CC) $(OBJS) $(MLX) $(LIBFT) -o $(NAME)

clean:
			$(RM) $(OBJS)
			make clean -C ./SRCS/libft

$(LIBFT):
			make bonus -C ./SRCS/libft

$(MLX):
			@make -C ./mlx

fclean:
			$(RM) $(OBJS) $(NAME)
			make fclean -C ./SRCS/libft

re:			fclean all

.PHONY:		all clean fclean re