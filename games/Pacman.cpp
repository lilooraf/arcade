/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** Pacman
*/

#include "Pacman.hpp"
#include <math.h>
#include <time.h>

Pacman::Pacman()
{
    this->_name = "Pacman";
    setMap();
    this->_player = new Player('r', 10000, 16000, RIGHT, 0);
    this->_blinky = new Player('J', 10000, 10000, RIGHT, 1);
    this->_pinky = new Player('P', 10000, 10000, UP, 1);
    this->_inky = new Player('I', 10000, 10000, DOWN, 1);
    this->_clyde = new Player('C', 10000, 10000, LEFT, 1);
}

Pacman::~Pacman()
{
    delete this->_blinky;
    delete this->_pinky;
    delete this->_inky;
    delete this->_player;
    delete this->_clyde;
}

void Pacman::resetGame()
{
    this->_player->reset('r', 10000, 16000, RIGHT, 0);
    this->_blinky->reset('J', 10000, 10000, RIGHT, 1);
    this->_pinky->reset('P', 10000, 10000, UP, 1);
    this->_inky->reset('I', 10000, 10000, DOWN, 1);
    this->_clyde->reset('C', 10000, 10000, LEFT, 1);
    this->_map.clear();
    setMap();
}

std::vector<std::string> Pacman::getMap() const
{
    return this->_map;
}

std::string Pacman::getName() const
{
    return this->_name;
}

void Pacman::setCore(Core *core)
{
    this->_core = core;
}

void Pacman::setMap()
{
    std::ifstream file("./assets/pacman_map");
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

void Pacman::ghostMove(Player *ghost)
{
    if (fmod((float)ghost->getX() / 1000, 1) == 0 && ghost->getDirect() == DOWN && (
    !checkDown('H', ghost) || !checkDown('Q', ghost) || !checkDown('S', ghost) ||
    !checkDown('A', ghost) || !checkDown('Z', ghost) || !checkDown('V', ghost) ||
    !checkDown('O', ghost)))
        ghost->setDirect(2 + rand() % 2);

    if (fmod((float)ghost->getY() / 1000, 1) == 0 && ghost->getDirect() == RIGHT && (
    !checkRight('H', ghost) || !checkRight('Q', ghost) || !checkRight('S', ghost) ||
    !checkRight('A', ghost) || !checkRight('Z', ghost) || !checkRight('V', ghost) ||
    !checkRight('O', ghost)))
        ghost->setDirect(rand() % 2);

    if (fmod((float)ghost->getX() / 1000, 1) == 0 && ghost->getDirect() == UP && (
    !checkUp('H', ghost) || !checkUp('Q', ghost) || !checkUp('S', ghost) ||
    !checkUp('A', ghost) || !checkUp('Z', ghost) || !checkUp('V', ghost) ||
    !checkUp('O', ghost)))
        ghost->setDirect(2 + rand() % 2);
    
    if (fmod((float)ghost->getY() / 1000, 1) == 0 && ghost->getDirect() == LEFT && (
    !checkLeft('H', ghost) || !checkLeft('Q', ghost) || !checkLeft('S', ghost) ||
    !checkLeft('A', ghost) || !checkLeft('Z', ghost) || !checkLeft('V', ghost) ||
    !checkLeft('O', ghost)))
        ghost->setDirect(rand() % 2);

    if (ghost->getDirect() == UP)
        moveUp(ghost);
    if (ghost->getDirect() == DOWN)
        moveDown(ghost);
    if (ghost->getDirect() == LEFT)
        moveLeft(ghost);
    if (ghost->getDirect() == RIGHT)
        moveRight(ghost);
}


void Pacman::collisionWall(Player *player)
{
    if (fmod((float)player->getX() / 1000, 1) == 0 && (player->getDirect_tmp() == DOWN &&
    checkDown('H', player) && checkDown('Q', player) && checkDown('S', player) &&
    checkDown('A', player) && checkDown('Z', player) && checkDown('V', player) &&
    checkDown('O', player)))
        player->setDirect(player->getDirect_tmp());

    if (fmod((float)player->getX() / 1000, 1) == 0 && (player->getDirect_tmp() == UP &&
    checkUp('H', player) && checkUp('Q', player) && checkUp('S', player) &&
    checkUp('A', player) && checkUp('Z', player) && checkUp('V', player) &&
    checkUp('O', player)))
        player->setDirect(player->getDirect_tmp());
    
    if (fmod((float)player->getY() / 1000, 1) == 0 && (player->getDirect_tmp() == LEFT &&
    checkLeft('H', player) && checkLeft('Q', player) && checkLeft('S', player) &&
    checkLeft('A', player) && checkLeft('Z', player) && checkLeft('V', player) &&
    checkLeft('O', player)))
        player->setDirect(player->getDirect_tmp());
    
    if (fmod((float)player->getY() / 1000, 1) == 0 && (player->getDirect_tmp() == RIGHT &&
    checkRight('H', player) && checkRight('Q', player) && checkRight('S', player) &&
    checkRight('A', player) && checkRight('Z', player) && checkRight('V', player) &&
    checkRight('O', player)))
        player->setDirect(player->getDirect_tmp());
}

void Pacman::collisionGhost(int x, int y, Player *ghost)
{
    if ((x + 500 > ghost->getX() && x - 500 < ghost->getX()) &
    (y + 500 > ghost->getY() && y - 500 < ghost->getY())) {
        if (this->_player->getType() == 1) {
            ghost->setPos(0, 0);
            ghost->setType(-1);
            std::thread thread = std::thread([ghost]() {
            sleep(10);
            ghost->setType(1);
            ghost->setPos(10000, 10000);
        });
        thread.detach();
        } else {
            this->_core->setState(Core::OVER);
            this->_core->getScore()->pauseTimer();
            this->_player->setPos(0, 0);
            this->_player->setType(-1);
        }
    }
}

void Pacman::collisionCoin(int x, int y)
{
    if (this->_map[(y / 1000)][(x / 1000)] == '.') {
        this->_core->getScore()->addScore(10);
        this->_map[(y / 1000)][(x / 1000)] = ' ';
    }
    if (this->_map[(y / 1000)][(x / 1000)] == 'o') {
        this->_core->getScore()->addScore(100);
        this->_map[(y / 1000)][(x / 1000)] = ' ';
        std::thread thread = std::thread([&]() {
            this->_player->setType(1);
            this->_blinky->setTex('B');
            this->_pinky->setTex('B');
            this->_inky->setTex('B');
            this->_clyde->setTex('B');
            sleep(10);
            this->_player->setType(0);
            this->_blinky->setTex('J');
            this->_pinky->setTex('P');
            this->_inky->setTex('I');
            this->_clyde->setTex('C');
        });
        thread.detach();
    }
}

void Pacman::playerMove(Player *player)
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

    collisionGhost(x, y, this->_blinky);
    collisionGhost(x, y, this->_pinky);
    collisionGhost(x, y, this->_inky);
    collisionGhost(x, y, this->_clyde);
    collisionCoin(x, y);
    collisionWall(player);

    if (player->getDirect() == UP) {
        player->setTex('u');
        moveUp(player);
    }
    if (player->getDirect() == DOWN) {
        player->setTex('d');
        moveDown(player);
    }
    if (player->getDirect() == LEFT) {
        player->setTex('l');
        moveLeft(player);
    }
    if (player->getDirect() == RIGHT) {
        player->setTex('r');
        moveRight(player);
    }
}

