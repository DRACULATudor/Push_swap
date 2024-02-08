# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/08 13:39:20 by tlupu             #+#    #+#              #
#    Updated: 2024/02/08 15:21:00 by tlupu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
FLAGZ = -Wall -Werror -Wall
FT_PRINTF_DIR = ./printf
SRC = push_swap.c $(FT_PRINTF_DIR)/*.c

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