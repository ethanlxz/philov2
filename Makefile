# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etlaw <ethanlxz@gmail.com>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/04 19:45:18 by lpang             #+#    #+#              #
#    Updated: 2023/07/20 02:42:54 by etlaw            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror -I -g3 
# CFLAGS +=	-pthread
# CFLAGS +=	-fsanitize=thread
LDFLAGS = -fsanitize=address -g

OBJS = obj/init.o \
	   obj/main.o \
	   obj/utils.o \
	   obj/philo.o \
	   obj/philo_actions.o \
	   obj/check_philo.o

all: $(NAME)

re: fclean all

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(LDFLAGS)

obj:
	mkdir obj

obj/%.o: srcs/%.c | obj
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -rf obj

fclean: clean
	rm -f $(NAME)

.PHONY: all re clean fclean
