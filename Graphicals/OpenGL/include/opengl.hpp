/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** opengl
*/

#pragma once
#include "../../../Core/include/various.hpp"
#include "../../../Interface/Graphical/IGraphicals.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class AGraphical : public IGraphical
{
    public:
        AGraphical() : _eventBinding{nullptr} {}
        ~AGraphical(){};

        // IGraphical
        virtual void loadResource(){};
        virtual void resetResource(){};

        // IWindow
        virtual void openWindow() final;
        virtual void closeWindow() final;
        virtual void initWindow(std::string, std::pair<size_t, size_t>) final;
        virtual bool windowIsOpen() final;
        virtual void clear() final;
        virtual void display() final;

        // IEvent
        virtual void loadEventBindings(EventHandler &) final{};

        // IEntity
        virtual void create() final{};

        virtual void setSize() final{};

        virtual void setPosition() final{};

        virtual void destroy() final{};

        virtual void displayEntity() final{};

    private:
        const int WINDOW_WIDTH = 800;
        const int WINDOW_HEIGHT = 600;
        const char *WINDOW_TITLE = "OpenGL Arcade";
        void callEvent(const IEvent::EventType);
        GLFWwindow *window;
        EventHandler *_eventBinding;
        std::unordered_map<int, bool> keyState;
};
