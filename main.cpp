/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** main
*/

#include "include/ILib.hpp"
#include "include/Core.hpp"
#include "include/defs.hpp"

int usage()
{
    std::cout << "USAGE" << std::endl;
    std::cout << "\t./arcade lib_path" << std::endl;
    std::cout << "DESCRIPTION" << std::endl;
    std::cout << "\tlib_path\tA library in the lib/ folder." << std::endl;
    return 84;
}

void GameLinkTexture(Core *core)
{
    std::map <char, std::string> texMap;
    texMap.insert(std::make_pair('H', "./assets/H.png"));
    texMap.insert(std::make_pair('V', "./assets/V.png"));
    texMap.insert(std::make_pair('A', "./assets/A.png"));
    texMap.insert(std::make_pair('Z', "./assets/Z.png"));
    texMap.insert(std::make_pair('Q', "./assets/Q.png"));
    texMap.insert(std::make_pair('S', "./assets/S.png"));
    texMap.insert(std::make_pair(' ', "./assets/G.png"));
    texMap.insert(std::make_pair('N', "./assets/N.png"));
    texMap.insert(std::make_pair('H', "./assets/H.png"));
    texMap.insert(std::make_pair('.', "./assets/X.png"));
    texMap.insert(std::make_pair('o', "./assets/O.png"));
    texMap.insert(std::make_pair('B', "./assets/Ghost_V.png"));
    texMap.insert(std::make_pair('J', "./assets/Blinky.png"));
    texMap.insert(std::make_pair('P', "./assets/Pinky.png"));
    texMap.insert(std::make_pair('I', "./assets/Inky.png"));
    texMap.insert(std::make_pair('C', "./assets/Clyde.png"));
    texMap.insert(std::make_pair('u', "./assets/Pacman_U.png"));
    texMap.insert(std::make_pair('d', "./assets/Pacman_D.png"));
    texMap.insert(std::make_pair('r', "./assets/Pacman_R.png"));
    texMap.insert(std::make_pair('l', "./assets/Pacman_L.png"));
    texMap.insert(std::make_pair('1', "./assets/1.png"));
    texMap.insert(std::make_pair('2', "./assets/2.png"));
    texMap.insert(std::make_pair('3', "./assets/3.png"));
    texMap.insert(std::make_pair('4', "./assets/4.png"));
    texMap.insert(std::make_pair('5', "./assets/5.png"));
    core->setTexmap(texMap);
    core->getCurrentLib()->setTextures(texMap);
}

int main(int ac, char **av)
{
    std::srand(time(nullptr));
    if (ac != 2)
        return usage();
    Core *core = new Core(av[1], "games/lib_arcade_nibbler.so");

    // Game set a map of his textures path link to a char
    GameLinkTexture(core);

    core->getCurrentLib()->windowOpen();
    while (core->getCurrentLib()->windowIsOpen()) {
        core->basicInput();
        core->getCurrentLib()->windowClear();
        core->checkState();
    }
    core->getCurrentLib()->windowClose();

    return 0;
}