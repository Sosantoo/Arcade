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

        /**
         * @brief
         *
         */
        virtual void startClock() = 0;

        /**
         * @brief
         *
         */
        virtual double getTimeElapsed() = 0;

        /**
         * @brief
         *
         */
        virtual void resetClock() = 0;

        /**
         * @brief
         *
         */
        virtual void initClock() = 0;
};
