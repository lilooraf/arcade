/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** Pacman
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

#include "IGame.hpp"
#include "Core.hpp"
#include "Player.hpp"

class Pacman : public IGame {
    public:
        Pacman();
        ~Pacman();
        void resetGame();
        bool checkUp(char c, Player *);
        void moveUp(Player *);
        bool checkDown(char c, Player *);
        void moveDown(Player *);
        bool checkRight(char c, Player *);
        void moveRight(Player *);
        bool checkLeft(char c, Player *);
        void moveLeft(Player *);
        void collisionWall(Player *);
        void collisionGhost(int, int, Player *);
        void collisionCoin(int, int);
        void refresh();
        void playerMove(Player *);
        void ghostMove(Player *);
        void drawPlayer(Player *);
        void checkWin();

        /* GETTERS */
        std::vector<std::string> getMap() const;
        char getMapChar();
        std::string getName() const;
        
        /* SETTERS */
        void setCore(Core *);
        void setMap();

        /* OTHERS */
    protected:
    private:
        std::string _name;
        Player *_player;
        Player *_blinky;
        Player *_pinky;
        Player *_inky;
        Player *_clyde;
        std::vector<std::string> _map;
        Core *_core;
};

#endif /* !PACMAN_HPP_ */
