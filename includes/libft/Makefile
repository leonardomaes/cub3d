SOURCES = \
	ft_atoi_hex.c ft_atoi.c ft_bzero.c ft_calloc.c ft_chartrim.c ft_isalnum.c ft_isalpha.c \
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_isspace.c ft_itoa.c ft_memchr.c \
	ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
	ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
	ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
	ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_uitoa.c \
	ft_strstr.c  ft_strcat.c ft_strcpy.c ft_strndup.c ft_spacetrim.c \
	get_next_line.c get_next_line_utils.c ft_strcmp.c ft_strextract.c 
OBJS = $(SOURCES:.c=.o)

BSOURCES = \
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
	ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
	ft_lstclear.c ft_lstiter.c ft_lstmap.c \

BON_OBJS = $(BSOURCES:.c=.o)

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -c $(SOURCES)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) $(BON_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus:	$(OBJS) $(BON_OBJS)
	$(CC) $(CFLAGS) -c $(SOURCES) $(BSOURCES)
	$(AR) $(NAME) $(OBJS) $(BON_OBJS)

.PHONY: all clean fclean re bonus
