/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** AGraphicalSDL2Window
*/

#include "sdl2.hpp"

void AGraphicalSDL2::loadResource()
{

}

void AGraphicalSDL2::destroyRessource()
{
    std::cout << "[SDL2] destroyRessource" << std::endl;
    SDL_DestroyWindow(graphicalInfo.window);
    SDL_Quit();
}

void AGraphicalSDL2::initWindow(std::string name, std::pair<size_t, size_t> size)
{
    std::cout << "[SDL2] initWindow" << std::endl;
    SDL_Init(SDL_INIT_VIDEO);

    graphicalInfo.isOpen = true;
    graphicalInfo.window = SDL_CreateWindow(name.c_str(),
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          size.first, size.second,
                                          SDL_WINDOW_SHOWN);
};

void AGraphicalSDL2::closeWindow()
{
    graphicalInfo.isOpen = false;

};

bool AGraphicalSDL2::windowIsOpen()
{
    return graphicalInfo.isOpen;
};

void AGraphicalSDL2::clear()
{

};

void AGraphicalSDL2::display()
{
};

void AGraphicalSDL2::eventPollEvent()
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
        case SDLK_n:
            callEvent(IEvent::EventType::NEXT_LIB);
            break;
        default:
            return;
        }
    }
};

//clock
IClock &AGraphicalSDL2::getClock() {
    return graphicalInfo.clock;
};