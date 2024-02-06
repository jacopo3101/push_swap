GCC		= gcc

CFLAGS	= -g -Wall -Wextra -Werror

MAIN	= push_swap.c ft_sort_num.c ft_radixsort.c

FILES	= ft_reverse_rotate.c ft_swap.c ft_rotate.c utils.c ft_free.c ft_push.c

BONUS	= checker.c

NAME	= push_swap

PRINTF	= ft_printf

LIBRARY = ft_printf/libftprintf.a

RM	= rm -f

OBJECTS=$(FILES:.c=.o)

MAIN_OBJ=$(MAIN:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJECTS)
			@make -C $(PRINTF)
			$(GCC) $(CFLAGS) $(MAIN) $(OBJECTS) $(LIBRARY) -o $(NAME)

bonus:		$(OBJECTS) $(BONUS)
			$(GCC) $(CFLAGS) $(OBJECTS) $(BONUS) $(LIBRARY) -o checker

clean:
			@$(RM) $(OBJECTS) $(MAIN_OBJ)
			@make clean -C $(PRINTF)
			
fclean:	clean
			@make fclean -C $(PRINTF)
			@$(RM) $(NAME)
			@$(RM) $(LIBRARY)
			@$(RM) checker
			
re:		fclean all

bonus: all

.PHONY:		all clean fclean re
