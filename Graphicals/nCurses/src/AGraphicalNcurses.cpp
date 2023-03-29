/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** AGraphicalNcurses
*/

#include "AGraphicalNcurses.hpp"
#include <iostream>
#include <ncurses.h>

AGraphicalNcurses::AGraphicalNcurses()
{
    if (!initscr())
        std::cerr << "LibGraphNcurses: could not initiate window" << std::endl;
    cbreak();
    noecho();
    curs_set(0);
    nonl();
    keypad(stdscr, TRUE);
    wtimeout(stdscr, 100);
    nodelay(stdscr, true);
    intrflush(stdscr, true);
}

AGraphicalNcurses::~AGraphicalNcurses()
{
    endwin();
}

void AGraphicalNcurses::loadResource()
{
    std::cout << "[nCurses loadResource] loadResource" << std::endl;
}

void AGraphicalNcurses::destroyRessource()
{
    std::cout << "[nCurses loadRessousreces] destroyRessource" << std::endl;
}

void AGraphicalNcurses::openWindow()
{
    std::cout << "[nCurses] openWindow" << std::endl;
};

void AGraphicalNcurses::closeWindow()
{
    std::cout << "[nCurses] closeWindow" << std::endl;
    // graphicalInfo.isOpen = false;
    // endwin();
};

void AGraphicalNcurses::initWindow(std::string name, std::pair<size_t, size_t> size){
    // snake_pos.x = (COLS - size.first) / 2;
    // snake_pos.y = (LINES - size.second) / 2;
    // WINDOW *win = newwin(height, width, y, x);
    // box(win, 0, 0);
    // refresh();
    // wrefresh(win);
};

bool AGraphicalNcurses::windowIsOpen()
{
    return graphicalInfo.isOpen;
};

void AGraphicalNcurses::clear()
{
    erase();
};

void AGraphicalNcurses::display()
{
    refresh();
};

void AGraphicalNcurses::eventPollEvent()
{
    // int key = wgetch(graphicalInfo.win);

    // switch (key) {
    //     case KEY_UP:
    //     case 'z': return callEvent(IEvent::EventType::UP_pressed);

    //     case KEY_DOWN:
    //     case 's': return callEvent(IEvent::EventType::DOWN_pressed);

    //     case KEY_LEFT:
    //     case 'q': return callEvent(IEvent::EventType::LEFT_pressed);

    //     case KEY_RIGHT:
    //     case 'd': return callEvent(IEvent::EventType::RIGHT_pressed);

    //     case 'n': return callEvent(IEvent::EventType::NEXT_LIB);

    //     case 27: return callEvent(IEvent::EventType::QUIT);

    //     default: std::cerr << "--! Event Handler Unknown key: " << key << std::endl; break;
    // }
};

IClock &AGraphicalNcurses::getClock()
{
    // return _clock;
};

// void initializeSnake(Snake &snake, int width, int height)
// {
//     // snake.x[0] = width / 2;
//     // snake.y[0] = height / 2;
//     // snake.size = 4;
// }

void initializeFood(int &foodX, int &foodY, int width, int height)
{
    // foodX = rand() % width - 1;
    // foodY = rand() % height - 1;
}

// void drawFoodAndSnake(WINDOW *win, const SnakePos &snake, int food_x, int food_y, int score)
// {
//     mvwprintw(win, food_x, food_y, "o");
//     for (int i = 0; i < snake.size; i++) {
//         mvwprintw(win, snake.y[i], snake.x[i], "x");
//     }
//     mvwprintw(win, 0, 0, "Score: %d", score);
// }

// void displaySnake(WINDOW *win, const SnakePos &snake)
// {
//     for (int i = 0; i < snake.size; i++) {
//         mvwprintw(win, snake.y[i], snake.x[i], "x");
//     }
// }

// void updateSnakePosition(Snake &snake, int &stockx, int &stocky, int ch)
// {
//     for (int i = snake.size - 1; i > 0; i--) {
//         snake.x[i] = snake.x[i - 1];
//         snake.y[i] = snake.y[i - 1];
//     }
//     switch (ch) {
//         case KEY_UP:
//             stockx = 0;
//             stocky = -1;
//             snake.y[0]--;
//             break;
//         case KEY_DOWN:
//             stockx = 0;
//             stocky = 1;
//             snake.y[0]++;
//             break;
//         case KEY_LEFT:
//             stockx = -1;
//             stocky = 0;
//             snake.x[0]--;
//             break;
//         case KEY_RIGHT:
//             stockx = 1;
//             stocky = 0;
//             snake.x[0]++;
//             break;
//         case ERR:
//             snake.x[0] += stockx;
//             snake.y[0] += stocky;
//             break;
//     }
// }

// void displayGameOver(WINDOW *win, int score)
// {
//     // wclear(win);
//     // mvwprintw(win, 0, 0, "Score: %d", score);
//     // mvwprintw(win, 1, 0, "Game Over");
//     // mvwprintw(win, 2, 0, "Press any key to play again");
//     // mvwprintw(win, 3, 0, "Press q to quit");
//     // wrefresh(win);
// }

// bool checkGameStatus(const Snake &snake, int width, int height)
// {
//     // if (snake.x[0] < 1 || snake.x[0] > width - 1 || snake.y[0] < 1 || snake.y[0] > height - 1) {
//     //     return true;
//     // }
//     // for (int i = 1; i < snake.size; i++) {
//     //     if (snake.x[0] == snake.x[i] && snake.y[0] == snake.y[i]) {
//     //         return true;
//     //     }
//     // }
//     // return false;
// }

// int main() {
//     int width = 50; int height = 20;
//     int foodX; int foodY; int score = 0;
//     int stockx = 1; int stocky = 0; int ch; bool gameOver = false;
//     Snake snake;
//     initializeNcurses();
//     WINDOW* win = initializeWindow(width, height);
//     initializeSnake(snake, width, height);
//     initializeFood(foodX, foodY, width, height);
//     while (!gameOver) {
//         drawFoodAndSnake(win, snake, foodX, foodY, score);
//         ch = getch();
//         mvwprintw(win, snake.y[snake.size - 1], snake.x[snake.size - 1], " ");
//         displaySnake(win, snake);
//         if (snake.x[0] == foodX && snake.y[0] == foodY) {
//             snake.size++;
//             score++;
//             foodX = rand() % width -1;
//             foodY = rand() % height-1;
//         }
//         gameOver = checkGameStatus(snake, width, height);
//         mvwprintw(win, 0, 0, "Score: %d", score);
//         mvwprintw(win, snake.y[snake.size - 1], snake.x[snake.size - 1], " ");
//         updateSnakePosition(snake, stockx, stocky, ch);
//         wrefresh(win);
//     }
//     wclear(win);
//     while (getch() != 'q') {
//         displayGameOver(win, score);
//         if (getch() == 'q') {
//             exit(0);
//         } else{
//             gameOver = false;
//         }
//     }
//     endwin();
//     return 0;
// }