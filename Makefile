NAME = libftprintf.a
SOURCES =ft_printf.c ft_putchar.c ft_putnbrbaze.c ft_putstr.c ft_strlen.c\


OBJECTS = $(SOURCES:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM =rm -f
AR =ar -rcs

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

%.o : %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

# .phony all clean fclean re