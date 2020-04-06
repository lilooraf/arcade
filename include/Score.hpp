/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** Score
*/

#ifndef SCORE_HPP_
#define SCORE_HPP_

#include <ctime>
#include <chrono>
#include <thread>
#include "defs.hpp"

class Score {
    public:
        Score();
        ~Score();

        typedef enum {
            UP,
            DOWN,
        } e_state;

        /* GETTERS */
        std::string getUsername() const;
        int getScore() const;
        std::vector<int> getTimer() const;
        int getMin() const;
        int getSec() const;
        e_state getState() const;
        bool isStarted() const;
        bool isPaused() const;

        /* SETTERS */
        void setUsername(std::string username);
        void setScore(int);
        void addScore(int);
        void setTimer(e_state state, int min, int sec);
        void setMin(int min);
        void setSec(int sec);

        /* OTHERS */
        void resetScore();
        void resetTimer();
        void reset();
        void startTimer();
        void stopTimer();
        void pauseTimer();
        void resumeTimer();

    protected:
    private:
        std::string _username;
        int _score;
        int _min;
        int _sec;
        std::vector<int> _timer;
        e_state _state;
        bool _paused;
        bool _started;
        std::thread _thread;
};

#endif /* !SCORE_HPP_ */
