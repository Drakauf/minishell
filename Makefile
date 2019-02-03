# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/01/28 15:19:07 by shthevak     #+#   ##    ##    #+#        #
#    Updated: 2019/02/03 14:05:21 by shthevak    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY : all clean fclean re

NAME = minishell

# **************************************************************************** #
#									PATH                                       #
# **************************************************************************** #

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./includes/
LIBFT_PATH = ./libft/
PRINT_PATH = ./ft_printf/

# **************************************************************************** #
# 									SRCS                                       #
# **************************************************************************** #

LIB_NAME = libft.a
PRT_NAME = libftprintf.a

INC_NAME =minishell.h

SRC_NAME = main.c drakauf.c charizard.c env_struct.c ft_free.c quote.c dquote.c\
		   semicolon.c split_com.c handle_tab.c

# **************************************************************************** #
#  									VAR                                        #
# **************************************************************************** #

OBJ_NAME = $(SRC_NAME:.c=.o)
INC = $(addprefix $(INC_PATH), $(INC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

PRT = $(addprefix $(PRINT_PATH), $(PRT_NAME))
LIB = $(addprefix $(LIBFT_PATH), $(LIB_NAME))

# **************************************************************************** #
#  									FLAG                                       #
# **************************************************************************** #

ifndef FLAG
	FLAG = -Wall -Werror -Wextra -g
endif

NORME = norminette

# **************************************************************************** #
#  									STYLE                                      #
# **************************************************************************** #

SAY=@echo
SAYD=@echo $

R_1= \033[1A
CLEAR_R= \033[J
WHITE= "\033[1;37m
GREEN= "\033[1;32m
RED= "\033[1;31m
YELLOW= "\033[1;33m
BLUE= "\033[1;34m
END= \033[0m"

# **************************************************************************** #
# 									REGLES                                     #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(LIB) $(PRT) $(OBJ_PATH) $(OBJ)
	$(SAY) "$(R_1) $(CLEAR_R)\n$(END)
	@gcc $(FLAGS) -o $@ $(OBJ) $(PRT) $(LIB)
	$(SAY) $(GREEN) $(R_1) $(CLEAR_R) 	                     ▂▃▄▅▆▇█▓▒░ ⚜ ⚜ ⚜  Minishell ⚜ ⚜ ⚜ ░▒▓█▇▆▅▄▃▂\n$(END)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH) 2> /dev/null
	$(SAY) $(YELLOW) $(R_1) $(CLEAR_R)  	                          Directory ./obj created$(END)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INC)
	@gcc $(FLAGS) -I $(INC) -o $@ -c $<
	$(SAY) $(YELLOW) $(R_1) $(CLEAR_R)  		              Binary File done : $*$(END)

$(LIB):
	@make -C $(LIBFT_PATH)

$(PRT):
	@make -C $(PRINT_PATH)

clean:
	@make -C $(LIBFT_PATH) clean
	@make -C $(PRINT_PATH) clean
	@rm -rf $(OBJ_PATH) 2> /dev/null
	$(SAY) $(RED) $(R_1) $(CLEAR_R) 	             🗑️ Minishell : Binary files directory \"/obj\" hab been deleted.🗑️\n$(END)

all_clean:
	@make -C $(LIBFT_PATH) fclean
	@make -C $(PRINT_PATH) fclean
	@rm -rf $(OBJ_PATH) 2> /dev/null
	$(SAY) $(RED) $(R_1) $(CLEAR_R) 	             🗑️ Minishell : Binary files directory \"/obj\" hab been deleted.🗑️\n$(END)



fclean: all_clean
	@rm -rf $(NAME) 2> /dev/null
	$(SAY) $(RED) $(R_1) $(CLEAR_R)     	                             🐚 Minishell has been deleted.🐚\n$(END)

new_line:
	$(SAY)

re: fclean new_line  all
