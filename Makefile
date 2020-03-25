##
## EPITECH PROJECT, 2020
## Untitled (Workspace)
## File description:
## Makefile
##

GAMESDIR	=	./games/

GRAPHDIR	=	./lib/

COREDIR		=	./core/

MAIN		=	main.cpp				\

RELOC_DIR	=	./relocated/

all:		graphicals games core

core:	
		g++ -c $(MAIN)
		mv main.o $(RELOC_DIR)
		make -sC $(COREDIR)

games:
		make -sC $(GAMESDIR)

graphicals:
		make -sC $(GRAPHDIR)

clean:
	make -sC $(GRAPHDIR) clean
	make -sC $(GAMESDIR) clean
	rm -f $(RELOC_DIR)*.o

fclean:		clean
	make -sC $(GRAPHDIR) fclean
	make -sC $(GAMESDIR) fclean
	make -sC $(COREDIR) fclean

re:			fclean all

.PHONY:		all			\
			core		\
			games		\
			graphicals	\
			clean		\
			fclean		\
			re			\
