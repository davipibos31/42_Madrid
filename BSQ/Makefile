SRC = cuadros.c

OBJS = $(SRC) :.c=.o

GCC = gcc

NAME = BSQ

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)
	
$(NAME): $(SRC)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) 
clean:
	rm -f ${NAME}
