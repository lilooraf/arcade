/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include "defs.hpp"
#include "LibLoader.hpp"
#include "../include/ILib.hpp"
#include "../include/IGame.hpp"
#include "../include/Score.hpp"

class Core {
    public:
    typedef enum {
        USERNAME,
        MENU,
        GAME,
        OVER,
        WIN
    } e_state;
        Core(const std::string &, const std::string &);
        ~Core();

        /* GETTERS */
        ILib *getCurrentLib() const;
        IGame *getCurrentGame() const;
        std::vector<std::vector<char>> getTab() const;
        Score *getScore() const;

        /* SETTERS */
        void setCurrentLib(ILib *lib);
        void setState(e_state);
        void setTexmap(std::map <char, std::string>);

        /* OTHERS */
        std::vector<std::string> parseLibs(std::string);
        void nextLib();
        void prevLib();
        void basicInput();
        void usernameInput();
        void menuInput();
        void gameInput();
        void gameoverInput();
        void winInput();
        void checkState();
        void nextGame();
        void prevGame();
        std::vector<std::string> libsName();
        size_t setCounters(const std::string &current_path, std::vector<std::string> all_path);

    protected:
    private:
        ILib *_currentLib;
        IGame *_currentGame;
        std::vector<std::string> _libs;
        std::vector<std::string> _games;
        size_t _libCount;
        size_t _gameCount;
        std::map <char, std::string> _texMap;
        e_state _state;
        std::vector<std::string> _map;
        LibLoader<ILib *> _libLoader;
        LibLoader<IGame *> _gameLoader;
        Score *_score;
};

#endif /* !CORE_HPP_ */
