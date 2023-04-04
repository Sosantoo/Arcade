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
         * @brief Start the clock used to measure time in the game or simulation.
         * This is a pure virtual function that must be implemented by the derived class. Its
         * purpose is to start the clock used to measure time in the game or simulation.
         */
        virtual void startClock() = 0;

        /**
         * @brief Get the time elapsed since the start of the clock.
         * Its purpose is to retrieve the time elapsed since the start of the clock used to measure
         * time in the game or simulation.
         * @return The time elapsed, in seconds.
         */
        virtual double getTimeElapsed() = 0;

        /**
         * @brief  Reset the clock used to measure time in the game or simulation.
         * Its purpose is to reset the clock used to measure time in the game or simulation to its
         * initial state.
         */
        virtual void resetClock() = 0;

        /**
         * @brief Initialize the clock used to measure time in the game or simulation.
         * Its purpose is to initialize the clock used to measure time in the game or simulation,
         * setting it to its initial state.
         */
        virtual void initClock() = 0;
};
