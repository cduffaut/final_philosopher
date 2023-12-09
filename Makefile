# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csil <csil@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/03 22:34:48 by csil              #+#    #+#              #
#    Updated: 2023/12/08 23:08:36 by csil             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= \
		philo.c free_all_and_exit.c parsing_args.c init_lists.c safe_exec.c \
		time_funcs.c init_threads.c routine.c

LIBFT	=		./libft/libft.a

MLIBFT	=		@$(MAKE) -C libft

OBJS	= $(SRCS:.c=.o)

GCC	= gcc -Wall -Wextra -Werror

NAME	= philo

all:	lib $(NAME)

lib:
	$(MLIBFT) all

%.o:	%.c 
	$(GCC) -c $< -o $@

$(NAME) :	${OBJS}
		$(GCC) -o ${NAME} ${OBJS} ${LIBFT}

clean:
	rm -f $(OBJS)
	${MLIBFT} clean

fclean:	clean
	rm -f $(NAME)
	${MLIBFT} fclean

re:	fclean all

.PHONY : re fclean clean all bonus
