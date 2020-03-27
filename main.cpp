/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** main
*/

#include "include/ILib.hpp"
#include "include/Core.hpp"

void GameLinkTexture(Core *core)
{
    std::map <char, std::string> texMap;
    texMap.insert(std::make_pair('A', "./assets/test.png"));
    texMap.insert(std::make_pair('B', "./assets/test1.png"));
    core->setTexmap(texMap);
    core->getCurrentLib()->setTextures(texMap);
}

int main(int ac, char **av)
{
    if (ac != 2)
        return 84;
    Core *core = new Core(av[1]);

    // Game set a map of his textures path link to a char
    GameLinkTexture(core);

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