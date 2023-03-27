/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** AGameNibller
*/

#pragma once
#include "../../Interface/AGame.hpp"
#include "GameEngine.hpp"

class AGameNibller : public AGame<GameEngine> {
private:

public:
    AGameNibller(): AGame<GameEngine>() {};
    AGameNibller(IGraphical &, IEvent::EventHandler &) {};
    ~AGameNibller() {};
};
