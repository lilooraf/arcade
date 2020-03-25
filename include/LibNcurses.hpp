/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** LibNcurses
*/

#ifndef LIBNCURSES_HPP_
#define LIBNCURSES_HPP_

#include <ncurses.h>

#include "ILib.hpp"
#include "defs.hpp"

class LibNcurses : public ILib {
    public:
        LibNcurses();
        ~LibNcurses();

        void test() const;
        void windowOpen();
        void windowClose();
        void windowClear();
        bool windowIsOpen() const;

        /* USER INPUT */
        void userInput();
        bool buttonClose() const;
        bool buttonNextLib() const;
        bool buttonPrevLib() const;
    protected:
    private:
        bool _windowState;
        WINDOW *_window;
        int _key;
};

#endif /* !LIBNCURSES_HPP_ */
