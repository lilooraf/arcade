/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** Nibbler
*/

#ifndef NIBBLER_HPP_
#define NIBBLER_HPP_

#include "IGame.hpp"
#include "Core.hpp"
#include "Player.hpp"

class Nibbler : public IGame {
    public:
        Nibbler();
        ~Nibbler();
        bool checkUp(char c, Player *);
        void moveUp(Player *);
        bool checkDown(char c, Player *);
        void moveDown(Player *);
        bool checkRight(char c, Player *);
        void moveRight(Player *);
        bool checkLeft(char c, Player *);
        void moveLeft(Player *);
        void refresh();
        void playerMove(Player *);
        void drawPlayer(Player *);
        void resetGame();
        void collisionWall(Player *);
        void collisionBody();
        void collisionCoin(int, int);

        /* GETTERS */
        std::vector<std::string> getMap() const;
        char getMapChar();
        std::string getName() const;
        
        /* SETTERS */
        void setCore(Core *);
        void setMap();

        /* OTHERS */
        void checkWin() {};
    protected:
    private:
        std::string _name;
        Player *_player;
        std::vector<std::string> _map;
        Core *_core;
};

#endif /* !Nibbler_HPP_ */
