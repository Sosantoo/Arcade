/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** nCurses
*/

#ifndef NCURSES_HPP_
    #define NCURSES_HPP_
    #include "../../../Core/include/various.hpp"
    #include "../../Interface/IGraphicals.hpp"

class AGraphicals: public IGraphical {
    public:
        AGraphicals();
        ~AGraphicals();

        virtual void display() final;

        virtual void openWindow() final;

        virtual void closeWindow() final;

        virtual void createGrid() final;

        virtual void updateCell() final;

        virtual void setName() final;

        virtual int setSize() final;

        virtual int getState() final;

        virtual int getKey() final;

};

#endif /* !NCURSES_HPP_ */
