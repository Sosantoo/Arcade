/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** IClock
*/

#pragma once

class IClock
{
    public:
        ~IClock() = default;

        virtual void startClock() = 0;
        virtual double getTimeElapsed() = 0;
        virtual void resetClock() = 0;
        virtual void initClock() = 0;
};
