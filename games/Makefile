##
## EPITECH PROJECT, 2020
## Untitled (Workspace)
## File description:
## Makefile
##

CORE_SRC	=	../core/Core.cpp	\
				../core/Score.cpp	\

SRC			=	$(NIBBLER_SRC)		\
				$(PACMAN_SRC)		\

OBJ			=	$(NIBBLER_OBJ)		\
				$(PACMAN_OBJ)		\

NAMES		=	$(N_NAME)			\
				$(P_NAME)			\

NIBBLER_SRC	=	Nibbler.cpp			\
				Player.cpp			\
				$(CORE_SRC)			\

PACMAN_SRC	=	Pacman.cpp			\
				Player.cpp			\
				$(CORE_SRC)			\

RELOC_DIR	=	./../relocated/

NIBBLER_OBJ	=	$(foreach source, $(NIBBLER_SRC), $(RELOC_DIR)$(source:.cpp=.o))

PACMAN_OBJ	=	$(foreach source, $(PACMAN_SRC), $(RELOC_DIR)$(source:.cpp=.o))

IDIR		=	./../include/

CXXFLAGS	=	-fPIC -shared -W -Wall -Wextra -I$(IDIR)

N_NAME		=	lib_arcade_nibbler.so

P_NAME		=	lib_arcade_pacman.so

all:		nibbler pacman

nibbler:	$(NIBBLER_OBJ)
		g++ -o $(N_NAME) $(NIBBLER_OBJ) $(CXXFLAGS)

pacman:		$(PACMAN_OBJ)
		g++ -o $(P_NAME) $(PACMAN_OBJ) $(CXXFLAGS)

$(RELOC_DIR)%.o:	%.cpp
		g++ -o $@ -c $^ $(CXXFLAGS)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAMES)

re:			fclean all

.PHONY:		all			\
			nibbler		\
			pacman		\
			clean		\
			fclean		\
			re			\