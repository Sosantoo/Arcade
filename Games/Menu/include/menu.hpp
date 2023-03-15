/*
** EPITECH PROJECT, 2023
** arcadeMirror
** File description:
** AGame
*/

#ifndef AGAME_HPP_
    #define AGAME_HPP_
    #include "../../../Core/include/various.hpp"
    #include "../../Interface/IGames.hpp"

class AGame: public IGame {
    public:
        AGame();
        ~AGame();

        virtual void start();

        virtual void stop();

        virtual void reset();

        virtual int getLife() const;

        virtual int getScore() const;

        virtual int handleEvent() const;

        virtual void checkAroundCells() const;

        virtual void move(int hor, int vir);

};



#endif /* !AGAME_HPP_ */
