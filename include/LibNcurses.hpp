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

        void windowOpen();
        void windowClose();
        void windowClear();
        bool windowIsOpen() const;
        void windowDraw(char, float, float);
        void windowDrawBackground(std::string username, int min, int sec, int score);
        void windowDrawGame(char, float, float);
        void windowDrawScore(std::string username, int min, int sec, int score);
        void windowDisplay() {};
        void windowGameOver(std::string username, int min, int sec, int score);
        void windowWin(std::string username, int min, int sec, int score);
        void setTextures(std::map<char, std::string>);
        void windowMenu(std::string gameName, std::string username);
        std::string windowUsername();

        /* USER INPUT */
        void userInput();
        bool buttonClose() const;
        bool buttonNextLib() const;
        bool buttonPrevLib() const;
        bool buttonNextGame() const;
        bool buttonPrevGame() const;
        bool buttonUp() const;
        bool buttonDown() const;
        bool buttonRight() const;
        bool buttonLeft() const;
        bool buttonSpace() const;
        bool buttonEnter() const;
        bool buttonEscape();
        bool buttonReset() const;
    protected:
    private:
        bool _windowState;
        WINDOW *_window;
        int _key;
        std::vector<std::string> _username_bg;
        std::vector<std::string> _menu_bg;
        std::vector<std::string> _game_bg;
        std::vector<std::string> _over_bg;
        std::vector<std::string> _win_bg;
        std::string _username;
};

#endif /* !LIBNCURSES_HPP_ */
