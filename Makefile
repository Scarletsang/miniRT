################################
######     Variables     #######
################################

NAME:=miniRT

CC:=cc
CFLAGS= -Wall -Wextra -Werror
ifdef DEBUG
	CFLAGS+= -g3
	LDFLAGS+= -g3
endif
INCLUDE_DIR= \
	include

###################################
######     Source files     #######
###################################

# To add souce files, create a varaible for each folder, and then
# contatenate them in the SRC variable like this:

MAIN_SRC:= \
	main.c
SRC:= $(MAIN_SRC)

####################################
######     Library files     #######
####################################

# To compile a library, store a variable for their library file like this
# and add a rule for it after the main rules:
# LIBRARY_NAME=lib/LIBRARY_NAME/LIBRARY_NAME.a
LIBFT=lib/libft/libft.a
MLX42=lib/MLX42/build/libmlx42.a

# To add a library, add the library header file like this:
# LIB_INCLUDE_DIR+= lib/LIBRARY_NAME/include
LIB_INCLUDE_DIR+= lib/libft/include
LIB_INCLUDE_DIR+= lib/MLX42/include

# Then add the library to the linking process in one of the following ways:
# LDFLAGS+= -Llib/LIBRARY_NAME -lLIBRARY_NAME
# LDFLAGS+= lib/LIBRARY_NAME/libLIBRARY_NAME.a
LDFLAGS+= $(LIBFT)
LDFLAGS+= $(MLX42)

# Specify the location of the binary and header file of the readline library
# on MacOS
ifeq ($(shell uname), Darwin)
# For MLX42
	LDFLAGS+= -framework Cocoa -framework OpenGL -framework IOKit
# For GLFW
	LDFLAGS+= -lglfw -L$(shell brew --prefix glfw)/lib
else
# For GLFW
	LDFLAGS+= -ldl -lglfw -pthread -lm
endif

###########################################
######     Object name reformat     #######
###########################################

# This in effect makes all the object files to be compiled in the OBJ_DIR directory

SRC_DIR:=src
OBJ_DIR:=obj
OBJ:=$(addprefix $(OBJ_DIR)/,$(subst /,@,$(SRC:.c=.o)))

#################################
######     Main rules     #######
#################################

all:
	@$(MAKE) $(NAME) -j

$(NAME): $(LIBFT) $(MLX42) $(OBJ)
	@$(CC) $(OBJ) -o $(NAME) $(LDFLAGS) && echo "Compilation of $(NAME) successful"

bonus: re

##########################################
######     Library compilation     #######
##########################################

# To compile a library, add a rule like this:

# $(LIBRARY_NAME):
# 	@$(MAKE) $(if $(FSANITIZE),FSANITIZE=yes,) -C lib/LIBRARY_NAME

$(LIBFT):
	@$(MAKE) $(if $(DEBUG),FSANITIZE=yes,) USE="stringbuilder iostream" -C lib/libft

$(MLX42):
	@cmake $(if $(DEBUG),-DDEBUG=1, ) -B lib/MLX42/build -S lib/MLX42
	@cmake --build lib/MLX42/build -j4

#########################################
######     Object compilation     #######
#########################################

.SECONDEXPANSION:
$(OBJ_DIR)/%.o: $(SRC_DIR)/$$(subst @,/,$$*).c
	@$(CC) $(CFLAGS) $(addprefix -iquote ,$(INCLUDE_DIR)) $(addprefix -I ,$(LIB_INCLUDE_DIR)) -c $< -o $@

$(OBJ): $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

###############################################
######     Pack objects for testing     #######
###############################################

pack: CFLAGS += -fPIC
pack: LDFLAGS += -shared
pack: $(LIBFT) $(OBJ)
	@$(CC) $(OBJ) -o lib$(NAME).so $(LDFLAGS) && echo "Compilation of $(NAME).so successful"

unpack:
	@rm -f lib$(NAME).so

repack: unpack clean
	@$(MAKE) pack

###############################
######     Cleaning     #######
###############################

clean:
	@$(MAKE) -C lib/libft clean
ifdef REBUILD_MLX42
	@rm -rf lib/MLX42/build
endif
	@rm -f $(OBJ)

fclean: clean
	@$(MAKE) -C lib/libft fclean
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re bonus