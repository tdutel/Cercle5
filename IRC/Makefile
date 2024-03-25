# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/26 13:52:16 by tdutel            #+#    #+#              #
#    Updated: 2024/03/25 15:38:59 by tdutel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ircserv
HEADER = incs/Irc.hpp	incs/Server.hpp	incs/Client.hpp
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -g3
SRC =	main.cpp	srcs/Server.cpp	srcs/Client.cpp

OBJ = $(SRC:.cpp=.o)

all :
	make $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

%.o : %.cpp $(HEADER) Makefile
	$(CC) $(CFLAGS) -o $@ -c $<

clean :
	rm -f $(OBJ)

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
