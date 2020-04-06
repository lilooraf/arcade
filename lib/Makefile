##
## EPITECH PROJECT, 2020
## Untitled (Workspace)
## File description:
## Makefile
##

SRC			=	$(NCURSES_SRC)		\
				$(SFML_SRC)			\
				$(SDL_SRC)			\

OBJ			=	$(NCURSES_OBJ)		\
				$(SFML_OBJ)			\
				$(SDL_OBJ)			\

NAMES		=	$(N_NAME)			\
				$(SFML_NAME)		\
				$(SDL_NAME)			\

NCURSES_SRC	=	LibNcurses.cpp		\

SFML_SRC	=	LibSfml.cpp			\

SDL_SRC		=	LibSdl.cpp			\

RELOC_DIR	=	./../relocated/

NCURSES_OBJ	=	$(foreach source, $(NCURSES_SRC), $(RELOC_DIR)$(source:.cpp=.o))

SFML_OBJ	=	$(foreach source, $(SFML_SRC), $(RELOC_DIR)$(source:.cpp=.o))

SDL_OBJ		=	$(foreach source, $(SDL_SRC), $(RELOC_DIR)$(source:.cpp=.o))

IDIR		=	./../include/

CXXFLAGS	=	-fPIC -shared -W -Wall -Wextra -I$(IDIR)

NCURSES_LIB	=	-lncurses

SFML_LIB	=	-lsfml-graphics -lsfml-window

SDL_LIB		=	-lSDL2 -lSDL2_image -lSDL2_ttf

N_NAME		=	lib_arcade_ncurses.so

SFML_NAME	=	lib_arcade_sfml.so

SDL_NAME	=	lib_arcade_sdl.so

all:		ncurses sfml sdl

ncurses:	$(NCURSES_OBJ)
		g++ -o $(N_NAME) $(NCURSES_OBJ) $(CXXFLAGS) $(NCURSES_LIB)
		rm -f $(NCURSES_OBJ)

sfml:		$(SFML_OBJ)
		g++ -o $(SFML_NAME) $(SFML_OBJ) $(CXXFLAGS) $(SFML_LIB)
		rm -f $(SFML_OBJ)


sdl:		$(SDL_OBJ)
		g++ -o $(SDL_NAME) $(SDL_OBJ) $(CXXFLAGS) $(SDL_LIB)
		rm -f $(SDL_OBJ)


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