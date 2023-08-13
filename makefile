# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rallouan <rallouan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/06 15:54:41 by rallouan          #+#    #+#              #
#    Updated: 2023/08/07 20:43:55 by rallouan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM 			= /bin/rm -f

INCS_DIR	= ./includes
LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

BUILD_DIR	= build
SRC_DIR		= ./srcs
SRCS		= 	cost_op.c\
					list_op.c\
					moves_op.c\
					parse_utils.c\
					parse.c\
					position.c\
					push_swap.c\
					push.c\
					rev_rotate.c\
					rotate.c\
					sort_utils.c\
					sort.c\
					stack_op.c\
					swap.c

OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)

all: $(NAME)

$(NAME):$(LIBFT) $(OBJS)
	@ar rc $(NAME) $(OBJS)

$(OBJS): $(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I $(INCS_DIR) -I $(LIBFT_DIR) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) -r $(BUILD_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all
	
.PHONY: all clean fclean re