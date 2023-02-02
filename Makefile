NAME = ft_container

RM = rm -rf 

SRC = main.cpp

OBJC = $(SRC:.cpp=.o)

CC = c++ -Wall -Wextra -Werror  -std=c++98

$(NAME): $(OBJC) vector/vector.hpp
	$(CC)  $(OBJC) -o $(NAME)

%.o:%.cpp vector/vector.hpp
	$(CC) -c $< -o $@
all: $(NAME)
clean :
	$(RM) $(OBJC)
fclean :clean
	$(RM) $(NAME)
re : fclean all
.PHONY : re clean fclean