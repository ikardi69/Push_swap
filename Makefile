CC = cc
FLAGS = -Wall -Wextra -Werror

NAME = push_swap
BONUS_NAME = push_swap_bonus

MANDATORY_DIR = mandatory/
BONUS_DIR = bonus/

MANDATORY_HEADER = $(MANDATORY_DIR)push_swap.h
BONUS_HEADER = $(BONUS_DIR)push_swap_bnus.h

SRC = $(MANDATORY_DIR)push_swap.c \
		$(MANDATORY_DIR)parcing.c \
		$(MANDATORY_DIR)parcing_tools.c \
		$(MANDATORY_DIR)parcing_utils1.c \
		$(MANDATORY_DIR)ft_split.c \
		$(MANDATORY_DIR)parsing_util2.c \
		$(MANDATORY_DIR)low_sort.c \
		$(MANDATORY_DIR)moves.c \
		$(MANDATORY_DIR)moves_2.c \
		$(MANDATORY_DIR)four_or_five.c \
		$(MANDATORY_DIR)big_one.c

OBJ = $(SRC:.c=.o)

BONUS_SRC = $(BONUS_DIR)parcing_tools_bonus.c \
			$(BONUS_DIR)parcing_utils1_bonus.c \
			$(BONUS_DIR)parsing_util2bonus.c \
			$(BONUS_DIR)push_swap_bonus.c \

BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(MANDATORY_HEADER)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJ) $(BONUS_HEADER)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.c $(MANDATORY_HEADER)
	$(CC) $(FLAGS) -c $< -o $@

%_bonus.o: %_bonus.c $(BONUS_HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re