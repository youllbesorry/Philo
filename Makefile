# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 11:31:06 by bfaure            #+#    #+#              #
#    Updated: 2023/12/05 18:51:13 by bfaure           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# ******** VARIABLES ******** #

# ---- Final Executable --- #

NAME		=	philo

# ---- Directories ---- #

DIR_OBJS	=	.objs/

DIR_SRCS	=	./src/

# ---- Files ---- #

SRCS			=	main.c \
					routine.c \
					utils/ft_atoi.c \
					utils/ft_isdigit.c \
					utils/init.c \
					utils/ft_exit.c \
					actions.c \
					utils/utils.c \
					fork.c \
					monitoring.c \

OBJS	= ${addprefix ${DIR_OBJS},${SRCS:.c=.o}}

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
	@				$(MKDIR) $(shell dirname $@)
					${CC} ${CFLAGS} -c $< -o $@		

# ---- Usual Commands ---- #

clean			:
					${RM} ${DIR_OBJS}

fclean			:	clean
					${RM} ${NAME}

re				:	fclean
					$(MAKE)
