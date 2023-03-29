/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** snake
*/

#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include <cstdlib>

struct Snake {
    int x[101];
    int y[101];
    int size;
};

void initializeNcurses() {
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    wtimeout(stdscr, 100);
}

WINDOW* initializeWindow(int width, int height) {
    int x = (COLS - width) / 2;
    int y = (LINES - height) / 2;
    WINDOW *win = newwin(height, width, y, x);
    box(win, 0, 0);
    refresh();
    wrefresh(win);
    return win;
}

void initializeSnake(Snake& snake, int width, int height) {
    snake.x[0] = width / 2;
    snake.y[0] = height / 2;
    snake.size = 4;
}

void initializeFood(int& foodX, int& foodY, int width, int height) {
    foodX = rand() % width -1;
    foodY = rand() % height-1;
}

void drawFoodAndSnake(WINDOW* win, const Snake& snake, int foodX, int foodY, int score) {
    mvwprintw(win, foodY, foodX, "o");
    for (int i = 0; i < snake.size; i++) {
        mvwprintw(win, snake.y[i], snake.x[i], "x");
    }
    mvwprintw(win, 0, 0, "Score: %d", score);
}

void displaySnake(WINDOW* win, const Snake& snake) {
    for (int i = 0; i < snake.size; i++) {
        mvwprintw(win, snake.y[i], snake.x[i], "x");
    }
}

void updateSnakePosition(Snake& snake, int& stockx, int& stocky, int ch) {
    for (int i = snake.size - 1; i > 0; i--) {
        snake.x[i] = snake.x[i - 1];
        snake.y[i] = snake.y[i - 1];
    }
    switch (ch) {
        case KEY_UP:
            stockx = 0;
            stocky = -1;
            snake.y[0]--;
            break;
        case KEY_DOWN:
            stockx = 0;
            stocky = 1;
            snake.y[0]++;
            break;
        case KEY_LEFT:
            stockx = -1;
            stocky = 0;
            snake.x[0]--;
            break;
        case KEY_RIGHT:
            stockx = 1;
            stocky = 0;
            snake.x[0]++;
            break;
        case ERR:
            snake.x[0] += stockx;
            snake.y[0] += stocky;
            break;
    }
}

void displayGameOver(WINDOW* win, int score) {
    wclear(win);
    mvwprintw(win, 0, 0, "Score: %d", score);
    mvwprintw(win, 1, 0, "Game Over");
    mvwprintw(win, 2, 0, "Press any key to play again");
    mvwprintw(win, 3, 0, "Press q to quit");
    wrefresh(win);
}

bool checkGameStatus(const Snake& snake, int width, int height) {
    if (snake.x[0] < 1 || snake.x[0] > width - 1 || snake.y[0] < 1 || snake.y[0] > height - 1) {
        return true;
    }
    for (int i = 1; i < snake.size; i++) {
        if (snake.x[0] == snake.x[i] && snake.y[0] == snake.y[i]) {
            return true;
        }
    }
    return false;
}

int main() {
    int width = 50; int height = 20;
    int foodX; int foodY; int score = 0;
    int stockx = 1; int stocky = 0; int ch; bool gameOver = false;
    Snake snake;
    initializeNcurses();
    WINDOW* win = initializeWindow(width, height);
    initializeSnake(snake, width, height);
    initializeFood(foodX, foodY, width, height);
    while (!gameOver) {
        drawFoodAndSnake(win, snake, foodX, foodY, score);
        ch = getch();
        mvwprintw(win, snake.y[snake.size - 1], snake.x[snake.size - 1], " ");
        displaySnake(win, snake);
        if (snake.x[0] == foodX && snake.y[0] == foodY) {
            snake.size++;
            score++;
            foodX = rand() % width -1;
            foodY = rand() % height-1;
        }
        gameOver = checkGameStatus(snake, width, height);
        mvwprintw(win, 0, 0, "Score: %d", score);
        mvwprintw(win, snake.y[snake.size - 1], snake.x[snake.size - 1], " ");
        updateSnakePosition(snake, stockx, stocky, ch);
        wrefresh(win);
    }
    wclear(win);
    while (getch() != 'q') {
        displayGameOver(win, score);
        if (getch() == 'q') {
            exit(0);
        } else{
            gameOver = false;
        }
    }
    endwin();
    return 0;
}