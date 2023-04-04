/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** nibbler
*/

#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <utility>

struct nibbler {
    int x[101];
    int y[101];
    int size;
    int stockx;
    int stocky;
    bool blocked;
};

struct food
{
    int x;
    int y;
    bool isEaten;
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

void initializenibbler(nibbler& nibbler, int width, int height) {
    nibbler.x[0] = 25;
    nibbler.y[0] = 10;
    nibbler.size = 4;
    nibbler.stockx = 1;
    nibbler.stocky = 0;
    nibbler.blocked = false;
    for (int i = 1; i < nibbler.size; i++)
    {
        nibbler.x[i] = 25 - i;
        nibbler.y[i] = 25 - i;
    }
}


void displaynibbler(WINDOW* win, const nibbler& nibbler) {
    for (int i = 0; i < nibbler.size; i++) {
        mvwprintw(win, nibbler.y[i], nibbler.x[i], "x");
    }
}

void lookAroundHead(nibbler& nibbler, int ch, std::vector<std::pair<int, int>>& coords_w, 
std::vector<std::pair <int, int> >& coords_t) {
    int safe = 4;
    for (auto coord : coords_t) {
        if (coord.first == nibbler.x[0] + 1 && coord.second == nibbler.y[0] ||
        coord.first == nibbler.x[0] - 1 && coord.second == nibbler.y[0] ||
        coord.first == nibbler.x[0] && coord.second == nibbler.y[0]  + 1 ||
        coord.first == nibbler.x[0] && coord.second == nibbler.y[0] - 1)
        safe -= 1;
    }
    for (auto coord : coords_w) {
        if (coord.first == nibbler.x[0] + 1 && coord.second == nibbler.y[0] ||
        coord.first == nibbler.x[0] - 1 && coord.second == nibbler.y[0] ||
        coord.first == nibbler.x[0] && coord.second == nibbler.y[0]  + 1 ||
        coord.first == nibbler.x[0] && coord.second == nibbler.y[0] - 1)
        safe -= 1;
    }
    safe -=1;
    mvprintw(31, 50, "Safe = %d", safe);
}

void updatenibblerPosition1(nibbler& nibbler, int ch,
std::vector<std::pair<int, int>>& coords_o, std::vector<std::pair<int, int>>& coords_w, std::vector<std::pair <int, int> >& coords_t) {
    int newx = nibbler.x[0] + nibbler.stockx;
    int newy = nibbler.y[0] + nibbler.stocky;
    mvprintw(33, 50, "newy = %d = %d + %d",newy, nibbler.y[0] + nibbler.stocky);
    if (nibbler.stockx == 0 && nibbler.stocky == 0) {
        lookAroundHead(nibbler, ch, coords_w, coords_t);
        return;
    }
    //Vérifier si la nouvelle position est valide (pas de collision avec les murs)
    bool valid_position = true;
    for (auto coord : coords_w) {
         if (newx == coord.second && newy == coord.first) {
             valid_position = false;
             nibbler.blocked = true;
             break;
         }
    }
    for (auto coord : coords_t) {
         if (newx == coord.second && newy == coord.first) {
            valid_position = false;
            nibbler.blocked = true;
            break;
         }
    }
    if (valid_position == true) {
        //Vérifier si la nouvelle position contient de la nourriture
        for (int i = nibbler.size - 1; i > 0; i--) {
            if (nibbler.blocked == false) {
                nibbler.x[i] = nibbler.x[i - 1];
                nibbler.y[i] = nibbler.y[i - 1];
            }
        }
        bool contains_food = false;
        for (auto coord : coords_o) {
            if (newx == coord.second && newy == coord.first) {
                contains_food = true;
                break;
            }
        }
        // Mettre à jour la position de la tête du serpent
        nibbler.blocked = false;
        nibbler.x[0] = newx;
        nibbler.y[0] = newy;
        if (contains_food) {
            nibbler.size++;
        }
    }
}

void updatenibblerPosition(nibbler& nibbler, int ch,
 std::vector<std::pair<int, int>>& coords_o,
  std::vector<std::pair<int, int>>& coords_w,
   std::vector<std::pair <int, int> >& coords_t) {
    switch (ch) {
        case KEY_UP:
            nibbler.stockx = 0;
            nibbler.stocky = -1;
            updatenibblerPosition1(nibbler, ch, coords_o, coords_w, coords_t);
             nibbler.blocked = false;
            break;
        case KEY_DOWN:
            nibbler.blocked = false;
            nibbler.stockx = 0;
            nibbler.stocky = 1;
            updatenibblerPosition1(nibbler, ch, coords_o, coords_w, coords_t);
             nibbler.blocked = false;
            break;
        case KEY_LEFT:
            nibbler.stockx = -1;
            nibbler.stocky = 0;
            updatenibblerPosition1(nibbler, ch, coords_o, coords_w, coords_t);
             nibbler.blocked = false;
            break;
        case KEY_RIGHT:
            nibbler.blocked = false;
            nibbler.stockx = 1;
            nibbler.stocky = 0;
            updatenibblerPosition1(nibbler, ch, coords_o, coords_w, coords_t);
            nibbler.blocked = false;
            break;
        case ERR:
            if (nibbler.blocked == true) {
                nibbler.stockx = 0;
                nibbler.stocky = 0;
            }
            updatenibblerPosition1(nibbler, ch, coords_o, coords_w, coords_t);
            break;
    }
}

void displayGameOver(WINDOW* win, int score) {
    wclear(win);
    mvwprintw(win, 0, 0, "Score: %d", score);
    mvwprintw(win, 1, 0, "Game Over");
    mvwprintw(win, 2, 0, "Press r to play again");
    mvwprintw(win, 3, 0, "Press q to quit");
    wrefresh(win);
}

void get_map(WINDOW *win, std::vector<std::pair <int, int> >& coords_o)
{
    std::ifstream fichier("map.txt");
    std::string ligne;
        int y = 0;
        while(getline(fichier, ligne)) {
            // Parcours de la ligne pour trouver les positions des "o"
            for(int x = 0; x < ligne.size(); x++) {
                if(ligne[x] == 'o') {
                    std::pair <int, int> add = {y, x};
                    coords_o.push_back(add);
                }
            }
            y++;
        }
}

bool checkGameStatus(const nibbler& nibbler, int width, int height,
 std::vector<std::pair<int, int>>& coord, WINDOW* win) {
    if (nibbler.blocked != true) {
        for (int i = 1; i < nibbler.size; i++) {
            if (nibbler.x[0] == nibbler.x[i] && nibbler.y[0] == nibbler.y[i]) {
                return true;
            }
        }
    }
    if (coord.empty() == true) {
        get_map(win, coord);
    }
    return false;
}

void getWall(std::vector<std::pair <int, int> >& coords_w, WINDOW *win)
{
    std::ifstream fichier("map.txt");
    std::string ligne;
        int y = 0;
        while(getline(fichier, ligne)) {
            // Parcours de la ligne pour trouver les positions des "-"
            for(int x = 0; x < ligne.size(); x++) {
                if(ligne[x] == '-') {
                    std::pair <int, int> add = {y, x};
                    coords_w.push_back(add);
                }
            }
            y++;
        }
}

void getWallT(std::vector<std::pair <int, int> >& coords_t, WINDOW *win)
{
    std::ifstream fichier("map.txt");
    std::string ligne;
        int y = 0;
        while(getline(fichier, ligne)) {
            // Parcours de la ligne pour trouver les positions des "|"
            for(int x = 0; x < ligne.size(); x++) {
                if(ligne[x] == '|') {
                    std::pair <int, int> add = {y, x};
                    coords_t.push_back(add);
                }
            }
            y++;
        }
}

void checkcollision(nibbler& nibbler, std::vector<std::pair <int, int> >& coords_o,
std::vector<std::pair <int, int> >& coords_w, std::vector<std::pair <int, int> >& coords_t, 
int& score)
{
    for (int i = 0; i < coords_o.size(); i++) {
        if (nibbler.x[0] + nibbler.stockx == coords_o[i].second + nibbler.stocky && nibbler.y[0] == coords_o[i].first) {
            score++;
            coords_o.erase(coords_o.begin() + i);
            nibbler.size++;
        }
    }
    for (int i = 0; i < coords_w.size(); i++) {
        if (nibbler.x[0] + nibbler.stockx == coords_w[i].second && nibbler.y[0] + nibbler.stocky == coords_w[i].first) {
            nibbler.blocked = true;
        }
    }
    for (int i = 0; i < coords_t.size(); i++) {
        if (nibbler.x[0] + nibbler.stockx == coords_t[i].second && nibbler.y[0] + nibbler.stocky == coords_t[i].first) {
            nibbler.blocked = true;
        }
    }
}

int nibblergame() {
    int width = 50; int height = 20; int score = 0; int ch;
    bool gameOver = false;
    nibbler nibbler;
    initializeNcurses();
    WINDOW* win = initializeWindow(width, height);
    std::vector<std::pair <int, int> > coords_o;
    std::vector<std::pair <int, int> > coords_w;
    std::vector<std::pair <int, int> > coords_t;
    get_map(win, coords_o);
    getWall(coords_w, win);
    getWallT(coords_t, win);
    initializenibbler(nibbler, width, height);
    while (!gameOver) {
        wclear(win);
        ch = getch();
        mvwprintw(win, nibbler.y[nibbler.size - 1], nibbler.x[nibbler.size - 1], " ");
        displaynibbler(win, nibbler);
        mvprintw(30, 50, "Score: %d", score);
        mvprintw(32, 50, "coord x = %d, y = %d", nibbler.x[0], nibbler.y[0]);
        checkcollision(nibbler, coords_o, coords_w, coords_t, score);
        updatenibblerPosition(nibbler, ch, coords_o, coords_w, coords_t);
        for(auto &coord : coords_o) {
            mvwprintw(win, coord.first, coord.second, "o");
        }
        for(auto &coord1 : coords_w) {
            mvwprintw(win, coord1.first, coord1.second, "-");
        }
        for(auto &coord2 : coords_t) {
            mvwprintw(win, coord2.first, coord2.second, "|");
        }
        gameOver = checkGameStatus(nibbler, width, height, coords_o, win);
        wrefresh(win);
    }
    wclear(win);
    while (getch() != 'q') {
        displayGameOver(win, score);
        switch (getch())
        {
        case 'q':
            endwin();
            exit(0);
            break;
        case 'r':
            nibblergame();
            break;
        }
    }
    return 0;
}

int main() {
    nibblergame();
    return 0;
}