/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** LibSfml
*/

#include "LibSfml.hpp"

LibSfml::LibSfml()
{
    this->_window = new sf::RenderWindow(sf::VideoMode(DISPLAY_W, DISPLAY_H), "SFML Window");
    this->_window->setFramerateLimit(144);
    this->_windowState = false;
    this->_sprite.setTextureRect(sf::IntRect(0, 0, IMG_SIZE, IMG_SIZE));
    this->_sprite.setScale(sf::Vector2f(SCALE , SCALE));
    this->_username_bg.loadFromFile("./assets/username_bg.png");
    this->_menu_bg.loadFromFile("./assets/menu_bg.png");
    this->_game_bg.loadFromFile("./assets/game_bg.png");
    this->_over_bg.loadFromFile("./assets/over_bg.png");
    this->_win_bg.loadFromFile("./assets/win_bg.png");
    this->_font.loadFromFile("./assets/Roboto-Bold.ttf");
}

LibSfml::~LibSfml()
{
    delete this->_window;
    this->_windowState = false;
}

void LibSfml::windowOpen()
{
    this->_event = sf::Event();
    this->_windowState = true;
}

void LibSfml::windowClose()
{
    this->_window->close();
    delete this;
}

bool LibSfml::windowIsOpen() const
{
    return this->_windowState;
}

void LibSfml::windowClear()
{
    this->_window->clear();
}

void LibSfml::setTextures(std::map<char, std::string> texMap)
{
    sf::Texture texture;

    for (std::map<char, std::string>::iterator it = texMap.begin(); it != texMap.end(); ++it) {
        texture.loadFromFile(it->second);
        this->_textures.insert(std::make_pair(it->first,texture));
    }
}

void LibSfml::windowDraw(char c, float x, float y)
{
    sf::Transform t;
    std::map<char, sf::Texture>::iterator it;

    for (int i = 0; i < 100; i++);
    it = this->_textures.find(c);
    if (it != this->_textures.end()) {
        this->_sprite.setTexture(it->second);
        this->_sprite.setPosition(x  * IMG_SIZE * SCALE, y * IMG_SIZE * SCALE);
        this->_window->draw(this->_sprite);
    }
}

void LibSfml::windowDrawBackground(std::string username, int min, int sec, int score)
{
    this->_background.setTexture(this->_game_bg);
    this->_window->draw(this->_background);
    windowDrawScore(username, min, sec, score);
}

void LibSfml::windowDrawGame(char c, float x, float y)
{
    windowDraw(c, x + 9.5, y + 3.4);
}

void LibSfml::windowDrawScore(std::string username, int min, int sec, int score)
{
    std::string stimer = "Timer = ";
    stimer.append(std::to_string(min).append(":").append(std::to_string(sec)));
    std::string sscore = "Score = ";
    sscore.append(std::to_string(score));

    this->_text.setString(username);
    this->_text.setFillColor(sf::Color::Black);
    this->_text.setFont(this->_font);
    this->_text.setStyle(this->_text.Bold);
    this->_text.setCharacterSize(25);
    this->_text.setPosition(890, 250);
    this->_window->draw(this->_text);

    this->_text.setString(stimer.c_str());
    this->_text.setFillColor(sf::Color::Black);
    this->_text.setFont(this->_font);
    this->_text.setStyle(this->_text.Bold);
    this->_text.setCharacterSize(25);
    this->_text.setPosition(890, 350);
    this->_window->draw(this->_text);

    this->_text.setString(sscore.c_str());
    this->_text.setFillColor(sf::Color::Black);
    this->_text.setFont(this->_font);
    this->_text.setStyle(this->_text.Bold);
    this->_text.setCharacterSize(25);
    this->_text.setPosition(890, 450);
    this->_window->draw(this->_text);
}

void LibSfml::windowGameOver(std::string username, int min, int sec, int score)
{
    std::string stimer = "Timer = ";
    stimer.append(std::to_string(min).append(":").append(std::to_string(sec)));
    std::string sscore = "Score = ";
    sscore.append(std::to_string(score));

    this->_background.setTexture(this->_over_bg);
    this->_window->draw(this->_background); 

    this->_text.setString(username);
    this->_text.setFillColor(sf::Color::Black);
    this->_text.setFont(this->_font);
    this->_text.setStyle(this->_text.Bold);
    this->_text.setCharacterSize(25);
    this->_text.setPosition(470, 320);
    this->_window->draw(this->_text);

    this->_text.setString(stimer.c_str());
    this->_text.setFillColor(sf::Color::Black);
    this->_text.setFont(this->_font);
    this->_text.setStyle(this->_text.Bold);
    this->_text.setCharacterSize(25);
    this->_text.setPosition(470, 360);
    this->_window->draw(this->_text);

    this->_text.setString(sscore.c_str());
    this->_text.setFillColor(sf::Color::Black);
    this->_text.setFont(this->_font);
    this->_text.setStyle(this->_text.Bold);
    this->_text.setCharacterSize(25);
    this->_text.setPosition(470, 420);
    this->_window->draw(this->_text);

    this->_window->display();
}

