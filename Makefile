# （参考）
# https://zenn.dev/keitean/articles/aaef913b433677
NAME = push_swap

INCLUDE = -I. -I./libft

SRCDIR = ./
SRCS = main.c
SRCS += ft_operation.c
SRCS += ft_phase1.c
SRCS += ft_phase2.c
SRCS += ft_phase3.c
SRCS += ft_stack.c
SRCS += ft_util.c

OBJS = $(addprefix $(SRCDIR),$(SRCS:%.c=%.o))

LIBS = -L./libft -lft

CC = cc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -g

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	$(CC) $^ $(LIBS) -o $@

%.o: %.c
	$(CC) $(INCLUDE) $(CFLAGS) -c $< -o $*.o

clean:
	$(MAKE) -C ./libft fclean
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
