/*
** EPITECH PROJECT, 2023
** arcadeMirror
** File description:
** AGame
*/

#include "menu.hpp"

AGame::AGame()
{

}

AGame::~AGame()
{

}

void AGame::start(IGraphical &graphicalInterface) const {
    std::cout << "[MENU game] start"<< std::endl;
}

void AGame::stop() const {
    std::cout << "[MENU game] stop" << std::endl;
}

void AGame::reset() const {
    std::cout << "[MENU game] reset" << std::endl;
}

int AGame::getLife() const {
    std::cout << "[MENU game] getLife" << std::endl;
    return 0;
}

int AGame::getScore() const {
    std::cout << "[MENU game] getScore" << std::endl;
    return 0;
}

int AGame::handleEvent() const {
    std::cout << "[MENU game] handleEvent" << std::endl;
    return 0;
}

void AGame::checkAroundCells() const {
    std::cout << "[MENU game] checkAroundCells" << std::endl;
}

void AGame::move(int hor, int vir) const {
    (void)hor;
    (void)vir;

    std::cout << "[MENU game] move" << std::endl;
}
