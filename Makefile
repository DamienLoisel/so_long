# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dloisel <dloisel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/01 19:20:53 by dloisel           #+#    #+#              #
#    Updated: 2024/09/15 00:02:29 by dloisel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GRAY = \033[30m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
RESET = \033[0m

NAME = so_long
NAME_BONUS = so_long_bonus

CC = cc
CFLAGS = -Wall -Werror -Wextra
MLX_FLAGS = -lmlx -lX11 -lXext -lm -lz

SRC = source/arg_verif.c \
	source/error_handling.c \
	source/exit_and_free.c \
	source/game_init.c \
	source/input_handling.c \
	source/main.c \
	source/map_flood_fill.c \
	source/map_init.c \
	source/map_parser.c \
	source/map_render.c \
	source/win_lose.c

SRC_BONUS = source_bonus/arg_verif_bonus.c \
	source_bonus/error_handling_bonus.c \
	source_bonus/exit_and_free_bonus.c \
	source_bonus/game_init_bonus.c \
	source_bonus/input_handling_bonus.c \
	source_bonus/main_bonus.c \
	source_bonus/map_flood_fill_bonus.c \
	source_bonus/map_init_bonus.c \
	source_bonus/map_parser_bonus.c \
	source_bonus/map_render_bonus.c \
	source_bonus/win_lose_bonus.c \
	source_bonus/animation_render.c

OBJ = $(SRC:.c=.o)
OBJS_BONUS = $(SRC_BONUS:.c=.o)

LIBFT = ./include/libft/libft.a
PRINTF = ./include/ft_printf/libftprintf.a
GNL = ./include/get_next_line/get_next_line.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF) $(GNL)
	@$(CC) $(OBJ) $(LIBFT) $(PRINTF) $(GNL) -L/home/dloisel/sgoinfre/minilibx-linux $(CFLAGS) $(MLX_FLAGS) -o $(NAME)
	@echo
	@echo "$(GREEN) ██████╗ █████╗ ██╗      █████╗ ███╗  ██╗ ██████╗ "
	@echo "$(GREEN)██╔════╝██╔══██╗██║     ██╔══██╗████╗ ██║██╔════╝ "
	@echo "$(GREEN)╚█████╗ ██║  ██║██║     ██║  ██║██╔██╗██║██║  ██╗ "
	@echo "$(GREEN) ╚═══██╗██║  ██║██║     ██║  ██║██║╚████║██║  ╚██╗"
	@echo "$(GREEN)██████╔╝╚█████╔╝███████╗╚█████╔╝██║ ╚███║╚██████╔╝"
	@echo "$(GREEN)╚═════╝  ╚════╝ ╚══════╝ ╚════╝ ╚═╝  ╚══╝ ╚═════╝ "
	@echo
	@echo "$(GREEN) █████╗  █████╗ ███╗   ███╗██████╗ ██╗██╗     ███████╗██████╗ ██╗"
	@echo "$(GREEN)██╔══██╗██╔══██╗████╗ ████║██╔══██╗██║██║     ██╔════╝██╔══██╗██║"
	@echo "$(GREEN)██║  ╚═╝██║  ██║██╔████╔██║██████╔╝██║██║     █████╗  ██║  ██║██║"
	@echo "$(GREEN)██║  ██╗██║  ██║██║╚██╔╝██║██╔═══╝ ██║██║     ██╔══╝  ██║  ██║╚═╝"
	@echo "$(GREEN)╚█████╔╝╚█████╔╝██║ ╚═╝ ██║██║     ██║███████╗███████╗██████╔╝██╗"
	@echo "$(GREEN) ╚════╝  ╚════╝ ╚═╝     ╚═╝╚═╝     ╚═╝╚══════╝╚══════╝╚═════╝ ╚═╝"
	@echo

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@echo "$(YELLOW)Making libft..."
	@make bonus --no-print-directory -C ./include/libft

$(PRINTF):
	@echo "$(YELLOW)Making printf..."
	@make --no-print-directory -C ./include/ft_printf

$(GNL):
	@echo "$(YELLOW)Making GNL..."
	@make --no-print-directory -C ./include/get_next_line

clean:
	@echo "$(RED)make clean..."
	@rm -f $(OBJ)
	@rm -f $(OBJS_BONUS)
	@make clean --no-print-directory -C ./include/libft
	@make clean --no-print-directory -C ./include/ft_printf
	@make clean --no-print-directory -C ./include/get_next_line

fclean: clean
	@echo "$(RED)make fclean..."
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@make fclean --no-print-directory -C ./include/libft
	@make fclean --no-print-directory -C ./include/ft_printf
	@make fclean --no-print-directory -C ./include/get_next_line

re: fclean all

bonus : $(OBJS_BONUS) $(LIBFT) $(PRINTF) $(GNL)
	@$(CC) $(OBJS_BONUS) $(LIBFT) $(PRINTF) $(GNL) -L/home/dloisel/sgoinfre/minilibx-linux $(CFLAGS) $(MLX_FLAGS) -o $(NAME_BONUS)
	@echo
	@echo "$(GREEN)██████╗  █████╗ ███╗  ██╗██╗   ██╗ ██████╗"
	@echo "$(GREEN)██╔══██╗██╔══██╗████╗ ██║██║   ██║██╔════╝"
	@echo "$(GREEN)██████╦╝██║  ██║██╔██╗██║██║   ██║╚█████╗ "
	@echo "$(GREEN)██╔══██╗██║  ██║██║╚████║██║   ██║ ╚═══██╗"
	@echo "$(GREEN)██████╦╝╚█████╔╝██║ ╚███║╚██████╔╝██████╔╝"
	@echo "$(GREEN)╚═════╝  ╚════╝ ╚═╝  ╚══╝ ╚═════╝ ╚═════╝ "
	@echo
	@echo "$(GREEN) █████╗  █████╗ ███╗   ███╗██████╗ ██╗██╗     ███████╗██████╗░██╗"
	@echo "$(GREEN)██╔══██╗██╔══██╗████╗ ████║██╔══██╗██║██║     ██╔════╝██╔══██╗██║"
	@echo "$(GREEN)██║  ╚═╝██║  ██║██╔████╔██║██████╔╝██║██║     █████╗  ██║  ██║██║"
	@echo "$(GREEN)██║  ██╗██║  ██║██║╚██╔╝██║██╔═══╝ ██║██║     ██╔══╝  ██║  ██║╚═╝"
	@echo "$(GREEN)╚█████╔╝╚█████╔╝██║ ╚═╝ ██║██║     ██║███████╗███████╗██████╔╝██╗"
	@echo "$(GREEN) ╚════╝  ╚════╝ ╚═╝     ╚═╝╚═╝     ╚═╝╚══════╝╚══════╝╚═════╝ ╚═╝"
	@echo
.PHONY: all clean fclean re

.SILENCE:
