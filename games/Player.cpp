/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** Player
*/

#include "Player.hpp"

Player::Player(char c, int x, int y, int direct, int type)
{
    this->_tex = c;
    this->_x = x;
    this->_y = y;
    this->_direct = direct;
    this->_direct_tmp = direct;
    this->_type = type;
}

Player::~Player()
{
}

void Player::reset(char c, int x, int y, int direct, int type)
{
    this->_tex = c;
    this->_x = x;
    this->_y = y;
    this->_direct = direct;
    this->_direct_tmp = direct;
    this->_type = type;
}

void Player::setPos(int x, int y)
{
    this->_x = x;
    this->_y = y;
}

void Player::setTex(char c)
{
    this->_tex = c;
}

void Player::setDirect(int direct)
{
    this->_direct = direct;
}

void Player::setType(int type)
{
    this->_type = type;
}

void Player::setDirect_tmp(int direct)
{
    this->_direct_tmp = direct;
}

int Player::getDirect()
{
    return this->_direct;
}

int Player::getDirect_tmp()
{
    return this->_direct_tmp;
}

int Player::getType()
{
    return this->_type;
}

int Player::getX()
{
    return this->_x;
}

int Player::getY()
{
    return this->_y;
}

char Player::getTex()
{
    return this->_tex;
}
