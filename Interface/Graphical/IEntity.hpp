/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** IEntity
*/

#pragma once
#include <cstddef>
class IGrid
{
    public:
        enum class Color {
            Blue,
            Green,
            Orange,
            Red,
            Brown,
            Yellow,
        };

        struct {
                Color color;
                size_t x;
                size_t y;
        } Cell;

        ~IGrid() = default;

        virtual void createGrid() = 0;
        virtual void updateCell() = 0;
};

class IEntity
{
    public:
        ~IEntity() = default;

        virtual void create() = 0;
        virtual void setSize() = 0;
        virtual void setPosition() = 0;
        virtual void destroy() = 0;
        virtual void displayEntity() = 0;
};
