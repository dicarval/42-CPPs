
NAME		= HI_THIS_IS_BRAIN
SRC			= main.cpp
OBJS		= $(SRC:%.cpp=%.o)

CC			= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98
RM			= @rm -f

all:		${NAME}
			@echo "Compiling done"

${NAME}:	$(OBJS)
			@$(CC) $(CPPFLAGS) $^ -o $@

%.o: 		%.cpp
			@$(CC) $(CPPFLAGS) -c $< -o $@

clean:
			@${RM} ${OBJS}
			@echo "Objects removed"

fclean:		clean
			@${RM} ${NAME}
			@echo "Executable removed"

re: fclean all

.PHONY: all clean fclean re
