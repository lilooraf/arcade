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
    return this->_windowState;
}

void LibNcurses::windowDisplay(std::vector<std::vector<char>> tab)
{
    std::string str = " ";
    int y = 0;
    for (std::vector<char> ta: tab) {
        int x = 0;
        for (char c : ta) {
            str[0] = c;
            mvprintw(y, x, str.c_str());
            x++;
        }
        y++;
    }
}

void LibNcurses::setTextures(std::map<char, std::string>)
{

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