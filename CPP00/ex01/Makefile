NAME		= "My_Awesome_PhoneBook"
SRCS		= main.cpp PhoneBook.cpp Contact.cpp searchPhoneBook.cpp
OBJS		= $(SRCS:%.cpp=%.o)

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
