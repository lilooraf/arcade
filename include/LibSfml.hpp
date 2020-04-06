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
        virtual void setTextures(std::map<char, std::string>);
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
        sf::RenderWindow *_window;
        sf::Event _event;
        sf::Sprite _sprite;
        std::map<char, sf::Texture> _textures;
        sf::Texture _username_bg;
        sf::Texture _menu_bg;
        sf::Texture _game_bg;
        sf::Texture _over_bg;
        sf::Texture _win_bg;
        sf::Font _font;
        sf::Text _text;
        sf::Sprite _background;
        std::string _username;
};

#endif /* !LIBSFML_HPP_ */
