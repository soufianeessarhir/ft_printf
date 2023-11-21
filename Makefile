NAME = libftprintf.a
SOURCES = 

    

OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM =rm -f
AR =ar -rcs

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

%.o : %.c libft.h
	$(CC) $(CFLAGS) -c $< 
clean:
	$(RM) $(OBJECTS) $(B_OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.phony all clean fclean re