# （参考）
# https://zenn.dev/keitean/articles/aaef913b433677
NAME = push_swap

CHECKER = checker_bonus

INCLUDE = -I. -I./libft

SRCDIR = ./
SRCS = ft_operation.c
SRCS += ft_optimizer.c
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

all: $(NAME) bonus

$(NAME): $(OBJS) main.o
	$(MAKE) -C ./libft
	$(CC) $^ $(LIBS) -o $@

bonus: $(OBJS) checker.o
	$(MAKE) -C ./libft
	$(CC) $^ $(LIBS) -o $(CHECKER)

%.o: %.c
	$(CC) $(INCLUDE) $(CFLAGS) -c $< -o $*.o

clean:
	$(MAKE) -C ./libft fclean
	rm -f $(OBJS) main.o checker.o

fclean: clean
	rm -f $(NAME) $(CHECKER)

re: fclean all
