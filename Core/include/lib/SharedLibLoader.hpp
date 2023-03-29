/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** SharedLibLoader
*/

#pragma once

class SharedLibLoader {
    protected:
        using CloseFunc = int (*)(void*);
        std::unique_ptr<void, CloseFunc> _Handle;

    public:
        SharedLibLoader();
        SharedLibLoader(const std::string &, int = RTLD_LAZY);
        ~SharedLibLoader();

        void open(const std::string &, int = RTLD_LAZY);
        void close();
        std::string error() const;
        void *sym(const std::string &);
        bool isLibLoaded() const;
};

