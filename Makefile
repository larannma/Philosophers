NAME		=	philo

HEAD		= ./include/philosophers.h

SRCS_FILES	= 	${shell find ./source -name "*.c"}

UTILS_FILES	= 	${shell find ./utils -name "*.c"}

SRCS		= 	$(SRCS_FILES)
OBJS		=	$(patsubst %.c,%.o,$(SRCS))
SRCS_UTILS_FILES	=	$(UTILS_FILES)
OBJS_UTILS		=	$(patsubst %.c,%.o,$(SRCS_UTILS_FILES))


CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

.PHONY:		all clean fclean re

all:		$(NAME)

%.o:		%.c $(HEAD)
			$(CC) $(CFLAGS) -c -g $< -o $@
		
$(NAME):	$(OBJS) $(HEAD) $(OBJS_UTILS)
			$(CC) -o $(NAME) $(OBJS) $(OBJS_UTILS)

clean:
			$(RM) $(OBJS) $(OBJS_UTILS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all