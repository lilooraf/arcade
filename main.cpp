/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** main
*/

#include "include/ILib.hpp"
#include "include/Core.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return 84;
    Core *core = new Core(av[1]);
    std::string input;
    core->getCurrentLib()->windowOpen();
    while (core->getCurrentLib()->windowIsOpen()) {
        core->getCurrentLib()->windowClear();
        core->getCurrentLib()->windowDisplay(core->getTab());
        core->getCurrentLib()->userInput();
        core->basicInput();
    }
    core->getCurrentLib()->windowClose();

    return 0;
}