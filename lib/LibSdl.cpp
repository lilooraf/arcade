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
    setTextures();
}

LibSdl::~LibSdl()
{
    std::cout << "sdl close" << std::endl;
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
    this->_windowState = false;
}

bool LibSdl::windowIsOpen() const
{
    return this->_windowState;
}

void LibSdl::windowClear()
{
    SDL_RenderClear(this->_renderer);
}

void LibSdl::setTextures()
{
    SDL_Surface *surface;

    surface = IMG_Load("./assets/test.png");
    this->_textures.insert(std::make_pair('A', SDL_CreateTextureFromSurface(this->_renderer, surface)));
    
    surface = IMG_Load("./assets/test1.png");
    this->_textures.insert(std::make_pair('B', SDL_CreateTextureFromSurface(this->_renderer, surface)));

    // Add Textures :

    /* surface = IMG_Load("./assets/__TEXTURE_NAME__");
    this->_textures.insert(std::make_pair(__CHAR_IN_TAB__, SDL_CreateTextureFromSurface(this->_renderer, surface))); */

    SDL_FreeSurface(surface);
}

void LibSdl::windowDisplay(std::vector<std::vector<char>> tab)
{
    int y = 0;
    for (std::vector<char> list: tab) {
        int x = 0;
        for (char c : list) {
            this->_rect.x = x * TEX_SIZE;
            this->_rect.y = y * TEX_SIZE;
            this->_tex = this->_textures.find(c)->second;
            SDL_RenderCopy(this->_renderer, this->_tex, NULL, &this->_rect);
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