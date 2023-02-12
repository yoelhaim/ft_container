NAME = ft_container

RM = rm -rf 

SRC = main.cpp
HEADER =  vector/vector.hpp iterator/iterator.hpp iterator/reverseIterator.hpp

OBJC = $(SRC:.cpp=.o)

CC = c++ -Wall -Wextra -Werror  -std=c++98 -g

$(NAME): $(OBJC) ${HEADER}
	$(CC)  $(OBJC) -o $(NAME)

%.o:%.cpp ${HEADER}
	$(CC) -c $< -o $@
all: $(NAME)
clean :
	$(RM) $(OBJC)
fclean :clean
	$(RM) $(NAME)
re : fclean all
.PHONY : re clean fclean