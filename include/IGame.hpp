/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** IGame
*/

#ifndef IGAME_HPP_
#define IGAME_HPP_

#include "defs.hpp"
#include "Score.hpp"
//#include "Core.hpp"

class Core;

struct pos {
    int x;
    int y;
};

class IGame {
    public:
        virtual ~IGame() {};
        typedef enum {
            UP,
            DOWN,
            RIGHT,
            LEFT,
        } e_move;
        virtual std::vector<std::string> getMap() const = 0;
        virtual std::string getName() const = 0;
        virtual void setMap() {};
        virtual void move() {};
        virtual void moveUp() {};
        virtual void moveDown() {};
        virtual void moveRight() {};
        virtual void moveLeft() {};
        virtual void keyUp() {};
        virtual void keyDown() {};
        virtual void keyRight() {};
        virtual void keyLeft() {};
        virtual void checkWin() {};
        virtual void resetGame() {};
        virtual void refresh() {};
        virtual void setCore(Core *) {};
};

#endif /* !IGAME_HPP_ */
