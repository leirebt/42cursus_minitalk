NAME1 = server
NAME2 = client
SRC1 = server.c
SRC2 = client.c
SRC_O1	= $(SRC1:.c=.o)
SRC_O2	= $(SRC2:.c=.o)
INCLUDES = ft_printf/libft/libft.h
CC	=	gcc
CFLAGS	=	-Werror -Wextra -Wall
MAKE = make

all	:	$(NAME1) $(NAME2)

$(NAME1)	: $(SRC_O1)
	$(MAKE) -C ft_printf
	cp ft_printf/libftprintf.a .
	$(CC) $(CFLAGS) $(SRC_O1) libftprintf.a -o $(NAME1)
	
$(NAME2)   : $(SRC_O2)
	$(MAKE) -C ft_printf/libft
	cp 	ft_printf/libft/libft.a .
	$(CC) $(CFLAGS) $(SRC_O2) libft.a -o $(NAME2)


%.o	:	%.c ft_printf/libft/libft.h
	$(CC) $(CFLAGS) -c $< -o $@


clean	:
	$(MAKE) -C ft_printf/libft/ clean
	$(MAKE) -C ft_printf/ clean
	rm -f $(SRC_O1) $(SRC_O2)

fclean	: clean
	$(MAKE) -C ft_printf/libft/ fclean
	$(MAKE) -C ft_printf/ fclean
	rm -f $(NAME1) $(NAME2)

re	: fclean all

.PHONY : clean fclean all re
