/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** LibSdl
*/

#ifndef LIBSDL_HPP_
#define LIBSDL_HPP_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "ILib.hpp"
#include "defs.hpp"

class LibSdl : public ILib {
    public:
        LibSdl();
        ~LibSdl();
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
        SDL_Window *_window;
        SDL_Event _event;
};

#endif /* !LIBSDL_HPP_ */
