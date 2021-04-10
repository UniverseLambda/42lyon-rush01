.DEFAULT: all
.PHONY: all clean fclean re
.SUFFIXES: .c .o

NAME := rush

CC ?= clang
AR ?= ar
RM ?= rm

CFLAGS ?=
CFLAGS := $(CFLAGS) -Wall -Wextra -Werror -Iinc -Ilibft/inc

BUILD_TYPE := release

OBJS := src/main.o

all: all-dependency $(NAME)

$(NAME): dependency $(OBJS)
	$(CC) $(LDFLAGS) -o $(NAME) $(OBJS) libft/libft.a

%.o: %.c libft.h
	$(CC) $(CFLAGS) -o $@ -c $<

clean: clean-dependency
	$(RM) -f $(OBJS)

fclean: fclean-dependency clean
	$(RM) -f $(NAME)

re: fclean all

debug:	BUILD_TYPE := debug
debug:	all

# DEPENDENCIES TARGET

dependency: all-dependency

all-dependency:
	make -C libft/ all

clean-dependency:
	make -C libft/ clean

fclean-dependency:
	make -C libft/ fclean

re-dependency:
	make -C libft/ re
