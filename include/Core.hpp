/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include "defs.hpp"
#include "../include/ILib.hpp"

class Core {
    public:
        Core(const std::string &);
        ~Core();

        /* GETTERS */
        ILib *getCurrentLib() const;
        std::vector<std::vector<char>> getTab() const;

        /* SETTERS */
        void setCurrentLib(ILib *lib);

        void loadLib(const std::string &);
        void closeLib();
        std::vector<std::string> parseLibs(std::string);
        void nextLib();
        void prevLib();
        void basicInput();

    protected:
    private:
        std::vector<std::vector<char>> _tab;
        void *_handle;
        ILib *_currentLib;
        std::vector<std::string> _graphLibs;
        size_t _libCount;
        size_t _gameCount;
};

#endif /* !CORE_HPP_ */
