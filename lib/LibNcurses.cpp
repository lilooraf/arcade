/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** LibNcurses
*/

#include "LibNcurses.hpp"

LibNcurses::LibNcurses()
{
    this->_key = -1;
    this->_window = initscr();
    this->_windowState = false;
}

LibNcurses::~LibNcurses()
{
    this->_windowState = false;
    endwin();
}

void LibNcurses::test() const
{
    std::cout << "test ncurses" << std::endl;
}

void LibNcurses::windowOpen()
{
    std::cout << "ncurses window open" << std::endl;
    keypad(this->_window, true);
    noecho();
    this->_windowState = true;
}

void LibNcurses::windowClose()
{
    std::cout << "ncurses window close" << std::endl;
    endwin();
    this->_windowState = false;
}

void LibNcurses::windowClear()
{
    wclear(_window);
    wrefresh(_window);
}

bool LibNcurses::windowIsOpen() const
{
    std::cout << this->_windowState << std::endl;
    return this->_windowState;
}

/* USER INPUT */

void LibNcurses::userInput()
{
    this->_key = getch();
}

bool LibNcurses::buttonClose() const
{
    if (this->_key == 27)
        return true;
    return false;
}

bool LibNcurses::buttonNextLib() const
{
    if (this->_key == KEY_F(3))
        return true;
    return false;
}

bool LibNcurses::buttonPrevLib() const
{
    if (this->_key == KEY_F(2))
        return true;
    return false;
}

extern "C" {
    LibNcurses *constuct() {
        return new LibNcurses();
    }
}