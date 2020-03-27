/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** Core
*/

#include "../include/Core.hpp"

Core::Core(const std::string &lib_path)
{
    loadLib(lib_path);
    this->_graphLibs = parseLibs("lib/");
    for (size_t i = 0; i < this->_graphLibs.size() ; i++) {
        std::string tmp;
        tmp.assign(this->_graphLibs.at(i).c_str());
        if (tmp.compare(lib_path.substr(lib_path.length() - tmp.length(), tmp.length())) == 0) {
            this->_libCount = i;
            break;
        }
    }
    this->_gameCount = 0;
    std::vector<char> baseline;
    for (int i = 0; i < TAB_W; i++)
        baseline.push_back(i % 2 ? 'A' : 'B');
    for (int j = 0; j < TAB_H; j++)
        this->_tab.push_back(baseline);
}

Core::~Core()
{
}

/* GETTERS */

ILib *Core::getCurrentLib() const
{
    return this->_currentLib;
}

std::vector<std::vector<char>> Core::getTab() const
{
    return this->_tab;
}


/* SETTERS */

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

void Core::loadLib(const std::string &lib_path)
{
    this->_handle = dlopen(lib_path.c_str(), RTLD_NOW);
    if (!this->_handle)
        exit(84);
    ILib *(*obj)() = (ILib *(*)())dlsym(this->_handle, "constuct");
    if (obj == nullptr)
        std::cout << "nope" << std::endl;
    this->_currentLib = obj();
    this->_currentLib->setTextures(this->_texMap);
}

void Core::closeLib()
{
    dlclose(this->_handle);
}

void Core::nextLib()
{
    this->_currentLib->windowClose();
    closeLib();
    this->_libCount = this->_libCount + 1 < this->_graphLibs.size() ? this->_libCount + 1 : 0;
    loadLib("lib/" + this->_graphLibs.at(this->_libCount));
    this->_currentLib->windowOpen();
}

void Core::prevLib()
{
    this->_currentLib->windowClose();
    closeLib();
    this->_libCount = this->_libCount == 0 ? this->_graphLibs.size() - 1 : this->_libCount - 1;
    loadLib("lib/" + this->_graphLibs.at(this->_libCount));
    this->_currentLib->windowOpen();
}

void Core::basicInput()
{
    if (this->_currentLib->buttonClose()) {
        this->_currentLib->windowClose();
        closeLib();
        exit(0);
    }
    if (this->_currentLib->buttonNextLib())
        nextLib();
    if (this->_currentLib->buttonPrevLib())
        prevLib();
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