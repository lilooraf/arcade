/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** LibNcurses
*/

#include "LibNcurses.hpp"

LibNcurses::LibNcurses()
{
    std::ifstream username("./assets/ncurses_username_bg");
    std::ifstream menu("./assets/ncurses_menu_bg");
    std::ifstream game("./assets/ncurses_game_bg");
    std::ifstream over("./assets/ncurses_over_bg");
    std::ifstream win("./assets/ncurses_win_bg");
    std::string tmp;
    while (std::getline(username, tmp))
        this->_username_bg.push_back(tmp);
    username.close();
    while (std::getline(menu, tmp))
        this->_menu_bg.push_back(tmp);
    menu.close();
    while (std::getline(game, tmp))
        this->_game_bg.push_back(tmp);
    game.close();
    while (std::getline(over, tmp))
        this->_over_bg.push_back(tmp);
    over.close();
    while (std::getline(win, tmp))
        this->_win_bg.push_back(tmp);
    win.close();
    this->_key = -1;
    this->_windowState = false;
}

LibNcurses::~LibNcurses()
{
    this->_windowState = false;
    endwin();
}

void LibNcurses::windowOpen()
{
    this->_window = initscr();
    nodelay(this->_window, true);
    noecho();
    keypad(this->_window, true);
    refresh();
    this->_windowState = true;
}

void LibNcurses::windowClose()
{
    endwin();
    this->_windowState = false;
    delete this;
}

void LibNcurses::windowClear()
{
    usleep(10000);
    wrefresh(this->_window);
}

bool LibNcurses::windowIsOpen() const
{
    return this->_windowState;
}

void LibNcurses::windowDraw(char c, float x, float y)
{
    curs_set(0);
    std::string str = " ";
    str[0] = c;
    mvprintw((int)y, (int)x, str.c_str());
}

void LibNcurses::windowDrawBackground(std::string username, int min, int sec, int score)
{
    wclear(this->_window);
    for (size_t i = 0; i < this->_game_bg.size(); i++)
        mvprintw(i + 1, 1, this->_game_bg.at(i).c_str());
    windowDrawScore(username, min, sec, score);
}

void LibNcurses::windowDrawGame(char c, float x, float y)
{
    if (c == 'H' || c == 'V' || c == 'A' || c == 'Z' || c == 'S' || c == 'Q')
        c = '#';
    if (c == '1' || c == '2' || c == '3' || c == '4')
        c = 'S';
    if (c == 'r' || c == 'l' || c == 'u' || c == 'd')
        c = 'C';
    if (c == '5')
        c = 's';
    windowDraw(c, x + 29, y + 5);
}

void LibNcurses::windowDrawScore(std::string username, int min, int sec, int score)
{
    std::string stimer = "Timer = ";
    stimer.append(std::to_string(min).append(":").append(std::to_string(sec)));
    std::string sscore = "Score = ";
    sscore.append(std::to_string(score));

    mvprintw(10, 60, username.c_str());
    mvprintw(15, 60, stimer.c_str());
    mvprintw(20, 60, sscore.c_str());
}

void LibNcurses::windowMenu(std::string gameName, std::string username)
{
    wclear(this->_window);
    curs_set(0);
    wclear(this->_window);
    for (size_t i = 0; i < this->_menu_bg.size(); i++)
        mvprintw(i + 1, 1, this->_menu_bg.at(i).c_str());
    mvprintw(11, 47, gameName.c_str());
    mvprintw(15, 47, username.c_str());
}
std::string LibNcurses::windowUsername()
{
    curs_set(0);
    for (size_t i = 0; i < this->_username_bg.size(); i++)
        mvprintw(i + 1, 1, this->_username_bg.at(i).c_str());
    if (this->_key > 0 && this->_key != 32 && this->_key != 27) {
        if (this->_key == KEY_BACKSPACE && this->_username.size() > 0)
            this->_username.pop_back();
        else if (this->_username.size() <= 8 && (this->_key >= 97 && this->_key <= 122))
            this->_username += (char)this->_key;
    }
    mvprintw(11, 46, this->_username.c_str());
    return this->_username;
}

void LibNcurses::windowGameOver(std::string username, int min, int sec, int score)
{
    wclear(this->_window);
    for (size_t i = 0; i < this->_over_bg.size(); i++)
        mvprintw(i + 1, 1, this->_over_bg.at(i).c_str());
    std::string stimer = "Timer = ";
    stimer.append(std::to_string(min).append(":").append(std::to_string(sec)));
    std::string sscore = "Score = ";
    sscore.append(std::to_string(score));

    mvprintw(11, 45, username.c_str());
    mvprintw(12, 45, stimer.c_str());
    mvprintw(13, 45, sscore.c_str());
}

void LibNcurses::windowWin(std::string username, int min, int sec, int score)
{
    wclear(this->_window);
    for (size_t i = 0; i < this->_win_bg.size(); i++)
        mvprintw(i + 1, 1, this->_win_bg.at(i).c_str());
    std::string stimer = "Timer = ";
    stimer.append(std::to_string(min).append(":").append(std::to_string(sec)));
    std::string sscore = "Score = ";
    sscore.append(std::to_string(score));

    mvprintw(11, 45, username.c_str());
    mvprintw(12, 45, stimer.c_str());
    mvprintw(13, 45, sscore.c_str());
}

void LibNcurses::setTextures(std::map<char, std::string>)
{
    
}

/* USER INPUT */

void LibNcurses::userInput()
{
    this->_key = getch();
}

bool LibNcurses::buttonClose() const
{
    return false;
}

bool LibNcurses::buttonNextLib() const
{
    if (this->_key == KEY_F(3)) {
        return true;
    }
    return false;
}

bool LibNcurses::buttonPrevLib() const
{
    if (this->_key == KEY_F(2)) {
        return true;
    }
    return false;
}

bool LibNcurses::buttonNextGame() const
{
    if (this->_key == KEY_F(5))
        return true;
    return false;
}

bool LibNcurses::buttonPrevGame() const
{
    if (this->_key == KEY_F(4))
        return true;
    return false;
}

bool LibNcurses::buttonUp() const
{
    if (this->_key == KEY_UP || this->_key == 'z')
        return true;
    return false;
}

bool LibNcurses::buttonDown() const
{
    if (this->_key == KEY_DOWN || this->_key == 's')
        return true;
    return false;
}

bool LibNcurses::buttonRight() const
{
    if (this->_key == KEY_RIGHT || this->_key == 'd')
        return true;
    return false;
}

bool LibNcurses::buttonLeft() const
{
    if (this->_key == KEY_LEFT || this->_key == 'q')
        return true;
    return false;
}

bool LibNcurses::buttonSpace() const
{
    if (this->_key == ' ')
        return true;
    return false;
}

bool LibNcurses::buttonEnter() const
{
    if (this->_key == '\n')
        return true;
    return false;
}

bool LibNcurses::buttonEscape()
{
    if (this->_key == 27)
        return true;
    return false;
}

bool LibNcurses::buttonReset() const
{
    if (this->_key == 'r')
        return true;
    return false;
}

extern "C" {
    LibNcurses *constuct() {
        return new LibNcurses();
    }
}