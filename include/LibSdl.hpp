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
        void windowOpen();
        void windowClose();
        void windowClear();
        bool windowIsOpen() const;
        void windowDraw(char, float, float);
        void windowDrawBackground(std::string username, int min, int sec, int score);
        void windowDrawGame(char, float, float);
        void windowDrawScore(std::string username, int min, int sec, int score);
        void windowDisplay();
        void windowGameOver(std::string username, int min, int sec, int score);
        void windowWin(std::string username, int min, int sec, int score);
        void setTextures(std::map<char, std::string> texMap);
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
        SDL_Window *_window;
        SDL_Renderer *_renderer;
        SDL_Event _event;
        SDL_Rect _rect;
        SDL_Texture *_tex;
        SDL_Surface *screen;
        std::map <char, SDL_Texture *> _textures;
        SDL_Surface *_username_bg;
        SDL_Surface *_menu_bg;
        SDL_Surface *_game_bg;
        SDL_Surface *_over_bg;
        SDL_Surface *_win_bg;
        SDL_Texture *_background;
        TTF_Font *_font;
        SDL_Surface *_text;
        SDL_Texture *_textT;
        std::string _username;
};

#endif /* !LIBSDL_HPP_ */
