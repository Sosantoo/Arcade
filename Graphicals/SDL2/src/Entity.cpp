/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Entity
*/

#include "GraphicalFactorySDL2.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <map>

void GridSDL2::resetColor() {
    SDL_SetRenderDrawColor(_renderer, 255, 255, 204, 255);
}

void GridSDL2::setColor(int x, int y, SDL_Color color) {
    int WINDOW_WIDTH, WINDOW_HEIGHT;
    SDL_GetWindowSize(_window, &WINDOW_WIDTH, &WINDOW_HEIGHT);

    int cellWidth = WINDOW_WIDTH / _gridColumn;
    int cellHeight = WINDOW_HEIGHT / _gridRow;

    SDL_Rect rect = {x * cellWidth, y * cellHeight, cellWidth, cellHeight};
    SDL_SetRenderDrawColor(_renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(_renderer, &rect);
    SDL_RenderDrawRect(_renderer, &rect);
    resetColor();
}

void GridSDL2::create(int gridRow, int gridColumn) {
    // Initialize variables
    _gridRow = gridRow;
    _gridColumn = gridColumn;
   resetColor();
}

void GridSDL2::displayEntity() {
    SDL_RenderPresent(_renderer);
    SDL_Delay(50);
};

void GridSDL2::updateCell(int x, int y, Color color) {
    std::map<IEntity::Color, SDL_Color> colorMap = {
        {IEntity::Color::Blue, {173, 216, 230, 255}},
        {IEntity::Color::Green, {152, 251, 152, 255}},
        {IEntity::Color::Orange, {255, 218, 185, 255}},
        {IEntity::Color::Red, {255, 192, 203, 255}},
        {IEntity::Color::Brown, {222, 184, 135, 255}},
        {IEntity::Color::Yellow, {255, 255, 204, 255}}
    };
    setColor(x, y, colorMap[color]);
};

void GridSDL2::destroy() {
}


//Clock
void ClockSDL2::startClock() {
    startTime = SDL_GetTicks();
};

double ClockSDL2::getTimeElapsed() {
    // return (SDL_GetTicks() - startTime) / 1000.0; //milliseconds
    return SDL_GetTicks() - startTime;
}

void ClockSDL2::resetClock() {
    startTime = SDL_GetTicks();
};

void ClockSDL2::initClock() {
    startTime = SDL_GetTicks();
};


//text
TextSDL2::TextSDL2(SDL_Renderer *renderer) : _renderer(renderer) {
    if (TTF_Init() < 0) {
        throw std::runtime_error("Failed to initialize SDL_ttf");
    }
    _font = TTF_OpenFont(PATH_FONT, 30);
    if (!_font) {
        throw std::runtime_error("Failed to load font");
    }
}

TextSDL2::~TextSDL2() {
    if (_text_texture) {
        SDL_DestroyTexture(_text_texture);
    }
    if (_font) {
        TTF_CloseFont(_font);
    }
    TTF_Quit();
}

void TextSDL2::create(std::string str) {
    SDL_Color color = {255, 192, 203, 255};
    _surface = TTF_RenderText_Solid(_font, str.c_str(), color);
    _text_texture = SDL_CreateTextureFromSurface(_renderer, _surface);

    int texW = 0;
    int texH = 0;
    SDL_QueryTexture(_text_texture, NULL, NULL, &texW, &texH);
    _rect = { 0, 0, texW, texH };
}

void TextSDL2::setPosition(int x, int y) {
    _rect.x = x;
    _rect.y = y;
}

void TextSDL2::destroy() {
    SDL_DestroyTexture(_text_texture);
    SDL_FreeSurface(_surface);
    TTF_CloseFont(_font);
}

void TextSDL2::displayEntity() {
    SDL_RenderCopy(_renderer, _text_texture, NULL, &_rect);
}

void TextSDL2::changeString(std::string str) {
    SDL_Color color = {255, 218, 185, 255};
    _surface = TTF_RenderText_Solid(_font, str.c_str(), color);
    _text_texture = SDL_CreateTextureFromSurface(_renderer, _surface);

    int texW = 0;
    int texH = 0;
    SDL_QueryTexture(_text_texture, NULL, NULL, &texW, &texH);
    _rect.w = texW;
    _rect.h = texH;
}