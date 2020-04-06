/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** ILib
*/

#ifndef ILIB_HPP_
#define ILIB_HPP_

#include "defs.hpp"

class ILib {
    public:
        virtual ~ILib() {};
        virtual void windowOpen() {};
        virtual void windowClose() {};
        virtual void windowClear() {};
        virtual bool windowIsOpen() const = 0;
        virtual void windowDraw(char, float, float) {};
        virtual void windowDisplay() {};
        virtual void windowDrawBackground(std::string, int, int, int) {};
        virtual void windowDrawGame(char, float, float) {};
        virtual void windowDrawScore(std::string, int, int, int) {};
        virtual void windowGameOver(std::string, int, int, int) {};
        virtual void windowWin(std::string, int, int, int) {};
        virtual void windowMenu(std::string, std::string) {};
        virtual std::string windowUsername() = 0;
        virtual void setTextures(std::map<char, std::string>) {};

        /* USER INPUT */
        virtual void userInput() {};
        virtual bool buttonClose() const = 0;
        virtual bool buttonEscape() = 0;
        virtual bool buttonNextLib() const = 0;
        virtual bool buttonPrevLib() const = 0;
        virtual bool buttonNextGame() const = 0;
        virtual bool buttonPrevGame() const = 0;
        virtual bool buttonUp() const = 0;
        virtual bool buttonDown() const = 0;
        virtual bool buttonRight() const = 0;
        virtual bool buttonLeft() const = 0;
        virtual bool buttonSpace() const = 0;
        virtual bool buttonEnter() const = 0;
        virtual bool buttonReset() const = 0;
};

#endif /* !ILIB_HPP_ */
