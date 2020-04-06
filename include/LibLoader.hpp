/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** LibLoader
*/

#ifndef LIBLOADER_HPP_
#define LIBLOADER_HPP_

#include "defs.hpp"

template <class T>
class LibLoader {
    public:
        T load(const std::string &lib_path);

        void close();

    protected:
    private:
        void *_handle;
};

template <class T>
T LibLoader<T>::load(const std::string &lib_path)
{
    this->_handle = dlopen(lib_path.c_str(), RTLD_NOW);
    if (!this->_handle) {
        std::cerr << dlerror() << std::endl;
        exit(84);
    }
    T (*obj)() = (T (*)())dlsym(this->_handle, "constuct");
    if (obj == nullptr)
        std::cout << "nope" << std::endl;
    return obj();
}

template <class T>
void LibLoader<T>::close()
{
    dlclose(this->_handle);
}

#endif /* !LIBLOADER_HPP_ */
