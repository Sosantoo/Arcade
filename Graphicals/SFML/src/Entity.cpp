/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Entity
*/

#include "GraphicalFactorySFML.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>


void GridSFML::setColor(int x, int y, sf::Color color) {
    auto windowSize = _window->getSize();

    int cellWidth = windowSize.x / _gridColumn;
    int cellHeight = windowSize.y / _gridRow;

    sf::RectangleShape rect(sf::Vector2f(cellWidth, cellHeight));
    rect.setPosition(sf::Vector2f(x * cellWidth, y * cellHeight));
    rect.setFillColor(color);

    _window->draw(rect);
}

void GridSFML::create(int gridRow, int gridColumn) {
    _gridRow = gridRow;
    _gridColumn = gridColumn;
    sf::Vector2u sizeWindow = _window->getSize();

    _renderer = new sf::RenderTexture();

    // Draw the grid
    for (int row = 0; row < gridRow; row++) {
        for (int col = 0; col < gridColumn; col++) {
            if (row == 0 || col == 0 || _gridRow - 1 == row || _gridColumn - 1 == col)
                updateCell(col, row, IEntity::Color::Orange);
            else
                updateCell(col, row, colorBackGround);
        }
    }
}

void GridSFML::displayEntity() {
    sf::sleep(sf::milliseconds(50));
};

void GridSFML::updateCell(int x, int y, Color color) {
    std::map<IEntity::Color, sf::Color> colorMap = {
        {IEntity::Color::Blue, sf::Color(173, 216, 230, 255)},
        {IEntity::Color::Green, sf::Color(152, 251, 152, 255)},
        {IEntity::Color::Orange, sf::Color(255, 218, 185, 255)},
        {IEntity::Color::Red, sf::Color(255, 192, 203, 255)},
        {IEntity::Color::Brown, sf::Color(222, 184, 135, 255)},
        {IEntity::Color::Yellow, sf::Color(255, 255, 204, 255)}
    };
    setColor(x, y, colorMap[color]);
};

void GridSFML::destroy() {
}