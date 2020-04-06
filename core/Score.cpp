/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** Score
*/

#include "../include/Score.hpp"

Score::Score()
{
    this->_score = 0;
    this->_username = "";
    this->_timer.push_back(0);
    this->_timer.push_back(0);
    setTimer(UP, 0, 0);
}

Score::~Score()
{
    this->_thread.~thread();
}

/* GETTERS */

std::string Score::getUsername() const
{
    return this->_username;
}

int Score::getScore() const
{
    return this->_score;
}

std::vector<int> Score::getTimer() const
{
    return this->_timer;
}

int Score::getMin() const
{
    return *this->_timer.begin();
}

int Score::getSec() const
{
    return *this->_timer.end();
}

Score::e_state Score::getState() const
{
    return this->_state;
}

bool Score::isStarted() const
{
    return this->_started;
}

bool Score::isPaused() const
{
    return this->_paused;
}

/* SETTERS */

void Score::setUsername(std::string username)
{
    this->_username.erase();
    this->_username.assign(username);
}

void Score::setScore(int score)
{
    this->_score = score;
}

void Score::addScore(int add)
{
    this->_score += add;
}

void Score::setMin(int min)
{
    *this->_timer.begin() = min;
}

void Score::setSec(int sec)
{
    if (sec > 60)
        return;
    *this->_timer.end() = sec;
}

void Score::setTimer(e_state state, int min, int sec)
{
    this->_state = state;
    this->_min = min;
    this->_sec = sec;
    setMin(min);
    setSec(sec);
    this->_started = false;
    this->_paused = false;
}

/* OTHERS */

void Score::resetScore()
{
    this->_score = 0;
}

void Score::resetTimer()
{
    setTimer(this->_state, this->_min, this->_sec);
}

void Score::reset()
{
    stopTimer();
    resetScore();
}

void Score::startTimer()
{
    this->_started = true;
    this->_thread = std::thread([this]() {
        while (this->isStarted() && !this->isPaused()) {
            if (this->getState() == UP) {
                if (this->getSec() == 59) {
                    this->setSec(0);
                    this->setMin(this->getMin() + 1);
                }
                sleep(1);
                this->setSec(this->getSec() + 1);
            } else if (this->getState() == DOWN) {
                if (this->getMin() <= 0 && this->getSec() <= 0) {
                    this->pauseTimer();
                    break;
                }
                if (this->getSec() == 0) {
                    this->setSec(59);
                    this->setMin(this->getMin() - 1);
                }
                sleep(1);
                this->setSec(this->getSec() - 1);
            }
        }
        if (!this->isStarted()) {
            resetTimer();
            startTimer();
        }
    });
    this->_thread.detach();
}

void Score::pauseTimer()
{
    this->_paused = true;
}

void Score::resumeTimer()
{
    this->_paused = false;
    stopTimer();
    startTimer();
}

void Score::stopTimer()
{
    this->_started = false;
}