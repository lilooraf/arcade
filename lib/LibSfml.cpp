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
    this->_window->display();
    this->_window->clear();
}

void LibSfml::windowDisplay(std::vector<std::vector<char>> tab)
{

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