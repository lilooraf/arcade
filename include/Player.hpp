/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

class Player {
    public:
        Player(char, int, int, int, int);
        ~Player();
        void reset(char, int, int, int, int);
        void setPos(int, int);
        void setTex(char);
        void setDirect(int);
        void setType(int);
        void setDirect_tmp(int);
        int getX();
        int getY();
        char getTex();
        int getType();
        int getDirect();
        int getDirect_tmp();

    protected:
    private:
        char _tex;
        int _x;
        int _y;
        int _direct;
        int _direct_tmp;
        int _type;
};

#endif /* !PLAYER_HPP_ */
