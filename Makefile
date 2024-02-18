NAME = push_swap
FLAGZ = -Wall -Werror -Wall
FT_PRINTF_DIR = ./printf
SRC = push_swap.c $(FT_PRINTF_DIR)/*.c \
	  checks.c add_stackA.c \

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