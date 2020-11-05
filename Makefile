# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/23 17:43:48 by clynderl          #+#    #+#              #
#    Updated: 2020/11/05 13:24:40 by clynderl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	= clynderl.filler

SRC		=	free.c \
			filler.c \
			heatmap.c \
			init.c \
			parse.c \
			put_piece.c \

OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g

FT		= ./libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./libft/includes
FT_LNK	= -L ./libft -l ft

SRCDIR	= ./srcs/
INCDIR	= ./includes/
OBJDIR	= ./obj/
H_FILE 	= $(addprefix $(INCDIR), filler.h)

all: obj $(FT_LIB) $(NAME)

obj:
	@mkdir -p $(OBJDIR)
	@echo "\033[32m✅$(NAME): $(OBJECTS_DIR)directory was created✅\033[0m"

$(OBJDIR)%.o:$(SRCDIR)%.c $(H_FILE)
	@$(CC) $(CFLAGS) $(FT_INC) -I $(INCDIR) -o $@ -c $<
	@echo "\033[32m🍏\c \033[0m"

$(FT_LIB):
	@make -C $(FT)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(FT_LNK) -lm -o $(NAME)
	@echo "\033[32m\n✅$(NAME): was created✅\033[0m"

clean:
	@rm -rf $(OBJDIR)
	@make -C $(FT) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(FT) fclean

re: fclean all
