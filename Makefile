CC = cc
FLAGS = -Wall -Wextra -Werror

NAME = push_swap
#BONUS_NAME = push_swap_bonus

MANDATORY_DIR = mandatory/
#BONUS_DIR = bonus/

MANDATORY_HEADER = $(MANDATORY_DIR)push_swap.h
#BONUS_HEADER = $(BONUS_DIR)push_swap_bnus.h

SRC = $(MANDATORY_DIR)push_swap.c \
		$(MANDATORY_DIR)parcing.c \
		$(MANDATORY_DIR)parcing_tools.c

OBJ = $(SRC:.c=.o)

#BONUS_SRC = ...

#BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(MANDATORY_HEADER)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

#bonus: $(BONUS_NAME) ...

%.o: %.c $(MANDATORY_HEADER)
	$(CC) $(FLAGS) -c $< -o $<@

#%_bonus.o: %_bonus.c ....

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re