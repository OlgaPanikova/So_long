NAME = libgnl.a
CC = cc
AR = ar
FLAGS = -Wall -Wextra -Werror

HDRS = get_next_line.h
SRCS = get_next_line_utils.c get_next_line.c

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) rcs $(NAME) $(OBJ)


%.o : %.c $(HDRS)
	$(CC) $(FLAGS) -I $(HDRS) -c $< -o $@

clean :
	rm -f $(OBJ) $(OBJB)

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re