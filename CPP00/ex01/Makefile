NAME = phonebook

SRCS =	PhoneBook.cpp \

OBJS = $(SRCS:.cpp=.o)

FLAGS = -Wall -Wextra -Werror

CC = clang++

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS)

all: $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all