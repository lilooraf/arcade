/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** Nibbler
*/

#include "Nibbler.hpp"
#include <math.h>
#include <time.h>

Nibbler::Nibbler()
{
    this->_name = "Nibbler";
    setMap();
    this->_player = new Player('N', 10000, 10000, RIGHT, 0);
}

Nibbler::~Nibbler()
{
    delete this->_player;
}

void Nibbler::resetGame()
{
    this->_player->reset('N', 10000, 10000, RIGHT, 0);
    this->_map.clear();
    setMap();
}

std::vector<std::string> Nibbler::getMap() const
{
    return this->_map;
}

std::string Nibbler::getName() const
{
    return this->_name;
}

void Nibbler::setCore(Core *core)
{
    this->_core = core;
}

void Nibbler::setMap()
{
    std::ifstream file("./assets/nibbler_map");
    std::string tmp;

    if (!file.is_open())
        return;
    while (std::getline(file, tmp)) {
        if (tmp.empty())
            continue;
        this->_map.push_back(tmp);
    }
    file.close();
}

void Nibbler::collisionWall(Player *player)
{
    if (fmod((float)player->getX() / 1000, 1) == 0 && (player->getDirect_tmp() == DOWN &&
    checkDown('H', player) && checkDown('Q', player) && checkDown('S', player) &&
    checkDown('A', player) && checkDown('Z', player) && checkDown('V', player) &&
    checkDown('O', player))) {
        player->setDirect(player->getDirect_tmp());
        if (!checkDown('5', player)) {
            this->_core->setState(Core::OVER);
            this->_core->getScore()->pauseTimer();
        }
    }

    if (fmod((float)player->getX() / 1000, 1) == 0 && (player->getDirect_tmp() == UP &&
    checkUp('H', player) && checkUp('Q', player) && checkUp('S', player) &&
    checkUp('A', player) && checkUp('Z', player) && checkUp('V', player) &&
    checkUp('O', player))) {
        player->setDirect(player->getDirect_tmp());
        if (!checkUp('5', player)) {
            this->_core->setState(Core::OVER);
            this->_core->getScore()->pauseTimer();
        }
    }
    
    if (fmod((float)player->getY() / 1000, 1) == 0 && (player->getDirect_tmp() == LEFT &&
    checkLeft('H', player) && checkLeft('Q', player) && checkLeft('S', player) &&
    checkLeft('A', player) && checkLeft('Z', player) && checkLeft('V', player) &&
    checkLeft('O', player))) {
        player->setDirect(player->getDirect_tmp());
        if (!checkLeft('5', player)) {
            this->_core->setState(Core::OVER);
            this->_core->getScore()->pauseTimer();
        }
    }
    
    if (fmod((float)player->getY() / 1000, 1) == 0 && (player->getDirect_tmp() == RIGHT &&
    checkRight('H', player) && checkRight('Q', player) && checkRight('S', player) &&
    checkRight('A', player) && checkRight('Z', player) && checkRight('V', player) &&
    checkRight('O', player))) {
        player->setDirect(player->getDirect_tmp());
        if (!checkRight('5', player)) {
            this->_core->setState(Core::OVER);
            this->_core->getScore()->pauseTimer();
        }
    }
}

void Nibbler::collisionCoin(int x, int y)
{
    if (this->_map[(y / 1000)][(x / 1000)] == '.') {
        std::thread thread = std::thread([x, y, this]() {
            usleep(250000);
            this->_map[(y / 1000)][(x / 1000)] = '5';
        });
        thread.detach();
    }
}

void Nibbler::playerMove(Player *player)
{
    int x = player->getX();
    int y = player->getY();

    if (this->_core->getCurrentLib()->buttonDown())
        player->setDirect_tmp(DOWN);
    if (this->_core->getCurrentLib()->buttonUp())
        player->setDirect_tmp(UP);
    if (this->_core->getCurrentLib()->buttonLeft())
        player->setDirect_tmp(LEFT);
    if (this->_core->getCurrentLib()->buttonRight())
        player->setDirect_tmp(RIGHT);

    collisionCoin(x, y);
    collisionWall(player);

    if (player->getDirect() == UP) {
        player->setTex('1');
        moveUp(player);
    }
    if (player->getDirect() == DOWN) {
        player->setTex('3');
        moveDown(player);
    }
    if (player->getDirect() == LEFT) {
        player->setTex('2');
        moveLeft(player);
    }
    if (player->getDirect() == RIGHT) {
        player->setTex('4');
        moveRight(player);
    }
}

void Nibbler::drawPlayer(Player *player)
{
    this->_core->getCurrentLib()->windowDrawGame(
    player->getTex(), ((float)player->getX() / 1000),
    ((float)player->getY() / 1000));
}

void Nibbler::refresh()
{
    this->_core->getCurrentLib()->
    windowDrawBackground(this->_core->getScore()->getUsername(),
    this->_core->getScore()->getMin(), this->_core->getScore()->getSec(),
    this->_core->getScore()->getScore());
    // MAP
    int y = 0;
    for (std::string list : this->_map) {
        int x = 0;
        for (char c : list) {
            this->_core->getCurrentLib()->windowDrawGame(c, x, y);
            x++;
        }
        y++;
    }
    // Player
    playerMove(this->_player);

    // Body
    drawPlayer(this->_player);

    this->_core->getCurrentLib()->windowDisplay();
}


// Move

bool Nibbler::checkUp(char c, Player *player)
{
    return (this->_map[((player->getY() - 1) / 1000)][(player->getX() / 1000)] != c);
}

bool Nibbler::checkDown(char c, Player *player)
{
    return (this->_map[(player->getY() / 1000) + 1][(player->getX() / 1000)] != c);
}

bool Nibbler::checkRight(char c, Player *player)
{
    return (this->_map[(player->getY() / 1000)][(player->getX() / 1000) + 1] != c);
}

bool Nibbler::checkLeft(char c, Player *player)
{
    return (this->_map[(player->getY() / 1000)][((player->getX() - 1) / 1000)] != c);
}

void Nibbler::moveUp(Player *player)
{
    if ((float)player->getY() / 1000 > 0 &&
    checkUp('H', player) && checkUp('V', player) && checkUp('O', player)) {
        player->setPos(player->getX(), player->getY() - SPEED);
        this->_core->getScore()->addScore(1);
    }
}

void Nibbler::moveDown(Player *player)
{
    if ((float)player->getY() / 1000 < TAB_H &&
    checkDown('H', player) && checkDown('V', player) && checkDown('O', player)) {
        player->setPos(player->getX(), player->getY() + SPEED);
        this->_core->getScore()->addScore(1);
    }
}

void Nibbler::moveRight(Player *player)
{
    if ((float)player->getX() / 1000 < TAB_W &&
    checkRight('H', player) && checkRight('V', player) && checkRight('O', player)) {
        player->setPos(player->getX() + SPEED, player->getY());
        this->_core->getScore()->addScore(1);
    }

}

void Nibbler::moveLeft(Player *player)
{
    if ((float)player->getX() / 1000 > 0 &&
    checkLeft('H', player) && checkLeft('V', player) && checkLeft('O', player)) {
        player->setPos(player->getX() - SPEED, player->getY());
        this->_core->getScore()->addScore(1);
    }
}


extern "C" {
    Nibbler *constuct() {
        return new Nibbler();
    }
}