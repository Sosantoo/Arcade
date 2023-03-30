/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Window
*/

#include "GraphicalFactorySFML.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

std::unordered_map<int, bool> keyState;

void WindowSFML::initWindow(std::string name, size_t width, size_t height)
{
    _window = new sf::RenderWindow(sf::VideoMode(width, height), name);
    _window->setFramerateLimit(60);
};

void WindowSFML::closeWindow()
{
    _window->close();
};

bool WindowSFML::windowIsOpen()
{
    return _window->isOpen();;
};

void WindowSFML::clear()
{
    _window->clear();
};

void WindowSFML::display()
{
   _window->display();
};

void WindowSFML::eventPollEvent()
{

    while (_window->pollEvent(event)) {
        switch (event.type) {
            case (sf::Event::Closed):
                callEvent(EventType::QUIT);
            default: break;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
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
         else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            callEvent(EventType::DOWN_pressed);
    }
};

void WindowSFML::callEvent(const IWindow::EventType eventType) {
    if (_eventBinding.count(eventType) <= 0)
        throw std::runtime_error("--! [GAME Logic] no event binded");
    _eventBinding[eventType]();
}

void WindowSFML::loadEventBindings(EventHandler &eventBinding) {
    _eventBinding.insert(eventBinding.begin(), eventBinding.end());
};

//Entity
std::unique_ptr<IText> WindowSFML::createIText() {
    return std::make_unique<TextSFML>(_window);
}

std::unique_ptr<IGrid> WindowSFML::createIGrid() {
    return std::make_unique<GridSFML>(_window);
}
