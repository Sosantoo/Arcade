/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** DlfcnWrapper
*/

#pragma once
#include <dlfcn.h>
#include <memory>
#include <string>

class DlfcnWrapper
{
    protected:
        using CloseFunc = int (*)(void *);
        std::unique_ptr<void, CloseFunc> _Handle;

    public:
        DlfcnWrapper();
        DlfcnWrapper(const std::string &, int = RTLD_LAZY);
        ~DlfcnWrapper();

        void open(const std::string &, int = RTLD_LAZY);
        void close();
        [[nodiscard]] std::string error() const;
        void *sym(const std::string &);
        [[nodiscard]] bool isLibLoaded() const;
};
