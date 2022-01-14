CC 		= gcc
INCLUDE = -I./inc -I/usr/local/include/

CCFLAGS = -Wall -Werror -Wextra
ECFLAGS = $(CCFLAGS)
UNAME_S := $(shell uname -s)
ECFLAGS +=  -framework OpenGL -framework AppKit
ECFLAGS += -lm -lmlx

FILES 	= main event drw map colors util util_extra
S_DIR	= src
B_DIR	= build
SRC		= $(addprefix $(S_DIR)/, 	$(FILES:=.c))
OBJ		= $(addprefix $(B_DIR)/, 	$(FILES:=.o))
EXE 	= fractol

all: $(EXE) 

$(EXE): $(OBJ)
	$(CC) $(OBJ) -o $@ $(ECFLAGS)


$(B_DIR)/%.o: $(S_DIR)/%.c inc/fractol.h
	mkdir -p $(@D)
	$(CC) $(CCFLAGS) $(INCLUDE) -o $@ -c $<

clean:
	rm -f $(OBJ)
	rm -rf $(B_DIR)

fclean: clean
	rm -f $(EXE)

re: fclean all

.PHONY: all clean fclean re
