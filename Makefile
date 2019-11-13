# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 11:11:52 by taho              #+#    #+#              #
#    Updated: 2019/11/12 20:36:17 by ngontjar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAG = -Wall -Wextra -Werror -I. -I libft -L libft -l ft
SRCS =	*.c
OBJE = $(subst .c,.o,$(SRCS))

GREEN = \033[0;32m
RED = \033[0;31m
END = \033[0m

all: $(NAME)

$(NAME):
	gcc $(FLAG) $(SRCS)
	#ar rc $(NAME) $(OBJE)
	@echo "$(NAME): $(GREEN)EI TUU VITTU TOIMII :D::D:DDD$(END)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(END)"

clean:
	rm -f $(OBJE)
	@echo "$(NAME): $(RED)All object files were deleted.$(END)"

fclean:	clean
	rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(END)"

re:	fclean all

.PHONY: all clean fclean re
.PRECIOUS: author
