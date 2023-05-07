# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdaly <jdaly@student.42bangkok.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/08 00:38:06 by jdaly             #+#    #+#              #
#    Updated: 2023/05/08 01:01:38 by jdaly            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

S_NAME = server
C_NAME = client

S_SOURCES = server.c
C_SOURCES = client.c

S_OBJECTS = $(S_SOURCES:.c=.o)
C_OBJECTS = $(C_SOURCES:.c=.o)

# S_BONUS_SOURCES =
# C_BONUS_SOURCES =
# BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(S_NAME) $(C_NAME)

$(S_NAME): $(S_OBJECTS)
	$(CC) $(CFLAGS) -o $(S_NAME) $(S_OBJECTS)

$(C_NAME): $(C_OBJECTS)
	$(CC) $(CFLAGS) -o $(C_NAME) $(C_OBJECTS)

# bonus: $(BONUS_OBJECTS)
#	$(AR) $(NAME) $(BONUS_OBJECTS)

clean:
	rm -rf $(S_OBJECTS) $(C_OBJECTS)

fclean: clean
	rm -rf $(S_NAME) $(C_NAME)

re:	fclean all

.PHONY: all clean fclean re
