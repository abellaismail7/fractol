CC 		= gcc
CCFLAGS = -Wall -Werror -Wextra -lX11 -lXext -lm
INCLUDE = -I./inc

FILES 	= main
S_DIR	= src
B_DIR	= build
SRC		= $(addprefix $(S_DIR)/, 	$(FILES:=.c))
OBJ		= $(addprefix $(B_DIR)/, 	$(FILES:=.o))
MLX 	= mlx.a
EXE 	= fractol

all: $(EXE) 

$(EXE): $(OBJ) $(MLX)
	$(CC) $(CCFLAGS) $(MLX) $^ -o $@

$(B_DIR)/%.o: $(S_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CCFLAGS) $(INCLUDE) -o $@ -c $<

debug: CCFLAGS += -g
debug: fclean all
bonus: all

clean:
	rm -f $(OBJ)
	rm -rf $(B_DIR)

fclean: clean
	rm -f $(EXE)

.PHONY: all clean fclean
