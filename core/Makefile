##
## EPITECH PROJECT, 2020
## Untitled (Workspace)
## File description:
## Makefile
##

SRC			=	Core.cpp				\
				Score.cpp				\

RELOC_DIR	=	../relocated/

OBJ			=	$(foreach source, $(SRC), $(RELOC_DIR)$(source:.cpp=.o))

CXXFLAGS	=	-W -Wall -Wextra -Iinclude -ldl -g -pthread

NAME		=	../arcade

all:		core

core:		$(OBJ)
		g++ -o $(NAME) $(OBJ) $(RELOC_DIR)main.o $(CXXFLAGS)

$(RELOC_DIR)%.o:	%.cpp
		g++ -o $@ -c $^ $(CXXFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:			fclean all

.PHONY:		all			\
			core		\
			games		\
			graphicals	\
			clean		\
			fclean		\
			re			\
