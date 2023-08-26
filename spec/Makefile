################################
######     Variables     #######
################################

NAME:=debug.out

CC:=g++
CFLAGS:= -Wall -Wextra -Werror -std=c++14
LDFLAGS:=-std=c++14
ifdef FSANITIZE
	CFLAGS+= -g3 -fsanitize=address
	LDFLAGS+= -g3 -fsanitize=address
endif
INCLUDE_DIR= \
	../include \
	../lib/libft/include

###################################
######     Source files     #######
###################################

# To add souce files, create a varaible for each folder, and then
# contatenate them in the SRC variable like this:

TEST_SRC:= $(shell cd tests && echo *.cpp)

SRC:= $(TEST_SRC)

####################################
######     Library files     #######
####################################

# To compile a library, store a variable for their library file like this
# and add a rule for it after the main rules:
# LIBRARY_NAME=lib/LIBRARY_NAME/LIBRARY_NAME.a
LIBFT= ../lib/libft/libft.a
MINIRT= $(CURDIR)/../libminiRT.so

# To add a library, add the library header file like this:
LIB_INCLUDE_DIR += $(shell brew --prefix googletest)/include

# Then add the library to the linking process in one of the following ways:
LDFLAGS+= -lft -L$(CURDIR)/../lib/libft -Wl,-rpath,$(CURDIR)/../lib/libft
LDFLAGS+= -L$(shell brew --prefix googletest)/lib -lgtest  -L$(shell brew --prefix googletest)/lib -lgtest_main
LDFLAGS+= -lminiRT -L$(CURDIR)/.. -Wl,-rpath,$(CURDIR)/..
# LDFLAGS+= -Llib/LIBRARY_NAME -lLIBRARY_NAME
# LDFLAGS+= lib/LIBRARY_NAME/libLIBRARY_NAME.a

###########################################
######     Object name reformat     #######
###########################################

# This in effect makes all the object files to be compiled in the OBJ_DIR directory

SRC_DIR:=tests
OBJ_DIR:=obj
OBJ:= $(addprefix $(OBJ_DIR)/,$(subst /,@,$(SRC:.cpp=.o)))

#################################
######     Main rules     #######
#################################

all: DEPS
	@$(MAKE) $(NAME) -j

run: all
	@DYLD_LIBRARY_PATH=$(CURDIR)/.. ./$(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(OBJ) -o $(NAME) $(LDFLAGS) && echo "Compilation of $(NAME) successful"

##########################################
######     Library compilation     #######
##########################################

# To compile a library, add a rule like this:

# $(LIBRARY_NAME):
# 	@${MAKE} $(if $(FSANITIZE),FSANITIZE=yes,) -C lib/LIBRARY_NAME

DEPS: $(MINIRT) $(LIBFT)

$(MINIRT):
	@$(MAKE) $(if $(FSANITIZE),DEBUG=yes,) -C .. repack

$(LIBFT):
	@$(MAKE) $(if $(FSANITIZE),FSANITIZE=yes,) USE="stringbuilder hashtable iostream parser ft_printf" -C ../lib/libft re


#########################################
######     Object compilation     #######
#########################################

.SECONDEXPANSION:
$(OBJ_DIR)/%.o: $(SRC_DIR)/$$(subst @,/,$$*).cpp
	@$(CC) $(CFLAGS) $(addprefix -iquote ,$(INCLUDE_DIR)) $(addprefix -I ,$(LIB_INCLUDE_DIR)) -c $< -o $@

$(OBJ): $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

###############################
######     Cleaning     #######
###############################

clean:
	@$(MAKE) -C .. clean
	@$(MAKE) -C $(CURDIR)/../lib/libft clean
	@rm -f $(OBJ_DIR)/*.o

fclean: clean
	@$(MAKE) -C .. unpack
	@$(MAKE) -C $(CURDIR)/../lib/libft fclean
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re