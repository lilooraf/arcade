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
    this->_sprite.setScale(sf::Vector2f(IMG_SIZE / (DISPLAY_H / TAB_H) , IMG_SIZE / (DISPLAY_H / TAB_H)));
}

LibSfml::~LibSfml()
{
    std::cout << "sfml close" << std::endl;
}

void LibSfml::test() const
{
    std::cout << "test sfml" << std::endl;
}

void LibSfml::windowOpen()
{
    this->_event = sf::Event();
    std::cout << "sfml window open" << std::endl;
    this->_windowState = true;
}

void LibSfml::windowClose()
{
    std::cout << "sfml window close" << std::endl;
    delete this->_window;
    this->_windowState = false;
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

void LibSfml::windowDisplay(std::vector<std::vector<char>> tab)
{
    sf::Transform t;
    std::map<char, sf::Texture>::iterator it;

    int y = 0;
    for (std::vector<char> list: tab) {
        int x = 0;
        for (char c : list) {
            it = this->_textures.find(c);
            if (it != this->_textures.end()) {
                this->_sprite.setTexture(it->second);
                this->_sprite.setPosition(x * TEX_SIZE, y * TEX_SIZE);
                this->_window->draw(this->_sprite);
            }
            x++;
        }
        y++;
    }
    this->_window->display();
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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        return true;
    return false;
}

bool LibSfml::buttonNextLib() const
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F3))
        return true;
    return false;
}

bool LibSfml::buttonPrevLib() const
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F2))
        return true;
    return false;
}


extern "C" {
    LibSfml *constuct() {
        return new LibSfml();
    }
}