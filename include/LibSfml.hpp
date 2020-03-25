/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** LibSfml
*/

#ifndef LIBSFML_HPP_
#define LIBSFML_HPP_

#include "includeSFML.hpp"

#include "ILib.hpp"
#include "defs.hpp"

class LibSfml : public ILib {
    public:
        LibSfml();
        ~LibSfml();
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
        sf::RenderWindow *_window;
        sf::Event _event;
};

#endif /* !LIBSFML_HPP_ */
