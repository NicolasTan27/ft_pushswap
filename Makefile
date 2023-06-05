# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 14:33:36 by ntan              #+#    #+#              #
#    Updated: 2022/03/08 14:28:58 by ntan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	main.c \
					src/init_tabs.c \
					src/check_arg.c \
					src/ops/swap.c \
					src/ops/push.c \
					src/ops/rotate.c \
					src/ops/rrotate.c \
					src/algo/sort_3.c \
					src/algo/algonul.c \
					src/algo/lis.c \
					src/algo/best_in_b.c \
					src/algo/utils.c \
					src/algo/mix.c
OBJS			= 	$(SRCS:.c=.o)

CC				= 	gcc
RM				= 	rm -f
CFLAGS			= 	-Wall -Wextra -Werror -fsanitize=address
NAME			= 	push_swap	

all:			libft_make $(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) -I. $(SRCS) -o $(NAME) -L./libft -lft 

libft_make:
				make -C libft

clean:
				$(RM) $(OBJS)
				make clean -C libft

fclean:			
				make fclean -C libft
				$(RM) $(OBJS)
				$(RM) $(NAME)

re:				fclean all
