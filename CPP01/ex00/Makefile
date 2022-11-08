NAME			=	zombiegang

SRCS			=	Zombie.cpp \
					newZombie.cpp \
					randomChump.cpp \
					main.cpp

OBJS			=	${SRCS:.cpp=.o}

HEAD			=	-I include

CC				=	c++

CFLAGS			=	-Wall -Werror -Wextra -std=c++98

.c.o			:
					${CC} ${CFLAGS} ${HEAD} -c $< -o ${<:.cpp=.o}

$(NAME)			:	${OBJS}
					@${CC} ${CFLAGS} ${OBJS} -lpthread -o ${NAME}

all				:	${NAME}

clean			:
					@rm -rf ${OBJS}

fclean			:	clean
					@rm -rf ${NAME}

re				:	fclean all

.PHONY			:	all clean fclean re