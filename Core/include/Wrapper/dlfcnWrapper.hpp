/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** DlfcnWrapper
*/

#ifndef DLFCNWRAPPER_HPP_
    #define DLFCNWRAPPER_HPP_
    #include "../various.hpp"

class DlfcnWrapper {
    public:
        DlfcnWrapper();
        DlfcnWrapper(const std::string &, int = RTLD_LAZY);
        ~DlfcnWrapper();

        void open(const std::string &, int = RTLD_LAZY);
        void close();
        std::string error();
        void *sym(const std::string &);
        bool islibLoaded();

    protected:
        void *_Handle;
};

#endif /* !DLFCNWRAPPER_HPP_ */
