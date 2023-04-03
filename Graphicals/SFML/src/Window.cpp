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

bool isAnyKeyPressed(std::vector<sf::Keyboard::Key> keys) {
    for (auto &key : keys) {
        if (sf::Keyboard::isKeyPressed(key))
            return true;
    }
    return false;
}

void WindowSFML::eventPollEvent()
{

    while (_window->pollEvent(event)) {
        switch (event.type) {
            case (sf::Event::Closed):
                return callEvent(EventType::QUIT);
            default: break;
        }

        if (isAnyKeyPressed({sf::Keyboard::Left, sf::Keyboard::Q}))
            return callEvent(EventType::LEFT_pressed);
        else if (isAnyKeyPressed({sf::Keyboard::Right, sf::Keyboard::D}))
            return callEvent(EventType::RIGHT_pressed);
        else if (isAnyKeyPressed({sf::Keyboard::Up, sf::Keyboard::Z}))
            return callEvent(EventType::UP_pressed);
        else if (isAnyKeyPressed({sf::Keyboard::Down, sf::Keyboard::S}))
            return callEvent(EventType::DOWN_pressed);

        else if (isAnyKeyPressed({sf::Keyboard::Y}))
            return callEvent(EventType::NEXT_LIB);

        else if (isAnyKeyPressed({sf::Keyboard::U}))
            return callEvent(EventType::NEXT_GAME);

        else if (isAnyKeyPressed({sf::Keyboard::I}))
            return callEvent(EventType::RESTART);

        else if (isAnyKeyPressed({sf::Keyboard::O}))
            return callEvent(EventType::GO_TO_MENU);

        else if (isAnyKeyPressed({sf::Keyboard::P}))
            return callEvent(EventType::QUIT);
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
