CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR) -g3
LDFLAGS =

_END    = $(shell printf "\033[0m")
_BOLD   = $(shell printf "\033[1m")
_CYAN   = $(shell printf "\033[36m")
_BLUE   = $(shell printf "\033[34m")

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include

SRC_FILES = dlst/ft_dlstadd_back.c \
			dlst/ft_dlstclear.c \
			dlst/ft_dlstlast.c \
			dlst/ft_dlstnew.c \
			main.c \
			parse/ft_better_atoi.c \
			parse/parse.c \
			dlst/ft_dlstsize.c \
			instruction/instruction.c \
			instruction/instruction_utils1.c \
			instruction/instruction_utils2.c \
			instruction/instruction_utils3.c \
			operation/operation.c \
			parse/ft_split.c \
			utils.c \
			small.c \
			turkish/sort.c \
			turkish/rot.c \
			turkish/utils.c \
			turkish/utils2.c

OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

NAME = push_swap

all: ascii $(NAME)
	@echo "$(_CYAN)[BUILD COMPLET]$(_END) $(NAME) est prêt !"

$(NAME): $(OBJ_FILES)
	@$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@
	@echo "$(_CYAN)[LINKING]$(_END) $(NAME) est créé !"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(_CYAN)[COMPILATION]$(_END) Création de l'objet : $@"

re: fclean all

NAME_BONUS = checker

BONUS_SRC_FILES = parse/parse.c \
				  parse/ft_split.c \
				  parse/ft_better_atoi.c \
				  utils.c \
				  dlst/ft_dlstadd_back.c \
				  dlst/ft_dlstclear.c \
				  dlst/ft_dlstlast.c \
				  dlst/ft_dlstnew.c \
				  dlst/ft_dlstsize.c \
				  gnl/get_next_line.c \
				  gnl/get_next_line_utils.c \
				  operation/operation.c \
				  instruction/instruction.c \
				  instruction/instruction_utils1.c \
				  instruction/instruction_utils2.c \
				  instruction/instruction_utils3.c \
				  bonus/exit.c \
				  bonus/main.c
BONUS_OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(BONUS_SRC_FILES:.c=.o))

bonus: $(BONUS_OBJ_FILES)
	@$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $(NAME_BONUS)
	@echo "$(_CYAN)[BONUS]$(_END) Compilation avec les fonctionnalités bonus terminée ! ✨"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(_BLUE)[CLEAN]$(_END) Suppression des fichiers objets."

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@echo "$(_BLUE)[FCLEAN]$(_END) Suppression de $(NAME) et de la copie de libft."


ascii:
	@echo $(_CYAN)$(_BOLD)
	@echo "PUSH SWAP"
	@echo $(_END)

test:
	@for j in $$(seq 500 500); do \
		echo "j = $$j"; \
		for i in $$(seq 500 500); do \
			ARG=$$(shuf -i 1-$$j -n 5 | tr '\n' ' '); \
			./push_swap $$ARG | wc -l; \
			./push_swap $$ARG | ./checker_linux $$ARG; \
		done; \
	done

.PHONY: all clean fclean re ascii
