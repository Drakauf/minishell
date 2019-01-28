#**************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/12/04 14:37:16 by shthevak     #+#   ##    ##    #+#        #
#    Updated: 2019/01/28 17:13:41 by shthevak    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY : all clean fclean re

NAME = libft.a

# **************************************************************************** #
#									PATH                                       #
# **************************************************************************** #

SRC_PATH= ./
OBJ_PATH= ./obj/
INC_PATH= ./includes/

# **************************************************************************** #
# 									SRCS                                       #
# **************************************************************************** #

SRC_NAME = ft_isdigit.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isprint.c\
		   ft_toupper.c ft_tolower.c ft_putchar.c ft_atoi.c ft_strcmp.c\
		   ft_strncmp.c ft_strstr.c ft_strcat.c ft_strncat.c ft_strnstr.c\
		   ft_strcpy.c ft_strncpy.c ft_strlen.c  ft_strdup.c ft_strchr.c\
		   ft_strrchr.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c\
		   ft_memchr.c ft_memcmp.c ft_memmove.c ft_strlcat.c ft_memalloc.c\
		   ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c\
		   ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c\
		   ft_strsub.c ft_strjoin.c ft_strtrim.c ft_chartotrim.c ft_strsplit.c\
		   ft_itoa.c ft_inttochar.c ft_itoa_base.c ft_intlen_base.c ft_putstr.c\
		   ft_putendl.c ft_putnbr.c ft_putnbr_base.c ft_puttab2d.c ft_voidswap.c\
		   ft_voidrev.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
		   ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c\
		   ft_lstiter.c ft_lstmap.c ft_strisalnum.c ft_strjoinfree.c get_next_line.c\

INC_NAME= libft.h

# **************************************************************************** #
#  									VAR                                        #
# **************************************************************************** #

OBJ_NAME= $(SRC_NAME:.c=.o)
INC = $(addprefix $(INC_PATH), $(INC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

# **************************************************************************** #
#  									FLAG                                       #
# **************************************************************************** #

ifndef FLAG
	FLAG= -Wall -Werror -Wextra
endif

NORME= norminette

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

$(NAME): $(OBJ_PATH) $(OBJ) $(INC)
	@ar rcs $(NAME) $(OBJ)
	$(SAY) $(GREEN) $(R_1) $(CLEAR_R) 	                             📚 📚 📚  TheLib is done 📚 📚 📚 \n$(END)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH) 2> /dev/null
	$(SAY) $(YELLOW) $(R_1) $(CLEAR_R)  	                          Directory ./obj created$(END)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INC)
	@gcc $(FLAGS) -I $(INC) -o $@ -c $<
	$(SAY) $(YELLOW) $(R_1) $(CLEAR_R)  	        	              Binary File done : $*$(END)

clean:
	@rm -rf $(OBJ_PATH) 2> /dev/null
	$(SAY) $(RED) $(R_1) $(CLEAR_R) 	               🗑️ Libft : Binary files directory \"/obj\" hab been deleted.🗑️ \n$(END)

fclean: clean
	@rm -rf $(NAME) 2> /dev/null
	$(SAY) $(RED) $(R_1) $(CLEAR_R)     	                               📕 TheLib has been deleted.📕\n$(END)

re: fclean all
