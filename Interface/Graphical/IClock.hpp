/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** IClock
*/

#pragma once
#include <bits/types/time_t.h>

class IClock
{
    public:
        ~IClock() = default;

        virtual void startClock() = 0;
        virtual time_t getTimeElapsed() = 0;
        virtual void resetClock() = 0;
        virtual void initClock() = 0;
        virtual IClock &getClock() = 0;
};
