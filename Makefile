# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 11:31:06 by bfaure            #+#    #+#              #
#    Updated: 2023/11/30 11:03:42 by bfaure           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# ******** VARIABLES ******** #

# ---- Final Executable --- #

NAME		=	philo

# ---- Directories ---- #

DIR_OBJS	=	.objs/

DIR_SRCS	=	src/

# ---- Files ---- #

SRCS			=	main.c \
					ft_atoi.c \
					routine.c \

OBJS = ${SRCS:%.c=${DIR_OBJS}%.o}

DEPS = ${SRCS:%.c=${DIR_OBJS}%.d}

# ---- Compilation ---- #

CC		=	cc

DEPS_FLAGS = -MMD -MP

CFLAGS	=	${DEPS_FLAGS} -Wall -Wextra -Werror -pthread -g3 -fsanitize=address

# ---- Commands ---- #

RM		=	rm -rf
MKDIR	=	mkdir -p

# ********* RULES ******** #

	
all		:	$(NAME)

.PHONY:	all clean fclean re force

# ---- Variables Rules ---- #

${NAME}	:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

# ---- Compiled Rules ---- #

-include ${DEPS}

${DIR_OBJS}%.o	:	${DIR_SRCS}%.c
					@${MKDIR} ${DIR_OBJS}
					${CC} ${CFLAGS} -c $< -o $@		

# ---- Usual Commands ---- #

clean			:
					${RM} ${DIR_OBJS}

fclean			:	clean
					${RM} ${NAME}

re				:	fclean
					$(MAKE)
