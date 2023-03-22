/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** AGraphicalWindow
*/

#include "sdl2.hpp"


void AGraphical::openWindow()
{
    return;
}

void AGraphical::initWindow(std::string name, std::pair<size_t, size_t> size)
{
    SDL_Init(SDL_INIT_VIDEO);

    graphicalInfo.isOpen = true;
    graphicalInfo.window = SDL_CreateWindow(name.c_str(),
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          size.first, size.second,
                                          SDL_WINDOW_SHOWN);
};

void AGraphical::closeWindow()
{
    graphicalInfo.isOpen = false;
    SDL_DestroyWindow(graphicalInfo.window);
    SDL_Quit();
};

bool AGraphical::windowIsOpen()
{
    return graphicalInfo.isOpen;
};

void AGraphical::clear()
{
    // SDL_SetRenderDrawColor(graphicalInfo.window, 0, 0, 0, 255);
    // SDL_RenderClear(graphicalInfo.window);
};

void AGraphical::display()
{
    while (SDL_PollEvent(&graphicalInfo.event)) {
        switch (graphicalInfo.event.type )
        {
        case SDL_QUIT:
            callEvent(IEvent::EventType::QUIT);
            break;
        case SDLK_DOWN:
        case SDLK_s:
            callEvent(IEvent::EventType::DOWN_pressed);
            break;
        case SDLK_UP:
        case SDLK_z:
            callEvent(IEvent::EventType::UP_pressed);
            break;
        case SDLK_LEFT:
        case SDLK_q:
            callEvent(IEvent::EventType::LEFT_pressed);
            break;
        case SDLK_RIGHT:
        case SDLK_d:
            callEvent(IEvent::EventType::RIGHT_pressed);
            break;
        default:
            return;
        }
    }
};
