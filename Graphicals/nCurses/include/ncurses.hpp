/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** nCurses
*/

#ifndef NCURSES_HPP_
    #define NCURSES_HPP_
    #include "../../../Core/include/various.hpp"
    #include "../../../Interface/IGraphicals.hpp"

class AGraphical: public IGraphical {
    public:
    AGraphical() {};
    ~AGraphical() {};

    virtual void createSprite() const {};
    virtual void createGrid() const {};
    virtual void updateCell() const {};
    virtual void display() const {};
    virtual void initWindow(std::string, std::pair<size_t, size_t>) const {};
    virtual void openWindow() const {};
    virtual void closeWindow() const {};

};

#endif /* !NCURSES_HPP_ */
