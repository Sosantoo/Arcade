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

    /**
     * @brief Set the Position object
     *
     * @param x
     * @param y
     */
    virtual void setPosition(int x, int y) = 0;

    /**
     * @brief
     *
     */
    virtual void destroy() = 0;

    /**
     * @brief
     *
     */
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

    /**
     * @brief
     *
     * @param str
     */
    virtual void create(std::string str) = 0;

    /**
     * @brief
     *
     * @param str
     */
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

    /**
     * @brief
     *
     * @param width
     * @param heigth
     */
    virtual void create(int width, int heigth) = 0;

    /**
     * @brief
     *
     * @param x
     * @param y
     */
    virtual void updateCell(int x, int y, IEntity::Color) = 0;
};
