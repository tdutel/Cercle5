# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/26 13:52:16 by tdutel            #+#    #+#              #
#    Updated: 2024/01/31 14:23:46 by tdutel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = AForm
HEADER = headers/Bureaucrat.hpp headers/AForm.hpp	headers/ShrubberyCreationForm.hpp	headers/RobotomyRequestForm.hpp	headers/PresidentialPardonForm.hpp
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
SRC =	main.cpp srcs/Bureaucrat.cpp srcs/AForm.cpp srcs/ShrubberyCreationForm.cpp	srcs/RobotomyRequestForm.cpp	srcs/PresidentialPardonForm.cpp

OBJ = $(SRC:.cpp=.o)


all :
	make $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

%.o : %.cpp $(HEADER) Makefile
	$(CC) $(CFLAGS) -o $@ -c $<

clean :
	rm -f $(OBJ)
	rm -f *_shrubbery

fclean : 
	$(MAKE) clean
	rm -f $(NAME)

re : fclean
	make all

debug :
	$(MAKE) all CFLAGS="-Wall -Werror -Wextra -std=c++98 -g"

rdebug : fclean
	make debug

.PHONY: all clean fclean re debug rdebug
