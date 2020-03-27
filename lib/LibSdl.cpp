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
    this->_window = SDL_CreateWindow("SDL Window", 0, 0, DISPLAY_W, DISPLAY_H, SDL_WINDOW_SHOWN);
    this->_renderer = SDL_CreateRenderer(this->_window, -1, 0);
    if (this->_renderer)
        SDL_SetRenderDrawColor(this->_renderer, 255, 255, 255, 255);
    if (this->_window == NULL)
        exit(84);
    this->_windowState = false;
    this->_rect.h = TEX_SIZE;
    this->_rect.w = TEX_SIZE;

}

LibSdl::~LibSdl()
{
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
    SDL_DestroyRenderer(this->_renderer);
    SDL_Quit();
    delete this;
}

bool LibSdl::windowIsOpen() const
{
    return this->_windowState;
}

void LibSdl::windowClear()
{
    SDL_RenderClear(this->_renderer);
}

void LibSdl::setTextures(std::map<char, std::string> texMap)
{
    SDL_Surface *surface;

    for (std::map<char, std::string>::iterator it = texMap.begin(); it != texMap.end(); ++it) {
        surface = IMG_Load(it->second.c_str());
        this->_textures.insert(std::make_pair(it->first, SDL_CreateTextureFromSurface(this->_renderer, surface)));
    }
}

void LibSdl::windowDisplay(std::vector<std::vector<char>> tab)
{
    int y = 0;
    std::map<char, SDL_Texture *>::iterator it;

    for (std::vector<char> list: tab) {
        int x = 0;
        for (char c : list) {
            this->_rect.x = x * TEX_SIZE;
            this->_rect.y = y * TEX_SIZE;
            it = this->_textures.find(c);
            if (it != this->_textures.end()) {
                this->_tex = it->second;
                SDL_RenderCopy(this->_renderer, this->_tex, NULL, &this->_rect);
            }
            x++;
        }
        y++;
    }
    SDL_RenderPresent(this->_renderer);
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