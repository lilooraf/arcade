/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** LibSdl
*/

#include "LibSdl.hpp"

LibSdl::LibSdl()
{
    SDL_Init(SDL_INIT_VIDEO);
    this->_window = SDL_CreateWindow("SDL Window", 0, 0, 1860, 1000, SDL_WINDOW_SHOWN);
    if (this->_window == NULL)
        exit(84);
    this->_windowState = false;
}

LibSdl::~LibSdl()
{
    SDL_DestroyWindow(this->_window);
    SDL_Quit();
    this->_windowState = false;
}

void LibSdl::test() const
{
    std::cout << "test sdl" << std::endl;
}

void LibSdl::windowOpen()
{
    SDL_PollEvent(&this->_event);
    std::cout << "sdl window open" << std::endl;
    this->_windowState = true;
}

void LibSdl::windowClose()
{
    std::cout << "sdl window close" << std::endl;
    SDL_DestroyWindow(this->_window);
    SDL_Quit();
    this->_windowState = false;
}

bool LibSdl::windowIsOpen() const
{
    std::cout << this->_windowState << std::endl;
    return this->_windowState;
}

void LibSdl::windowClear()
{
    
}

/* KEY INPUT */

void LibSdl::userInput()
{
    while (SDL_PollEvent(&this->_event));
}

bool LibSdl::buttonClose() const
{
    if (this->_event.type == SDL_KEYDOWN && this->_event.key.keysym.sym == SDLK_ESCAPE)
        return true;
    if (this->_event.type == SDL_QUIT)
        return true;
    return false;
}

bool LibSdl::buttonNextLib() const
{
    if (this->_event.type == SDL_KEYDOWN && this->_event.key.keysym.sym == SDLK_F3)
        return true;
    return false;
}

bool LibSdl::buttonPrevLib() const
{
    if (this->_event.type == SDL_KEYDOWN && this->_event.key.keysym.sym == SDLK_F2)
        return true;
    return false;
}

extern "C" {
    LibSdl *constuct() {
        return new LibSdl();
    }
}