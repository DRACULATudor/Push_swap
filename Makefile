# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 16:15:09 by tlupu             #+#    #+#              #
#    Updated: 2024/03/05 16:28:28 by tlupu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
FLAGZ = -Wall -Werror -Wall
FT_PRINTF_DIR = ./printf
SRC = push_swap.c $(FT_PRINTF_DIR)/*.c \
	  checks.c add_stackA.c split.c\
	  operationsA.c operationB.c free.c\
	  lindex.c sort_operations3num.c\
	  utils.c init_nodes.c\
	  sorting.c sort2.c\

all:	$(NAME) 

$(NAME): 
	cc $(FLAGZ) -c $(SRC) -I $(FT_PRINTF_DIR)
	ar rc $(NAME).a *.o
	cc $(FLAGZ) -o $(NAME) $(NAME).a -L$(FT_PRINTF_DIR)
	rm -f *.o
	rm -f *.a
	
clean:
	rm -f *.o
	rm -f $(NAME)

fclean:	clean
	rm -f $(NAME).a
    
re:	fclean	all

