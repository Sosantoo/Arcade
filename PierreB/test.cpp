#include <ncurses.h>
#include <iostream>


int main() {
    initscr();  // Initialise la bibliothèque NCurses

    // Définit un timeout de 5 secondes pour getch()
    wtimeout(stdscr, 5000);

    // Utilise getch() pour attendre l'entrée de l'utilisateur pendant 5 secondes
    int ch = getch();
    std::cout << "getch() a retourné:" << ch << std::endl;
    if (ch == ERR) {
        // Si le timeout est dépassé, getch() retourne ERR
        std::cout << "Timeout dépassé" << std::endl;
    } else {
        // Sinon, getch() retourne la valeur de la touche pressée
        std::cout << "Touche pressée: " << ch << std::endl;
    }
    while (1)
    {
        /* code */
    }
    // Restaure le timeout par défaut
    wtimeout(stdscr, -1);
    endwin();   // Termine la bibliothèque NCurses
    return 0;
}
