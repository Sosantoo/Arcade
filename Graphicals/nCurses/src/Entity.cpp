/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Entity
*/

#include "GraphicalFactoryNcurses.hpp"
#include <ncurses.h>

void GridNcurses::setColorPair(int colorPair, int foregroundColor, int backgroundColor) {
    init_pair(colorPair, foregroundColor, backgroundColor);
}

void GridNcurses::setColor(int x, int y, int color) {
    wattron(_window, COLOR_PAIR(color));
    // std::cout << x << " " << y << " " << color << std::endl;
    // for (int i = startY; i < startY + cellHeight; i++) {
    //     for (int j = startX; j < startX + cellWidth; j++) {
    mvwprintw(_window, y, x, "  ");
    //     }
    // }
    // wrefresh(_window);
    wattroff(_window, COLOR_PAIR(color));
}

void GridNcurses::create(int gridRow, int gridColumn) {
    _gridRow = gridRow;
    _gridColumn = gridColumn;
    start_color();
    colorBackGround = COLOR_BLACK;
    setColorPair(1, COLOR_WHITE, COLOR_BLUE);
    setColorPair(2, COLOR_WHITE, COLOR_GREEN);
    setColorPair(3, COLOR_WHITE, COLOR_RED);
    setColorPair(4, COLOR_WHITE, COLOR_MAGENTA);
    setColorPair(5, COLOR_WHITE, COLOR_CYAN);
    setColorPair(6, COLOR_WHITE, COLOR_YELLOW);
    setColorPair(7, COLOR_WHITE, COLOR_WHITE);
}

void GridNcurses::displayEntity() {
    napms(100);
    refresh();
}

void GridNcurses::updateCell(int x, int y, Color color) {
    std::map<IEntity::Color, int> colorMap = {
        {IEntity::Color::Blue, 1},
        {IEntity::Color::Green, 2},
        {IEntity::Color::Orange, 3},
        {IEntity::Color::Red, 4},
        {IEntity::Color::Brown, 5},
        {IEntity::Color::Yellow, 6}
    };
    setColor(x, y, colorMap[color]);
}

void GridNcurses::destroy() {
}

//text
void TextNcurses::create(std::string str) {
    _text = str;
    _x = 0;
    _y = 0;

    mvprintw(_x, _y, " ");
}

void TextNcurses::setPosition(int x, int y) {
    _x = x / 50;
    _y = y / 50;
}

void TextNcurses::destroy() {

}

void TextNcurses::displayEntity() {
    mvprintw(_x, _y, _text.c_str());
    refresh();
}

void TextNcurses::changeString(std::string str) {
    _text = str;
}