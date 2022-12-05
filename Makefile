SRCS = child_process.c exec.c ft_calloc.c ft_split.c ft_strdup.c ft_substr.c parent_process.c pipex.c utils.c\
		utils_2.c
OBG = $(SRCS:.c=.o)
CFLAGS = -Wall -Werror -Wextra
NAME = pipex

all: $(NAME)

$(NAME): $(OBG)
	$(CC) $(CFLAGS) $(OBG) -o $(NAME)

clean:
	rm -rf $(OBG)

fclean: clean
	rm -rf $(NAME)

re: fclean all