#include </opt/homebrew/include/SDL2/SDL.h>
#include </opt/homebrew/include/SDL2/SDL_image.h>
#include </opt/homebrew/include/SDL2/SDL_ttf.h>
#include <iostream>
#include <string>

using namespace std;

// Définition des constantes de la fenêtre
const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;
const char *WINDOW_TITLE = "Arcade";

// Définition des constantes pour le texte
const char *FONT_PATH = "arial.ttf";
const int FONT_SIZE = 36;
const int FONT_SIZE_Title = 72;
const SDL_Color FONT_COLOR_Title = {255, 255, 255, 255};
const SDL_Color FONT_COLOR = {255, 255, 255, 255};
const int COLUMN_PADDING = 400;

// Fonction pour afficher du texte sur la surface
void drawText(SDL_Renderer *renderer, TTF_Font *font, const std::string &text,
              int x, int y)
{
    // Création de la surface de texte
    SDL_Surface *textSurface =
        TTF_RenderText_Solid(font, text.c_str(), FONT_COLOR);

    // Création de la texture à partir de la surface
    SDL_Texture *textTexture =
        SDL_CreateTextureFromSurface(renderer, textSurface);

    // Rendu de la texture
    SDL_Rect textRect = {x, y, textSurface->w, textSurface->h};
    SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);

    // Nettoyage de la surface et de la texture
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
}

int main(int argc, char *argv[])
{
    // Initialisation de SDL2 et de SDL_ttf
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    string LibChoices[3] = {"OpenGl", "Ncurses", "SDL2"};
    string GameLibChoices[2] = {"Nibbler", "Snake"};
    int arcadeX = SCREEN_WIDTH / 2 - COLUMN_PADDING;
    int gamesX = SCREEN_WIDTH / 2 - COLUMN_PADDING / 2 - 100;
    int y = 400;
    string game;
    string lib;
    int finish = 1;

    // Création de la fenêtre
    SDL_Window *window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                                          SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    // Création du renderer
    SDL_Renderer *renderer =
        SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);

    // Chargement de la police d'écriture
    TTF_Font *font = TTF_OpenFont(FONT_PATH, FONT_SIZE);
    TTF_Font *fontTitle = TTF_OpenFont(FONT_PATH, FONT_SIZE_Title);
    // Chargement de l'image de fond
    SDL_Surface *backgroundImage = IMG_Load("background.jpg");
    SDL_Texture *backgroundTexture =
        SDL_CreateTextureFromSurface(renderer, backgroundImage);

    // Boucle de gestion des événements
    bool quit = false;
    while (!quit) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }

            // Gestion des clics de souris
            if (event.type == SDL_MOUSEBUTTONDOWN) {
                if (event.button.y >= 450 && event.button.y <= 500 &&
                    event.button.x >= gamesX &&
                    event.button.x <= gamesX + 200) {
                    // Clic sur OpenGL
                    lib = LibChoices[0];
                    cout << "You clicked on OpenGL" << endl;
                } else if (event.button.y >= 500 && event.button.y <= 550 &&
                           event.button.x >= gamesX &&
                           event.button.x <= gamesX + 200) {
                    // Clic sur Ncurses
                    lib = LibChoices[1];
                    cout << "You clicked on Ncurses" << endl;
                } else if (event.button.y >= 550 && event.button.y <= 600 &&
                           event.button.x >= gamesX &&
                           event.button.x <= gamesX + 200) {
                    // Clic sur SDL2
                    cout << "You clicked on SDL2" << endl;
                    lib = LibChoices[2];
                } else if (event.button.y >= 450 && event.button.y <= 500 &&
                           event.button.x >= gamesX + COLUMN_PADDING &&
                           event.button.x <= gamesX + COLUMN_PADDING + 200) {
                    // Clic sur Nibbler
                    game = GameLibChoices[0];
                    cout << "You clicked on Nibbler" << endl;
                } else if (event.button.y >= 500 && event.button.y <= 550 &&
                           event.button.x >= gamesX + COLUMN_PADDING &&
                           event.button.x <= gamesX + COLUMN_PADDING + 200) {
                    game = GameLibChoices[1];
                    cout << "Game selected: Snake" << endl;
                } else if (event.button.y >= y + 450  && event.button.y <= y + 500 &&
                           event.button.x >= gamesX + COLUMN_PADDING &&
                           event.button.x <= gamesX + COLUMN_PADDING + 200) {
                    if (lib != "" && game != "") {
                        finish = 0;
                    }
                }
            }

            // Mise à jour de l'affichage
        }
        // Effacement de l'écran
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
        //  Affichage des colonnes de texte
        if (finish == 0) {
            drawText(renderer, font, "Game selected: " + game + " with " + lib,
                     gamesX + COLUMN_PADDING, y + 600);
        }
        drawText(renderer, fontTitle, "Arcade", arcadeX + 300, y - 100);
        drawText(renderer, font, "Choose a game:", gamesX, y);
        drawText(renderer, font, "OpenGL", gamesX, y + 50);
        drawText(renderer, font, "Ncurses", gamesX, y + 100);
        drawText(renderer, font, "SDL2", gamesX, y + 150);
        drawText(renderer, font,
                 "Choose a library:", gamesX - 100 + COLUMN_PADDING, y);
        drawText(renderer, font, "Nibbler", gamesX + COLUMN_PADDING, y + 50);
        drawText(renderer, font, "Snake", gamesX + COLUMN_PADDING, y + 100);
        drawText(renderer, font, "Game selected: " + game,
                 gamesX + COLUMN_PADDING, y + 200);
        drawText(renderer, font, "Library selected: " + lib,
                 gamesX + COLUMN_PADDING, y + 250);
        drawText(renderer, font, "Click here to start the game",
                 gamesX + COLUMN_PADDING, y + 450);
        SDL_RenderPresent(renderer);
    }

    // Destruction de la fenêtre, du renderer et de la police d'écriture
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    // Arrêt de SDL2 et de SDL_ttf
    TTF_Quit();
    SDL_Quit();

    return 0;
}
