/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-leopold.sallan-gemard
** File description:
** IGames
*/

#ifndef IGAME_HPP_
    #define IGAME_HPP_

class IGame {
    public:
        ~IGame() = default;

        virtual void start() = 0;

        virtual void stop() = 0;

        virtual void reset() = 0;

        virtual int getLife() const = 0;

        virtual int getScore() const = 0;

        virtual int handleEvent() const = 0;

        virtual void checkAroundCells() const = 0;

        virtual void move(int hor, int vir) = 0;
};

typedef IGame* create_game_t();
typedef void destroy_game_t(IGame *);

#endif
