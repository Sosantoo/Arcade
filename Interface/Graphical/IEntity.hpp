/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** IEntity
*/

#pragma once
#include <string>

class IEntity
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

        ~IEntity() = default;

        /**
         * @brief Sets the position of the entity.
         * Its purpose is to set the position of the entity to the specified x and y coordinates.
         * The function takes two integer parameters representing the x and y coordinates to set as
         * the new position of the entity.
         * @param x
         * @param y
         */
        virtual void setPosition(int x, int y) = 0;

        /**
         * @brief  Destroys any resources used in the implementation.
         * Its purpose is to destroy any resources used in the implementation, such as windows or
         * textures.
         */
        virtual void destroy() = 0;

        /**
         * @brief Displays an entity on the screen.
         * Its purpose is to display an entity on the screen, such as a sprite or image.
         */
        virtual void displayEntity() = 0;
};

class IText : public IEntity
{
    public:
        enum class EntityType {
            GridEntity,
            SpriteEntity,
            TextEntity,
        };
        ~IText() = default;

        /**
         * @brief Creates a new object in the implementation.
         * Its purpose is to create a new object in the implementation based on the given string
         * parameter.
         * The function take a string as parameter, which can be used to determine the
         * type or properties of the object to be created
         * @param str
         */
        virtual void create(std::string str) = 0;

        /**
         * @brief Changes the string property of the object in the implementation.
         * Its purpose is to change the string property of the object in the implementation.
         * The function takes a string parameter, which represents the new value for the
         * string property of the object.
         * @param str
         */
        virtual void changeString(std::string str) = 0;
};

class IGrid : public IEntity
{
    public:
        struct Cell {
                Color color;
                size_t x;
                size_t y;
        };
        ~IGrid() = default;

        /**
         * @brief Creates a new object in the implementation with the given width and height.
         * Its purpose is to create a new object in the implementation with the given width and
         * height.
         * The function takes two integer parameters, representing the width and height of the new
         * object to be created.
         * @param width
         * @param heigth
         */
        virtual void create(int width, int heigth) = 0;

        /**
         * @brief a pure virtual function that must be implemented by the derived class.
         * Its purpose is to update the color of a cell in the implementation's grid, identified by
         * its x and y coordinates.
         * The function takes three parameters: two integer parameters representing the x and y
         * coordinates of the cell, and a parameter of type IEntity::Color representing the new
         * color to assign to the cell.
         * @param x
         * @param y
         */
        virtual void updateCell(int x, int y, IEntity::Color) = 0;
};
