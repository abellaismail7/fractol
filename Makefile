CC 		= gcc
INCLUDE = -I./inc -I/usr/local/include/

CCFLAGS = -Wall -Werror -Wextra -g
ECFLAGS = $(CCFLAGS)
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	ECFLAGS +=  -lX11 -lXext
endif
ifeq ($(UNAME_S),Darwin)
	ECFLAGS +=  -framework OpenGL -framework AppKit
endif
ECFLAGS += -lm -lmlx

FILES 	= main event drw map colors util
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
	$(CC) $(CCFLAGS) -I mlx $(INCLUDE) -o $@ -c $<

debug: CCFLAGS += -g
debug: fclean all
bonus: all

clean:
	rm -f $(OBJ)
	rm -rf $(B_DIR)

fclean: clean
	rm -f $(EXE)

.PHONY: all clean fclean