void LibSfml::windowWin(std::string username, int min, int sec, int score)
{
    std::string stimer = "Timer = ";
    stimer.append(std::to_string(min).append(":").append(std::to_string(sec)));
    std::string sscore = "Score = ";
    sscore.append(std::to_string(score));

    this->_background.setTexture(this->_win_bg);
    this->_window->draw(this->_background); 

    this->_text.setString(username);
    this->_text.setFillColor(sf::Color::Black);
    this->_text.setFont(this->_font);
    this->_text.setStyle(this->_text.Bold);
    this->_text.setCharacterSize(25);
    this->_text.setPosition(470, 320);
    this->_window->draw(this->_text);

    this->_text.setString(stimer.c_str());
    this->_text.setFillColor(sf::Color::Black);
    this->_text.setFont(this->_font);
    this->_text.setStyle(this->_text.Bold);
    this->_text.setCharacterSize(25);
    this->_text.setPosition(470, 360);
    this->_window->draw(this->_text);

    this->_text.setString(sscore.c_str());
    this->_text.setFillColor(sf::Color::Black);
    this->_text.setFont(this->_font);
    this->_text.setStyle(this->_text.Bold);
    this->_text.setCharacterSize(25);
    this->_text.setPosition(470, 420);
    this->_window->draw(this->_text);

    this->_window->display();
}

void LibSfml::windowDisplay()
{

    this->_window->display();
}

void LibSfml::windowMenu(std::string gameName, std::string username)
{
    this->_text.setString(gameName.c_str());
    this->_text.setFillColor(sf::Color::Black);
    this->_text.setFont(this->_font);
    this->_text.setStyle(this->_text.Bold);
    this->_text.setCharacterSize(25);
    this->_text.setPosition(490, 360);

    this->_background.setTexture(this->_menu_bg);
    this->_window->draw(this->_background);
    this->_window->draw(this->_text);
    this->_text.setString(username.c_str());
    this->_text.setFillColor(sf::Color::Black);
    this->_text.setPosition(490, 585);
    this->_window->draw(this->_text);
    this->_window->display();
}

std::string LibSfml::windowUsername()
{
    if (this->_event.type == sf::Event::TextEntered) {
        if (this->_event.text.unicode == 8 && this->_username.size() > 0)
            this->_username.pop_back();
        else if (this->_username.size() <= 8 && (this->_event.text.unicode >= 'a' && this->_event.text.unicode <= 'z'))
            this->_username += (char)_event.text.unicode;
    }
    this->_text.setString(this->_username.c_str());
    this->_text.setFillColor(sf::Color::Black);
    this->_text.setFont(this->_font);
    this->_text.setStyle(this->_text.Bold);
    this->_text.setCharacterSize(25);
    this->_text.setPosition(490, 360);

    this->_background.setTexture(this->_username_bg);
    this->_window->draw(this->_background);
    this->_window->draw(this->_text);
    this->_window->display();
    return this->_username;
}

/* KEY INPUT */

void LibSfml::userInput()
{
    while (this->_window->pollEvent(this->_event));
}

bool LibSfml::buttonClose() const
{
    if (this->_event.type == sf::Event::Closed)
        return true;
    return false;
}

bool LibSfml::buttonNextLib() const
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F3)) {
        for (int i = 0; i < 100000000; i++);
        return true;
    }
    return false;
}

bool LibSfml::buttonPrevLib() const
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F2)) {
        for (int i = 0; i < 100000000; i++);
        return true;
    }
    return false;
}

bool LibSfml::buttonNextGame() const
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F5)) {
        for (int i = 0; i < 100000000; i++);
        return true;
    }
    return false;
}

bool LibSfml::buttonPrevGame() const
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F4)) {
        for (int i = 0; i < 100000000; i++);
        return true;
    }
    return false;
}

bool LibSfml::buttonUp() const
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        for (int i = 0; i < 1000000; i++);
        return true;
    }
    return false;
}

bool LibSfml::buttonDown() const
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        for (int i = 0; i < 1000000; i++);
        return true;
    }
    return false;
}

bool LibSfml::buttonRight() const
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        for (int i = 0; i < 1000000; i++);
        return true;
    }
    return false;
}

bool LibSfml::buttonLeft() const
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        for (int i = 0; i < 1000000; i++);
        return true;
    }
    return false;
}

bool LibSfml::buttonSpace() const
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        for (int i = 0; i < 1000000; i++);
        return true;
    }
    return false;
}

bool LibSfml::buttonEnter() const
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
        for (int i = 0; i < 1000000; i++);
        return true;
    }
    return false;
}

bool LibSfml::buttonEscape()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        for (int i = 0; i < 100000000; i++);
        return true;
    }
    return false;
}

bool LibSfml::buttonReset() const
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
        for (int i = 0; i < 10000000; i++);
        return true;
    }
    return false;
}

extern "C" {
    LibSfml *constuct() {
        return new LibSfml();
    }
}