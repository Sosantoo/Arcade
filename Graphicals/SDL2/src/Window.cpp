/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Window
*/

#include "GraphicalFactorySDL2.hpp"
#include <SDL2/SDL.h>
#include <iostream>

void WindowSDL2::initWindow(std::string name, size_t width, size_t height)
{
    std::cout << "[SDL2] initWindow" << std::endl;

    isOpen = true;
    SDL_Init(SDL_INIT_VIDEO);
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        throw std::runtime_error("SDL could not initialize!");

    _window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width,
                        height, SDL_WINDOW_SHOWN);
    if (!_window)
        throw std::runtime_error("Window could not be created!!");
};

void WindowSDL2::closeWindow()
{
    isOpen = false;
    SDL_DestroyWindow(_window);
};

bool WindowSDL2::windowIsOpen()
{
    return isOpen;
};

void WindowSDL2::clear()
{

};

void WindowSDL2::display()
{
};

void WindowSDL2::eventPollEvent()
{
   while (SDL_PollEvent(&event)) {
        switch (event.type )
        {
        case SDL_QUIT:
            callEvent(IWindow::EventType::QUIT);
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_DOWN:
                case SDLK_s:
                    return callEvent(IWindow::EventType::DOWN_pressed);
                case SDLK_UP:
                case SDLK_z:
                    return callEvent(IWindow::EventType::UP_pressed);
                    break;
                case SDLK_LEFT:
                case SDLK_q:
                    return callEvent(IWindow::EventType::LEFT_pressed);
                case SDLK_RIGHT:
                case SDLK_d:
                    return callEvent(IWindow::EventType::RIGHT_pressed);
                    break;
                case SDLK_n:
                    return callEvent(IWindow::EventType::NEXT_LIB);
                case SDLK_p:
                    return callEvent(IWindow::EventType::NEXT_GAME);
            }
            break;
        default:
            break;
        }
    }
};

void WindowSDL2::callEvent(const IWindow::EventType eventType) {
    if (_eventBinding.count(eventType) <= 0)
        throw std::runtime_error("--! [GAME Logic] no event binded");
    _eventBinding[eventType]();
}

void WindowSDL2::loadEventBindings(EventHandler &eventBinding) {
    _eventBinding.insert(eventBinding.begin(), eventBinding.end());
};

std::unique_ptr<IText> WindowSDL2::createIText() {
    return std::make_unique<TextSDL2>(_window);
}

std::unique_ptr<IGrid> WindowSDL2::createIGrid() {
    return std::make_unique<GridSDL2>(_window);
}
