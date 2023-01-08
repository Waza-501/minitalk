NAME1 :=		server
NAME2 :=		client
CC :=			gcc
FLAGS :=		-Wall -Werror -Wextra

LIBRARIES :=	./libft/libft.a
HEADERS :=		./headers ./libft/libft.h
INCLUDE_DIR :=	./includes
OBJECT_DIR	:=	./objects
OBJECT_DIR1 :=	./objects/server
OBJECT_DIR2 :=	./objects/client
SOURCE_DIR1 :=	./sources/server
SOURCE_DIR2 :=	./sources/client
LIBFT :=		./libft
OBJECTS :=		$(addprefix $(OBJECT_DIR1)/, $(SOURCES1!:.c=.o))
OBJECTS :=		$(addprefix $(OBJECT_DIR2)/, $(SOURCES2!:.c=.o))



all:	libraries $(NAME1) $(NAME2)

$(NAME1):		$(OBJECTS1)
					$(CC) $(FLAGS) $(LIBFT) -o $@ $^ $(HEADERS)

$(NAME2):		$(OBJECTS2)
					$(CC) $(FLAGS) $(LIBFT) -o $@ $^ $(HEADERS)

$(OBJECT_DIR1)/%.o:	$(SOURCE_DIR)/%.c
						mkdir -p $(dir $@)
						$(CC) -c -o $@ $< -03

$(OBJECT_DIR2)/%.o:	$(SOURCE_DIR)/%.c
						mkdir -p $(dir $@)
						$(CC) -c -o $@ $< -03

clean:
		rm -f $(OBJECTS1) $(OBJECTS2)
		$(MAKE) fclean -C $(LIBFT)

fclean:	clean
		rm -f $(NAME1) $(NAME2)
		if [ -d "$(OBJECT_DIR)" ]; then rm -drf $(OBJECT_DIR); fi

libraries:
		$(MAKE) -s -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re libraries