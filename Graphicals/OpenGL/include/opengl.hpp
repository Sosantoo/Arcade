/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** opengl
*/

#ifndef OPENGL_HPP_
    #define OPENGL_HPP_
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

#endif /* !OPENGL_HPP_ */
