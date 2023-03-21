/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** opengl
*/

#ifndef OPENGL_HPP_
    #define OPENGL_HPP_
    #include "../../../Core/include/various.hpp"
    #include "../../../Interface/IGraphicals.hpp"
    #include <GL/glut.h>

class AGraphical: public IGraphical {
    public:
    AGraphical()
        : _eventBinding{ nullptr} {};
    ~AGraphical() {};

    //Basics
    virtual void createSprite() const {};

    //IGrid
    virtual void createGrid() const {};
    virtual void updateCell() const {};

    //IWindow
    virtual void display() const {};
    virtual void initWindow(std::string, std::pair<size_t, size_t>) const;
    virtual void openWindow() const;
    virtual void closeWindow() const;

    //IEvent
    virtual void loadEventBindings(IEvent::EventHandler &);

    private:
        IEvent::EventHandler *_eventBinding;
        std::unordered_map<int, bool> keyState;
};

int launchSnakeTest(int argc, char** argv);

#endif /* !OPENGL_HPP_ */
