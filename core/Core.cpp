/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** Core
*/

#include "../include/Core.hpp"
#include "../include/IGame.hpp"

Core::Core(const std::string &lib_path, const std::string &game_path)
{
    this->_currentLib = this->_libLoader.load(lib_path);
    this->_currentLib->setTextures(this->_texMap);
    this->_libs = parseLibs("lib/");
    this->_libCount = setCounters(lib_path, this->_libs);
    this->_currentGame = _gameLoader.load(game_path);
    this->_currentGame->setCore(this);
    this->_games = parseLibs("games/");
    this->_gameCount = setCounters(game_path, this->_games);
    this->_state = USERNAME;
    this->_score = new Score();
}

Core::~Core()
{
    delete this->_score;
}

/* GETTERS */

ILib *Core::getCurrentLib() const
{
    return this->_currentLib;
}

IGame *Core::getCurrentGame() const
{
    return this->_currentGame;
}

Score *Core::getScore() const
{
    return this->_score;
}

/* SETTERS */

void Core::setState(e_state state)
{
    this->_state = state;
}

void Core::setCurrentLib(ILib *lib)
{
    delete(this->_currentLib);
    this->_currentLib = lib;
}

void Core::setTexmap(std::map <char, std::string>texMap)
{
    this->_texMap = texMap;
}

/* OTHERS */

void Core::nextLib()
{
    this->_currentLib->windowClose();
    this->_libLoader.close();
    this->_libCount = this->_libCount + 1 < this->_libs.size() ? this->_libCount + 1 : 0;
    this->_currentLib = this->_libLoader.load("lib/" + this->_libs.at(this->_libCount));
    this->_currentLib->setTextures(this->_texMap);
    this->_currentLib->windowOpen();
}

void Core::prevLib()
{
    this->_currentLib->windowClose();
    this->_libLoader.close();
    this->_libCount = this->_libCount == 0 ? this->_libs.size() - 1 : this->_libCount - 1;
    this->_currentLib = this->_libLoader.load("lib/" + this->_libs.at(this->_libCount));
    this->_currentLib->setTextures(this->_texMap);
    this->_currentLib->windowOpen();
}

void Core::nextGame()
{
    delete this->_currentGame;
    this->_gameLoader.close();
    this->_gameCount = this->_gameCount + 1 < this->_games.size() ? this->_gameCount + 1 : 0;
    this->_currentGame = this->_gameLoader.load("games/" + this->_games.at(this->_gameCount));
    this->_currentGame->setCore(this);
}

void Core::prevGame()
{
    delete this->_currentGame;
    this->_gameLoader.close();
    this->_gameCount = this->_gameCount == 0 ? this->_games.size() - 1 : this->_gameCount - 1;
    this->_currentGame = this->_gameLoader.load("games/" + this->_games.at(this->_gameCount));
    this->_currentGame->setCore(this);
}

void Core::basicInput()
{
    this->_currentLib->userInput();
    if (this->_currentLib->buttonClose()) {
        this->_currentLib->windowClose();
        this->_libLoader.close();
        exit(0);
    }
    if (this->_currentLib->buttonNextLib())
        nextLib();
    if (this->_currentLib->buttonPrevLib())
        prevLib();
    if (this->_state == USERNAME)
        usernameInput();
    if (this->_state == MENU)
        menuInput();
    if (this->_state == GAME)
        gameInput();
    if (this->_state == OVER) {
        gameoverInput();
    }
    if (this->_state == WIN)
        winInput();
}

void Core::usernameInput()
{
    if (this->_currentLib->buttonEnter())
        this->_state = MENU;
    if (this->_currentLib->buttonEscape()) {
        this->_currentLib->windowClose();
        this->_libLoader.close();
        exit(0);
    }
}

void Core::menuInput()
{
    if (this->_currentLib->buttonSpace()) {
        this->_state = GAME;
        if (this->_score->isStarted())
            this->_score->resumeTimer();
        else
            this->_score->startTimer();
    }
    if (this->_currentLib->buttonEscape()) {
        this->_currentLib->windowClose();
        this->_libLoader.close();
        exit(0);
    }
    if (this->_currentLib->buttonNextGame()) {
        this->_score->reset();
        nextGame();
    }
    if (this->_currentLib->buttonPrevGame()) {
        this->_score->reset();
        prevGame();
    }
}

void Core::gameInput()
{
    if (this->_currentLib->buttonEscape()) {
        this->_state = MENU;
        this->_score->pauseTimer();
    }
    if (this->_currentLib->buttonReset()) {
        this->_currentGame->resetGame();
        this->_score->reset();
    }
}

void Core::gameoverInput() {
    if (this->_currentLib->buttonSpace()) {
        this->_state = GAME;
        this->_currentGame->resetGame();
        this->_score->reset();
        this->_score->resetTimer();
        this->_score->startTimer();
    }
    if (this->_currentLib->buttonEscape()) {
        this->_currentLib->windowClose();
        this->_libLoader.close();
        exit(0);
    }
}

void Core::winInput() {
    if (this->_currentLib->buttonSpace()) {
        this->_state = GAME;
        this->_currentGame->resetGame();
        this->_score->reset();
        this->_score->resetTimer();
        this->_score->startTimer();
    }
    if (this->_currentLib->buttonEscape()) {
        this->_currentLib->windowClose();
        this->_libLoader.close();
        exit(0);
    }
}

std::vector<std::string> Core::parseLibs(std::string path)
{
    DIR *dir = opendir(path.c_str());
    if (!dir)
        exit(84);
    struct dirent *content = readdir(dir);
    std::vector<std::string> allLibs;
    for (std::string tmp; content; content = readdir(dir)) {
        tmp.assign(content->d_name);
        if (tmp.compare(0, strlen(LIB_NAME), LIB_NAME) == 0
        && tmp.compare(tmp.length() - 3, 3, ".so") == 0)
            allLibs.push_back(tmp);
    }
    closedir(dir);
    return allLibs;
}

void Core::checkState()
{
    if (this->_state == USERNAME)
        this->_score->setUsername(this->_currentLib->windowUsername());
    if (this->_state == MENU)
        this->_currentLib->windowMenu(this->_currentGame->getName(), this->_score->getUsername());
    if (this->_state == GAME)
        this->getCurrentGame()->refresh();
    if (this->_state == OVER)
        this->_currentLib->windowGameOver(this->_score->getUsername(), this->_score->getMin(), this->_score->getSec(), this->_score->getScore());
    if (this->_state == WIN)
        this->_currentLib->windowWin(this->_score->getUsername(), this->_score->getMin(), this->_score->getSec(), this->_score->getScore());
}

size_t Core::setCounters(const std::string &current_path, std::vector<std::string> all_path)
{
    for (size_t i = 0; i < all_path.size(); i++) {
        std::string tmp;
        tmp.assign(all_path.at(i).c_str());
        if (tmp.compare(current_path.substr(current_path.length() - tmp.length(), tmp.length())) == 0)
            return i;
    }
    return 0;
}