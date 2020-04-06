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
    this->_rect.h = TEX_SIZE * SCALE;
    this->_rect.w = TEX_SIZE * SCALE;
    this->_username_bg = IMG_Load("./assets/username_bg.png");
    this->_menu_bg = IMG_Load("./assets/menu_bg.png");
    this->_game_bg = IMG_Load("./assets/game_bg.png");
    this->_over_bg = IMG_Load("./assets/over_bg.png");
    this->_win_bg = IMG_Load("./assets/win_bg.png");
    this->_font = TTF_OpenFont("./assets/Roboto-Bold.ttf", 25);
}

LibSdl::~LibSdl()
{
    TTF_CloseFont(this->_font);
    TTF_Quit();
    SDL_DestroyWindow(this->_window);
    SDL_Quit();
    this->_windowState = false;
}

void LibSdl::windowOpen()
{
    SDL_PollEvent(&this->_event);
    this->_windowState = true;
}

void LibSdl::windowClose()
{
    TTF_CloseFont(this->_font);
    TTF_Quit();
    SDL_DestroyWindow(this->_window);
    SDL_Quit();
    this->_windowState = false;
}

bool LibSdl::windowIsOpen() const
{
    return this->_windowState;
}

void LibSdl::windowClear()
{
    SDL_PollEvent(&this->_event);
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

void LibSdl::windowDraw(char c, float x, float y)
{
    std::map<char, SDL_Texture *>::iterator it;

    this->_rect.x = x * TEX_SIZE * SCALE;
    this->_rect.y = y * TEX_SIZE * SCALE;
    it = this->_textures.find(c);
    if (it != this->_textures.end()) {
        this->_tex = it->second;
        SDL_RenderCopy(this->_renderer, this->_tex, NULL, &this->_rect);
    }
}

void LibSdl::windowDrawBackground(std::string username, int min, int sec, int score)
{
    this->_background = SDL_CreateTextureFromSurface(this->_renderer, this->_game_bg);
    SDL_RenderCopy(this->_renderer, this->_background, NULL, NULL);
    SDL_DestroyTexture(this->_background);
    windowDrawScore(username, min, sec, score);
}

void LibSdl::windowDrawGame(char c, float x, float y)
{
    windowDraw(c, x + 9.5, y + 3.4);
}

void LibSdl::windowDrawScore(std::string username, int min, int sec, int score)
{
    std::string stimer = "Timer = ";
    stimer.append(std::to_string(min).append(":").append(std::to_string(sec)));
    std::string sscore = "Score = ";
    sscore.append(std::to_string(score));
    int texW = 0;
    int texH = 0;

    this->_text = TTF_RenderText_Solid(this->_font, username.c_str(), {0, 0, 0, 0});
    this->_tex = SDL_CreateTextureFromSurface(this->_renderer, this->_text);
    SDL_QueryTexture(this->_tex, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect = {490, 360, texW, texH};
    SDL_RenderCopy(this->_renderer, this->_tex, NULL, &dstrect);

    this->_text = TTF_RenderText_Solid(this->_font, stimer.c_str(), {0, 0, 0, 0});
    this->_tex = SDL_CreateTextureFromSurface(this->_renderer, this->_text);
    SDL_QueryTexture(this->_tex, NULL, NULL, &texW, &texH);
    dstrect = {490, 360, texW, texH};
    SDL_RenderCopy(this->_renderer, this->_tex, NULL, &dstrect);

    this->_text = TTF_RenderText_Solid(this->_font, sscore.c_str(), {0, 0, 0, 0});
    this->_tex = SDL_CreateTextureFromSurface(this->_renderer, this->_text);
    SDL_QueryTexture(this->_tex, NULL, NULL, &texW, &texH);
    dstrect = {490, 360, texW, texH};
    SDL_RenderCopy(this->_renderer, this->_tex, NULL, &dstrect);

    SDL_DestroyTexture(this->_background);
    SDL_DestroyTexture(this->_tex);
    SDL_FreeSurface(this->_text);
}

void LibSdl::windowGameOver(std::string username, int min, int sec, int score)
{
    std::string stimer = "Timer = ";
    stimer.append(std::to_string(min).append(":").append(std::to_string(sec)));
    std::string sscore = "Score = ";
    sscore.append(std::to_string(score));
    int texW = 0;
    int texH = 0;

    this->_background = SDL_CreateTextureFromSurface(this->_renderer, this->_over_bg);
    SDL_RenderCopy(this->_renderer, this->_background, NULL, NULL);

    this->_text = TTF_RenderText_Solid(this->_font, username.c_str(), {0, 0, 0, 0});
    this->_tex = SDL_CreateTextureFromSurface(this->_renderer, this->_text);
    SDL_QueryTexture(this->_tex, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect = {470, 320, texW, texH};
    SDL_RenderCopy(this->_renderer, this->_tex, NULL, &dstrect);

    this->_text = TTF_RenderText_Solid(this->_font, stimer.c_str(), {0, 0, 0, 0});
    this->_tex = SDL_CreateTextureFromSurface(this->_renderer, this->_text);
    SDL_QueryTexture(this->_tex, NULL, NULL, &texW, &texH);
    dstrect = {470, 360, texW, texH};
    SDL_RenderCopy(this->_renderer, this->_tex, NULL, &dstrect);

    this->_text = TTF_RenderText_Solid(this->_font, sscore.c_str(), {0, 0, 0, 0});
    this->_tex = SDL_CreateTextureFromSurface(this->_renderer, this->_text);
    SDL_QueryTexture(this->_tex, NULL, NULL, &texW, &texH);
    dstrect = {470, 420, texW, texH};
    SDL_RenderCopy(this->_renderer, this->_tex, NULL, &dstrect);

    SDL_DestroyTexture(this->_background);
    SDL_RenderPresent(this->_renderer);
    SDL_DestroyTexture(this->_tex);
    SDL_FreeSurface(this->_text);
}

void LibSdl::windowWin(std::string username, int min, int sec, int score)
{
    std::string stimer = "Timer = ";
    stimer.append(std::to_string(min).append(":").append(std::to_string(sec)));
    std::string sscore = "Score = ";
    sscore.append(std::to_string(score));
    int texW = 0;
    int texH = 0;

    this->_background = SDL_CreateTextureFromSurface(this->_renderer, this->_win_bg);
    SDL_RenderCopy(this->_renderer, this->_background, NULL, NULL);

    this->_text = TTF_RenderText_Solid(this->_font, username.c_str(), {0, 0, 0, 0});
    this->_tex = SDL_CreateTextureFromSurface(this->_renderer, this->_text);
    SDL_QueryTexture(this->_tex, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect = {470, 320, texW, texH};
    SDL_RenderCopy(this->_renderer, this->_tex, NULL, &dstrect);

    this->_text = TTF_RenderText_Solid(this->_font, stimer.c_str(), {0, 0, 0, 0});
    this->_tex = SDL_CreateTextureFromSurface(this->_renderer, this->_text);
    SDL_QueryTexture(this->_tex, NULL, NULL, &texW, &texH);
    dstrect = {470, 360, texW, texH};
    SDL_RenderCopy(this->_renderer, this->_tex, NULL, &dstrect);

    this->_text = TTF_RenderText_Solid(this->_font, sscore.c_str(), {0, 0, 0, 0});
    this->_tex = SDL_CreateTextureFromSurface(this->_renderer, this->_text);
    SDL_QueryTexture(this->_tex, NULL, NULL, &texW, &texH);
    dstrect = {470, 420, texW, texH};
    SDL_RenderCopy(this->_renderer, this->_tex, NULL, &dstrect);

    SDL_DestroyTexture(this->_background);
    SDL_RenderPresent(this->_renderer);
    SDL_DestroyTexture(this->_tex);
    SDL_FreeSurface(this->_text);
}

void LibSdl::windowDisplay()
{
    SDL_RenderPresent(this->_renderer);
}

void LibSdl::windowMenu(std::string gameName, std::string username)
{
    int texW = 0;
    int texH = 0;
    this->_background = SDL_CreateTextureFromSurface(this->_renderer, this->_menu_bg);
    SDL_RenderCopy(this->_renderer, this->_background, NULL, NULL);
    this->_text = TTF_RenderText_Solid(this->_font, gameName.c_str(), {0, 0, 0, 0});
    this->_tex = SDL_CreateTextureFromSurface(this->_renderer, this->_text);
    SDL_QueryTexture(this->_tex, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect = {490, 360, texW, texH};
    SDL_RenderCopy(this->_renderer, this->_tex, NULL, &dstrect);
    SDL_DestroyTexture(this->_tex);
    this->_text = TTF_RenderText_Solid(this->_font, username.c_str(), {0, 0, 0, 0});
    this->_tex = SDL_CreateTextureFromSurface(this->_renderer, this->_text);
    SDL_QueryTexture(this->_tex, NULL, NULL, &texW, &texH);
    dstrect = {490, 585, texW, texH};
    SDL_RenderCopy(this->_renderer, this->_tex, NULL, &dstrect);
    SDL_RenderPresent(this->_renderer);
    SDL_DestroyTexture(this->_background);
    SDL_DestroyTexture(this->_tex);
    SDL_FreeSurface(this->_text);
}

std::string LibSdl::windowUsername()
{
    int texW = 0;
    int texH = 0;

    if (this->_event.type == SDL_TEXTINPUT)
        if (this->_username.size() <= 8 && (*this->_event.text.text >= 'a' && *this->_event.text.text <= 'z'))
            this->_username += *this->_event.text.text;
    if (this->_event.type == SDL_KEYDOWN)
        if (this->_event.key.keysym.sym == SDLK_BACKSPACE && this->_username.size() > 0)
            this->_username.pop_back();

    this->_text = TTF_RenderText_Solid(_font, this->_username.c_str(), {1, 1, 1, 255});
    this->_textT = SDL_CreateTextureFromSurface(this->_renderer, this->_text);
    this->_background = SDL_CreateTextureFromSurface(this->_renderer, this->_username_bg);
    SDL_RenderCopy(this->_renderer, this->_background, NULL, NULL);
    SDL_QueryTexture(this->_textT, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect = { 490, 360, texW, texH };
    SDL_RenderCopy(this->_renderer, this->_textT, NULL, &dstrect);
    SDL_RenderPresent(this->_renderer);
    SDL_DestroyTexture(this->_background);
    SDL_DestroyTexture(this->_textT);
    SDL_FreeSurface(this->_text);
    return this->_username;
}

/* KEY INPUT */

void LibSdl::userInput()
{
    while (SDL_PollEvent(&this->_event));
}

bool LibSdl::buttonClose() const
{
    if (this->_event.type == SDL_QUIT)
        return true;
    return false;
}

bool LibSdl::buttonNextLib() const
{
    if (this->_event.type == SDL_KEYDOWN && this->_event.key.keysym.sym == SDLK_F3) {
        for (int i = 0; i < 100000000; i++);
        return true;
    }
    return false;
}

bool LibSdl::buttonPrevLib() const
{
    if (this->_event.type == SDL_KEYDOWN && this->_event.key.keysym.sym == SDLK_F2) {
        for (int i = 0; i < 100000000; i++);
        return true;
    }
    return false;
}

bool LibSdl::buttonNextGame() const
{
    if (this->_event.type == SDL_KEYDOWN && this->_event.key.keysym.sym == SDLK_F5) {
        for (int i = 0; i < 100000000; i++);
        return true;
    }
    return false;
}

bool LibSdl::buttonPrevGame() const
{
    if (this->_event.type == SDL_KEYDOWN && this->_event.key.keysym.sym == SDLK_F4) {
        for (int i = 0; i < 100000000; i++);
        return true;
    }
    return false;
}

bool LibSdl::buttonUp() const
{
    if ((this->_event.type == SDL_KEYDOWN && this->_event.key.keysym.sym == SDLK_UP) || (this->_event.type == SDL_TEXTINPUT && *this->_event.text.text == 'z')) {
        for (int i = 0; i < 1000000; i++);
        return true;
    }
    return false;
}

bool LibSdl::buttonDown() const
{
    if ((this->_event.type == SDL_KEYDOWN && this->_event.key.keysym.sym == SDLK_DOWN) || (this->_event.type == SDL_TEXTINPUT && *this->_event.text.text == 's')) {
        for (int i = 0; i < 1000000; i++);
        return true;
    }
    return false;
}

bool LibSdl::buttonRight() const
{
    if ((this->_event.type == SDL_KEYDOWN && this->_event.key.keysym.sym == SDLK_RIGHT) || (this->_event.type == SDL_TEXTINPUT && *this->_event.text.text == 'd')) {
        for (int i = 0; i < 1000000; i++);
        return true;
    }
    return false;
}

bool LibSdl::buttonLeft() const
{
    if ((this->_event.type == SDL_KEYDOWN && this->_event.key.keysym.sym == SDLK_LEFT) || (this->_event.type == SDL_TEXTINPUT && *this->_event.text.text == 'q')) {
        for (int i = 0; i < 1000000; i++);
        return true;
    }
    return false;
}

bool LibSdl::buttonSpace() const
{
    if (this->_event.type == SDL_TEXTINPUT && *this->_event.text.text == ' ') {
        for (int i = 0; i < 1000000; i++);
        return true;
    }
    return false;
}

bool LibSdl::buttonEnter() const
{
    if (this->_event.type == SDL_KEYDOWN && this->_event.key.keysym.sym == SDLK_RETURN) {
        for (int i = 0; i < 1000000; i++);
        return true;
    }
    return false;
}

bool LibSdl::buttonEscape()
{
    if (this->_event.type == SDL_KEYDOWN && this->_event.key.keysym.sym == SDLK_ESCAPE) {
        for (int i = 0; i < 100000000; i++);
        return true;
    }
    return false;
}

bool LibSdl::buttonReset() const
{
    if (this->_event.type == SDL_TEXTINPUT && *this->_event.text.text == 'r') {
        for (int i = 0; i < 1000000; i++);
        return true;
    }
    return false;
}

extern "C" {
    LibSdl *constuct() {
        return new LibSdl();
    }
}