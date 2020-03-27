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
        virtual void test() const {};
        virtual void windowOpen() {};
        virtual void windowClose() {};
        virtual void windowClear() {};
        virtual bool windowIsOpen() const = 0;
        virtual void windowDisplay(std::vector<std::vector<char>>) {};

        /* USER INPUT */
        virtual void userInput() {};
        virtual bool buttonClose() const = 0;
        virtual bool buttonNextLib() const = 0;
        virtual bool buttonPrevLib() const = 0;
    protected:
    private:
};

#endif /* !ILIB_HPP_ */
