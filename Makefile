# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skaur <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 13:03:18 by skaur             #+#    #+#              #
#    Updated: 2022/11/24 13:03:32 by skaur            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

SRCS =  get_next_line.c get_next_line_utils.c

AR = ar rcs

CC = cc -c

CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=1

HEAD = get_next_line.h

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME):	$(OBJS)
	@$(AR) $@ $(OBJS)
	@ranlib $@

$(OBJS):	$(SRCS)
	@$(CC) $(CFLAGS) $(SRCS)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
