# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rallouan <rallouan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/06 15:54:41 by rallouan          #+#    #+#              #
#    Updated: 2023/08/14 12:51:13 by rallouan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
BONUS_NAME	=	checker
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g
RM 			=	/bin/rm -f

INCS_DIR	=	./includes
LIBFT_DIR	=	./libft
LIBFT		=	$(LIBFT_DIR)/libft.a

BUILD_DIR	=	build
SRC_MAIN	=	./srcs/push_swap.c
SRCS		=	./srcs/cost_op.c\
					./srcs/list_op.c\
					./srcs/moves_op.c\
					./srcs/parse_utils.c\
					./srcs/parse.c\
					./srcs/position.c\
					./srcs/push.c\
					./srcs/rev_rotate.c\
					./srcs/rotate.c\
					./srcs/sort_utils.c\
					./srcs/sort.c\
					./srcs/stack_op.c\
					./srcs/swap.c

OBJS		=	$(SRCS:%.c=$(BUILD_DIR)/%.o)
BONUS		=	./bonus/checker.c ./bonus/get_next_line/get_next_line.c ./bonus/get_next_line/get_next_line_utils.c
BONUS_OBJ	=	$(BONUS:.c=.o)

all: $(NAME)


$(NAME):$(LIBFT) 
	@$(CC) $(CFLAGS) $(SRCS) $(SRC_MAIN) $(LIBFT) -I $(INCS_DIR) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR) --silent

clean:
	make clean -C $(LIBFT_DIR) --silent
	$(RM) -r $(BUILD_DIR) $(BONUS_OBJ)

fclean: clean
	make fclean -C $(LIBFT_DIR) --silent
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

bonus: $(BONUS_OBJ)
	@$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -I $(INCS_DIR) $(BONUS) -o $(BONUS_NAME)
	
.PHONY: all clean fclean re