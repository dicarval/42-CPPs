
NAME		= Its_a_ClapTrap
SRC			= main.cpp ClapTrap.cpp actions.cpp
OBJ_DIR		= objects
OBJS		= $(addprefix $(OBJ_DIR)/, $(SRC:%.cpp=%.o))

CC			= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98
RM			= @rm -rf

all:		${NAME}
			@echo "Compiling done"

${NAME}:	$(OBJS)
			@$(CC) $(CPPFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: %.cpp
			@mkdir -p $(OBJ_DIR)
			@$(CC) $(CPPFLAGS) -c $< -o $@

clean:
			@${RM} $(OBJ_DIR)
			@echo "Objects removed"

fclean:		clean
			@${RM} ${NAME}
			@echo "Executable removed"

re: fclean all

.PHONY: all clean fclean re
