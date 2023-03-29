/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** AGraphicals
*/

#include "../include/AGraphicalSFML.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <unordered_map>

std::unordered_map<int, bool> keyState;

void AGraphicalSFML::initWindow(std::string name, std::pair<size_t, size_t> size)
{
    // graphicalInfo.setFramerateLimit(60);
    graphicalInfo.window.create(sf::VideoMode(size.first, size.second), name);
};

void AGraphicalSFML::closeWindow()
{
    graphicalInfo.window.close();
};

bool AGraphicalSFML::windowIsOpen()
{
    return (graphicalInfo.window.isOpen());
};

void AGraphicalSFML::clear()
{
    graphicalInfo.window.clear();
};

void AGraphicalSFML::eventPollEvent()
{

    while (graphicalInfo.window.pollEvent(graphicalInfo.event)) {
        switch (graphicalInfo.event.type) {
            case (sf::Event::Closed): callEvent(EventType::QUIT);
            default: break;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1))
            callEvent(EventType::NEXT_LIB);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F2))
            callEvent(EventType::NEXT_GAME);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F3))
            callEvent(EventType::RESTART);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F4))
            callEvent(EventType::GO_TO_MENU);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F5))
            callEvent(EventType::QUIT);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            callEvent(EventType::LEFT_pressed);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            callEvent(EventType::RIGHT_pressed);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            callEvent(EventType::UP_pressed);
    }
};

void AGraphicalSFML::display()
{
    graphicalInfo.window.display();
};

void AGraphicalSFML::loadResource(){
    // loadImage();
    // loadFont();
};

void AGraphicalSFML::destroyRessource(){
    // graphicalInfo._window.close();
};