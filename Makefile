# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbenjy <jbenjy@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/02 15:57:25 by jbenjy            #+#    #+#              #
#    Updated: 2022/02/06 19:15:35 by jbenjy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME			=	push_swap

CFLAGS			=	-Wall -Wextra -Werror -g

HEAD			=	includes/*.h \
					libft/*.h
INCLUDES		= 	-I./includes/ -I./libft/

SRCS			=	srcs/main.c \
					srcs/utils.c \
					srcs/dequeue_utils.c \
					srcs/dequeue.c \
					srcs/core_operations.c \
					srcs/operations.c \
					srcs/operations3.c \
					srcs/operations2.c \
					srcs/checks.c \
					srcs/sort.c \
					srcs/parser.c 
					
OBJS			=	$(SRCS:.c=.o)

OBJS_LIB		=	${addprefix ./libft/, *.c}
L_LIBFT			=  ./libft/libft.a


GREEN			=	\033[0;32m
YELLOW			=	\033[0;33m

WORD_CLEANING	=	████─█───███─████─█──█─███─█──█─███─████\n\
					█──█─█───█───█──█─██─█──█──██─█──█──█\n\
					█────█───███─████─█─██──█──█─██──█──█─██\n\
					█──█─█───█───█──█─█──█──█──█──█──█──█──█\n\
					████─███─███─█──█─█──█─███─█──█─███─████─█─█─█\n

WORD_FCLEANING	=	███─████─█───███─████─█──█─███─█──█─███─████\n\
					█───█──█─█───█───█──█─██─█──█──██─█──█──█\n\
					███─█────█───███─████─█─██──█──█─██──█──█─██\n\
					█───█──█─█───█───█──█─█──█──█──█──█──█──█──█\n\
					█───████─███─███─█──█─█──█─███─█──█─███─████─█─█─█\n

WORD_SUCCESS	=	███─█─█─████─████─███─███─███─█\n\
					█───█─█─█──█─█──█─█───█───█───█\n\
					███─█─█─█────█────███─███─███─█\n\
					──█─█─█─█──█─█──█─█─────█───█\n\
					███─███─████─████─███─███─███─█\n

.c.o:
		@gcc ${CFLAGS} ${INCLUDES} -c -o $@ $^

$(NAME): ${OBJS} ${OBJS_LIB} ${HEAD}
		@make -C ./libft
		@cp libft/libft.a ./$(NAME)
		@$(CC) $(CFLAGS) ${INCLUDES} ${L_LIBFT} $(SRCS) -o $@
		@echo "${GREEN} ${WORD_SUCCESS}${NORMAL}"

all:	${NAME}

clean:
		@echo "${YELLOW} ${WORD_CLEANING}${NORMAL}"
		@make -C ./libft clean
		@rm -f $(OBJS)
		@echo "${GREEN} ${WORD_SUCCESS}${NORMAL}"
		
fclean:	
		@echo "${YELLOW} ${WORD_FCLEANING}${NORMAL}"
		@make -C ./libft fclean
		@rm -f $(OBJS)
		@rm -f ${NAME}
		@echo "${GREEN} ${WORD_SUCCESS}${NORMAL}"

re:		fclean all