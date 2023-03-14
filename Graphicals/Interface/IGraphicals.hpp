/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-leopold.sallan-gemard
** File description:
** IGraphicals
*/

#ifndef IGRAPHICAL_HPP_
    #define IGRAPHICAL_HPP_

class IGraphical {
    public:
        ~IGraphical() = default;

        virtual void display() = 0;

        virtual void openWindow() = 0;

        virtual void closeWindow() = 0;

        virtual void createGrid() = 0;

        virtual void updateCell() = 0;

        virtual void setName() = 0;

        virtual int setSize() = 0;

        virtual int getState() = 0;

        virtual int getKey() = 0;

};

#endif
