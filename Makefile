NAME1 :=		server
NAME2 :=		client
CC :=			gcc
FLAGS :=		-Wall -Werror -Wextra -g

LIBRARIES :=	./libraries/libft/libft.a\

SOURCES1	:=	server.c\

SOURCES2	:=	client.c\

INCLUDE_DIR :=	./includes
HEADERS :=		-I ./includes -I ./libraries/libft/header
LIBFT :=		./libraries/libft
SOURCE_DIR1 :=	./sources/server
SOURCE_DIR2 :=	./sources/client
OBJECT_DIR	:=	./objects
OBJECT_DIR1 :=	./objects/server
OBJECT_DIR2 :=	./objects/client
OBJECTS1 :=		$(addprefix $(OBJECT_DIR1)/, $(SOURCES1:.c=.o))
OBJECTS2 :=		$(addprefix $(OBJECT_DIR2)/, $(SOURCES2:.c=.o))



all:	libraries $(NAME1) $(NAME2)

$(NAME1):		$(OBJECTS1)
					$(CC) $(FLAGS) $(LIBRARIES) -o $@ $^ $(HEADERS)

$(NAME2):		$(OBJECTS2)
					$(CC) $(FLAGS) $(LIBRARIES) -o $@ $^ $(HEADERS)

$(OBJECT_DIR1)/%.o:	$(SOURCE_DIR1)/%.c
						mkdir -p $(dir $@)
						$(CC) $(FLAGS) $(HEADERS) -c -o $@ $< -O3

$(OBJECT_DIR2)/%.o:	$(SOURCE_DIR2)/%.c
						mkdir -p $(dir $@)
						$(CC) $(FLAGS) $(HEADERS) -c -o $@ $< -O3

clean:
		rm -f $(OBJECTS1) $(OBJECTS2)
		$(MAKE) fclean -C $(LIBFT)

fclean:	clean
		rm -f $(NAME1) $(NAME2)
		if [ -d "$(OBJECT_DIR)" ]; then rm -drf $(OBJECT_DIR); fi

libraries:
		@$(MAKE) -s -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re libraries