void Pacman::drawPlayer(Player *player)
{
    if (player->getType() != -1)
        this->_core->getCurrentLib()->windowDrawGame(
        player->getTex(), ((float)player->getX() / 1000),
        ((float)player->getY() / 1000));
}

void Pacman::refresh()
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
    ghostMove(this->_blinky);
    ghostMove(this->_pinky);
    ghostMove(this->_inky);
    ghostMove(this->_clyde);
    
    drawPlayer(this->_player);
    drawPlayer(this->_blinky);
    drawPlayer(this->_pinky);
    drawPlayer(this->_inky);
    drawPlayer(this->_clyde);

    this->_core->getCurrentLib()->windowDisplay();
    checkWin();
}


// Move

bool Pacman::checkUp(char c, Player *player)
{
    return (this->_map[((player->getY() - 1) / 1000)][(player->getX() / 1000)] != c);
}

bool Pacman::checkDown(char c, Player *player)
{
    return (this->_map[(player->getY() / 1000) + 1][(player->getX() / 1000)] != c);
}

bool Pacman::checkRight(char c, Player *player)
{
    return (this->_map[(player->getY() / 1000)][(player->getX() / 1000) + 1] != c);
}

bool Pacman::checkLeft(char c, Player *player)
{
    return (this->_map[(player->getY() / 1000)][((player->getX() - 1) / 1000)] != c);
}

void Pacman::moveUp(Player *player)
{
    if ((float)player->getY() / 1000 > 0 &&
    checkUp('H', player) && checkUp('V', player) && checkUp('O', player))
        player->setPos(player->getX(), player->getY() - SPEED);
}

void Pacman::moveDown(Player *player)
{
    if ((float)player->getY() / 1000 < TAB_H &&
    checkDown('H', player) && checkDown('V', player) && checkDown('O', player))
        player->setPos(player->getX(), player->getY() + SPEED);
}

void Pacman::moveRight(Player *player)
{
    if ((float)player->getX() / 1000 < TAB_W &&
    checkRight('H', player) && checkRight('V', player) && checkRight('O', player))
        player->setPos(player->getX() + SPEED, player->getY());

}

void Pacman::moveLeft(Player *player)
{
    if ((float)player->getX() / 1000 > 0 &&
    checkLeft('H', player) && checkLeft('V', player) && checkLeft('O', player))
        player->setPos(player->getX() - SPEED, player->getY());
}

void Pacman::checkWin()
{
    for (std::string str : this->_map)
        for (char c : str)
            if (c == '.' || c == 'o')
                return;
    this->_core->setState(Core::WIN);
    this->_core->getScore()->stopTimer();
    this->_player->setPos(0, 0);
    this->_player->setType(-1);
}

extern "C" {
    Pacman *constuct() {
        return new Pacman();
    }
}