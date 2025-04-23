CC = cc
FLAGS = -Wall -Wextra -Werror

NAME = push_swap
BONUS_NAME = checker

MANDATORY_DIR = mandatory/
BONUS_DIR = bonus/

MANDATORY_HEADER = $(MANDATORY_DIR)push_swap.h
BONUS_HEADER = $(BONUS_DIR)push_swap_bonus.h

SRC = $(MANDATORY_DIR)push_swap.c \
		$(MANDATORY_DIR)parsing.c \
		$(MANDATORY_DIR)parsing_utils.c \
		$(MANDATORY_DIR)parsing_utils1.c \
		$(MANDATORY_DIR)ft_split.c \
		$(MANDATORY_DIR)parsing_util2.c \
		$(MANDATORY_DIR)low_sort.c \
		$(MANDATORY_DIR)moves.c \
		$(MANDATORY_DIR)moves_2.c \
		$(MANDATORY_DIR)four_or_five.c \
		$(MANDATORY_DIR)big_one.c \
		$(MANDATORY_DIR)moves_3.c \
		$(MANDATORY_DIR)parcing_utils3.c

OBJ = $(SRC:.c=.o)

BONUS_SRC = $(BONUS_DIR)parsing_tools_bonus.c \
			$(BONUS_DIR)parsing_utils1_bonus.c \
			$(BONUS_DIR)parsing_util2_bonus.c \
			$(BONUS_DIR)push_swap_bonus.c \
			$(BONUS_DIR)ft_split_bonus.c \
			$(BONUS_DIR)parsing_bonus.c \
			$(BONUS_DIR)get_next_line_bonus.c \
			$(BONUS_DIR)get_next_line_utils_bonus.c \
			$(BONUS_DIR)apply_operations_bonus.c \
			$(BONUS_DIR)moves1.c \
			$(BONUS_DIR)moves2.c \
			$(BONUS_DIR)moves3.c \
			$(BONUS_DIR)parsing_util3_bonus.c

BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(MANDATORY_HEADER)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJ) $(BONUS_HEADER)
	$(CC) $(FLAGS) $(BONUS_OBJ) -o $(BONUS_NAME)

%.o: %.c $(MANDATORY_HEADER)
	$(CC) $(FLAGS) -c $< -o $@

%_bonus.o: %_bonus.c $(BONUS_HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re : fclean all

.PHONY: all clean fclean re