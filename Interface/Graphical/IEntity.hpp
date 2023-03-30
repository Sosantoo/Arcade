/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** IEntity
*/

#pragma once
#include <string>

class IEntity {
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

    virtual void setPosition(int x, int y) = 0;

    virtual void destroy() = 0;

    virtual void displayEntity() = 0;
};

class IText
    : public IEntity
{
public:
    enum class EntityType {
        GridEntity,
        SpriteEntity,
        TextEntity,
    };

    ~IText() = default;

    virtual void create(std::string str) = 0;

    virtual void changeString(std::string str) = 0;
};

class IGrid
    : public IEntity
{
public:
    struct Cell {
        Color color;
        size_t x;
        size_t y;
    };

    ~IGrid() = default;

    virtual void create(int width, int heigth) = 0;

    virtual void updateCell(int x, int y, IEntity::Color) = 0;
};
