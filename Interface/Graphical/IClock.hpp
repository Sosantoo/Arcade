/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** IClock
*/

#pragma once
#include "../../Core/include/various.hpp"

class IClock {
    public:
        ~IClock() = delete;;

        virtual void startClock() = 0;

        virtual double getTimeElapsed() = 0;

        virtual void resetClock() = 0;
};

