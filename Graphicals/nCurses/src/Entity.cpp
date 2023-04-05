/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Entity
*/

#include "GraphicalFactoryNcurses.hpp"
#include <ncurses.h>

void GridNcurses::setColor(int x, int y, int color)
{
    // std::cout << "setColor" << x << ", y: " << y << ", color: " << std::endl;
    wattron(_window, COLOR_PAIR(color));
    mvwprintw(_window, y, x, "w");
    wattroff(_window, COLOR_PAIR(color));
}

void GridNcurses::create(int gridRow, int gridColumn)
{
    _gridRow = gridRow;
    _gridColumn = gridColumn;
    colorBackGround = COLOR_BLACK;
    refresh();
}

void GridNcurses::displayEntity()
{
    wrefresh(_window);
}

void GridNcurses::updateCell(int x, int y, Color color)
{
    std::map<IEntity::Color, int> colorMap = {
        {IEntity::Color::Blue, 1}, {IEntity::Color::Green, 2}, {IEntity::Color::Orange, 3},
        {IEntity::Color::Red, 4},  {IEntity::Color::Brown, 5}, {IEntity::Color::Yellow, 6}};
    setColor(x, y, colorMap[color]);
}

void GridNcurses::destroy() {
}

//text
void TextNcurses::create(std::string str) {
    _text = str;
    _x = 0;
    _y = 0;
    mvwprintw(_window, _x, _y, " ");
}

void TextNcurses::setPosition(int x, int y) {
    _x = x / 50;
    _y = y / 50;
}

void TextNcurses::destroy() {

}

void TextNcurses::displayEntity() {
    mvwprintw(_window, _x, _y, " ");
}

void TextNcurses::changeString(std::string str) {
    _text = str;
}