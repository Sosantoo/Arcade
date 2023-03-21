/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** nibbler
*/

#ifndef NIBBLER_HPP_
    #define NIBBLER_HPP_
    #include "../../../Interface/IGames.hpp"
    #include "../../../Interface/IGraphicals.hpp"

class AGame:public IGame {
    public:
        AGame() {};
        ~AGame() {};

        virtual void start(IGraphical &graphical) const {
        };

        virtual void stop() const {
        };

        virtual void reset() const {

        };

        virtual int getLife() const {
            return 0;
        };

        virtual int getScore() const {
            return 0;

        };

        virtual int handleEvent() const {
            return 0;

        };

        virtual void checkAroundCells() const {

        };

        virtual void move(int hor, int vir) const {
            (void) hor;
            (void) vir;
        };
};


#endif /* !NIBBLER_HPP_ */
