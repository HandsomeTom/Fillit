# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 11:11:52 by taho              #+#    #+#              #
#    Updated: 2019/11/28 14:00:22 by ngontjar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAG = -Wall -Wextra -Werror -I libft -L libft -l ft

SRCS =	main.c validate.c validate_piece.c validate_file.c make_piece.c smallest_square.c get_next_line.c make_grid.c ft_piece_add_back.c free2d.c

OBJE = $(subst .c,.o,$(SRCS))

GREEN = \033[0;32m
RED = \033[0;31m
END = \033[0m

all: $(NAME)

$(NAME):
	make -C libft re
	gcc -o $(NAME) $(FLAG) $(SRCS)

clean:
	rm -f $(OBJE)
	@echo "$(NAME): $(RED)All object files were deleted.$(END)"

fclean:	clean
	rm -f $(NAME)
	make -C libft fclean
	@echo "$(NAME): $(RED)$(NAME) was deleted$(END)"

re:	fclean all

tests: re
	@echo "$(NAME): $(RED)Testing error files:"
	./$(NAME) tests/error-0
	./$(NAME) tests/error-27
	./$(NAME) tests/error-blocks
	./$(NAME) tests/error-broken
	./$(NAME) tests/error-char
	./$(NAME) tests/error-length
	./$(NAME) tests/error-newlines
	@echo "$(END)$(NAME): $(GREEN)Testing valid files:"
	./$(NAME) tests/valid-cube
	./$(NAME) tests/valid-T
	./$(NAME) tests/valid-subject
	./$(NAME) tests/valid-hard-L
	@echo "$(END)"

.PHONY: all clean fclean re tests
.PRECIOUS: author
