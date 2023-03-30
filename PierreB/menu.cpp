/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** ncurses
*/

#include <ncurses.h>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
    initscr();
    cbreak();
    noecho();

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    WINDOW *menuWin = newwin(15, xMax -100, yMax /2, 30);
    box(menuWin, 0, 0);
    refresh();
    wrefresh(menuWin);
    keypad(menuWin, TRUE);

    string LibChoices[3] = {"OpenGl", "Ncurses", "SDL2"};
    string GameLibChoices[2] = {"Nibbler", "Snake"};
    int choice;
    int choice2;
    int highlight = 0;
    int highlight2 = 0;

    while (1) {
        attron(A_BOLD);
        mvwprintw(menuWin, 1, xMax / 3 - 15, "Arcade");
        attroff(A_BOLD);
        mvwprintw(menuWin, 4, xMax / 2 - 27, "Choose a library :");
        for (int i = 0; i < 3; i += 1) {
            if (i == highlight)
                wattron(menuWin, A_REVERSE);
            mvwprintw(menuWin, i + 5, xMax / 5 - 20, LibChoices[i].c_str());
            wattroff(menuWin, A_REVERSE);
        }
        mvwprintw(menuWin, 4, xMax / 4 - 32, "Choose a game :");
        for (int i = 0; i < 2; i += 1) {
            if (i == highlight2)
                wattron(menuWin, A_REVERSE);
            mvwprintw(menuWin, i + 5, xMax / 3 +10 , GameLibChoices[i].c_str());
            wattroff(menuWin, A_REVERSE);
        }
        choice = wgetch(menuWin);
        switch (choice) {
        case KEY_UP:
            highlight--;
            if (highlight == -1)
                highlight = 0;
            break;
        case KEY_DOWN:
            highlight++;
            if (highlight == 3)
                highlight = 2;
            break;
        case KEY_LEFT:
            highlight2--;
            if (highlight2 == -1)
                highlight2 = 0;
            break;
        case KEY_RIGHT:
            highlight2++;
            if (highlight2 == 2)
                highlight2 = 1;
            break;
        default: break;
        }
        if (choice == 10)
            break;
    }
    printw("You choose choice %d with choice string %s\n", highlight,
           LibChoices[highlight].c_str());
    getch();
    endwin();
    return 0;
}
