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
#include <map>
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
        void windowDisplay(std::vector<std::vector<char>>);
        void setTextures(std::map<char, std::string>);

        /* USER INPUT */
        void userInput();
        bool buttonClose() const;
        bool buttonNextLib() const;
        bool buttonPrevLib() const;
    protected:
    private:
        bool _windowState;
        SDL_Window *_window;
        SDL_Renderer *_renderer;
        SDL_Event _event;
        SDL_Rect _rect;
        SDL_Texture *_tex;
        std::map <char, SDL_Texture *> _textures;
};

#endif /* !LIBSDL_HPP_ */
