SRCS = child_process.c exec.c ft_calloc.c ft_split.c ft_strdup.c ft_substr.c parent_process.c pipex.c utils.c \
		utils_2.c utils_end.c \
		get_line.c get_line_utils.c
SRCS_BONUS = child_process_bonus.c exec.c ft_calloc.c ft_split.c ft_strdup.c ft_substr.c parent_process.c pipex_bonus.c utils.c \
		utils_2.c utils_end.c \
		get_line.c get_line_utils.c
OBG = $(SRCS:.c=.o)
OBG_BONUS = $(SRCS_BONUS:.c=.o)
CFLAGS = -Wall -Werror -Wextra
NAME = pipex
BONUS = pipex_bonus

all: $(NAME)

bonus: $(BONUS)

$(BONUS): $(OBG_BONUS)
	$(CC) $(CFLAGS) $(OBG_BONUS) -o $(BONUS)

$(NAME): $(OBG)
	$(CC) $(CFLAGS) $(OBG) -o $(NAME)

clean:
	rm -rf $(OBG) $(OBG_BONUS)

fclean: clean
	rm -rf $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus