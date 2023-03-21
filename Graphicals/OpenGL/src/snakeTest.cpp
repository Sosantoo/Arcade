/*
 * Maze Generator:
 *   Made by Jaden Peterson in 2016
 */

/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <deque>
#include <GL/glut.h>
#include <sstream>
#include <functional>
#include <iostream>
#include <map>

// A macro for unused variables (to bypass those pesky G++ warnings)
#define UNUSED(param) (void)(param)

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT,
};

const char title[] = "OpenGL Snake";

const float map_half_length = 30.0f;

Direction direction = Direction::DOWN;
bool moved = false;
const int move_speed = 100;
std::deque< std::deque<float> > part_coords;

bool food_available = false;
int food_coords[2];

int score = 0;

int growth_stage = 0;
const int growth = 2;

void drawFood(){
    glLoadIdentity();
    glTranslatef(food_coords[0], food_coords[1], -40.0f);
    glColor3f(1.0f, 0.0f, 0.0f);

    glBegin(GL_POLYGON);
        glVertex2d( 1.0f,  1.0f);
        glVertex2d( 1.0f, -1.0f);
        glVertex2d(-1.0f, -1.0f);
        glVertex2d(-1.0f,  1.0f);
    glEnd();
}

void spawnFood(){
    if(food_available){
        return;
    }

    int temp_food_coords[2];
    bool collides;

    do {
        collides = false;

        // Produce a temporary random coordinate
        temp_food_coords[0] = 2 * (rand() % ((int) map_half_length + 1)) - (int) map_half_length;
        temp_food_coords[1] = 2 * (rand() % ((int) map_half_length + 1)) - (int) map_half_length;

        // Does it collide with the snake?
        for(unsigned int a = 0; a < part_coords.size(); a++){
            if(temp_food_coords[0] == part_coords[a][0] &&
               temp_food_coords[1] == part_coords[a][1]){
                collides = true;
            }
        }
    } while(collides);

    food_coords[0] = temp_food_coords[0];
    food_coords[1] = temp_food_coords[1];

    food_available = true;
}

void drawBitmapText(char* text, float x, float y, float z) {
    char* c;

    glLoadIdentity();
    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos3f(x, y, z);

    for(c = text; *c != '\0'; c++){
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *c);
    }
}

void drawControls(){
    char* move_message = (char*) "Use WASD or the arrow keys to move";
    char* exit_message = (char*) "Press ESC or Q to exit";

    drawBitmapText(move_message, map_half_length - 32.0f, map_half_length - 2.0f, -39.5f);
    drawBitmapText(exit_message, map_half_length - 21.0f, map_half_length - 4.0f, -39.5f);
}

void drawScore(){
    const char* score_message = (char*) "Score: ";
    const char* length_message = (char*) "Length: ";
    std::stringstream score_string;
    std::stringstream length_string;

    score_string << score_message << score;
    length_string << length_message << part_coords.size();

    drawBitmapText((char*) score_string.str().c_str(), -map_half_length + 1.0f, map_half_length - 2.0f, -39.5f);
    drawBitmapText((char*) length_string.str().c_str(), -map_half_length + 1.0f, map_half_length - 4.0f, -39.5f);
}

void drawSnake(){
     // Loop over snake size and draw each part at it's respective coordinates
    for(unsigned int a = 0; a < part_coords.size(); a++){
        glLoadIdentity();
        glTranslatef(part_coords[a][0], part_coords[a][1], -40.0f);
        glColor3f(0.0f, 1.0f, 0.0f);

        glBegin(GL_POLYGON);
            glVertex2d( 1.0f,  1.0f);
            glVertex2d( 1.0f, -1.0f);
            glVertex2d(-1.0f, -1.0f);
            glVertex2d(-1.0f,  1.0f);
        glEnd();
    }
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    drawSnake();

    spawnFood();
    drawFood();

    drawScore();
    drawControls();

    glutSwapBuffers();
}

void moveSnake(Direction new_direction){
    int last_part = part_coords.size() - 1;
    std::deque<float> new_head = part_coords[last_part];

    float delta_x = 0.0f;
    float delta_y = 0.0f;

    float map_edge = 0.0f;

    int snake_part_axis = 0;

    std::map<Direction, std::function<void()>> eventHandler {
        {UP, [&]() {
            delta_y = 2.0f;
            map_edge = map_half_length;
            snake_part_axis = 1;
        }},
        {DOWN, [&]() {
            delta_y = -2.0f;
            map_edge = -map_half_length;
            snake_part_axis = 1;
        }},
        {LEFT, [&]() {
            delta_x = 2.0f;
            map_edge = map_half_length;
            snake_part_axis = 0;
        }},
        {RIGHT, [&]() {
            delta_x = -2.0f;
            map_edge = -map_half_length;
            snake_part_axis = 0;
        }},
    };
    eventHandler[new_direction]();
    direction = new_direction;

    // Did we slither into ourself?
    for(unsigned int a = 0; a < part_coords.size(); a++){
        if(part_coords[0][0] + delta_x == part_coords[a][0] &&
           part_coords[0][1] + delta_y == part_coords[a][1]){
            exit(0);
        }
    }

    // Did we slither into a wall?
    if(part_coords[0][snake_part_axis] == map_edge){
        exit(0);
    }

    // Did we get food?
    if(part_coords[0][0] + delta_x == food_coords[0] &&
       part_coords[0][1] + delta_y == food_coords[1]){
        score += 50;
        growth_stage++;
        food_available = false;
    }

    new_head[0] = part_coords[0][0] + delta_x;
    new_head[1] = part_coords[0][1] + delta_y;

    part_coords.push_front(new_head);

    if(!growth_stage){
        part_coords.pop_back();
    } else if(growth_stage == growth){
        growth_stage = 0;
    } else {
        growth_stage++;
    }

    glutPostRedisplay();
}

void moveSnakeAuto(int value){
    if(!moved){
        UNUSED(value);
        moveSnake(direction);
    } else {
        moved = false;
    }

    glutTimerFunc(move_speed, moveSnakeAuto, 0);
}

void initGL(){
    glMatrixMode(GL_PROJECTION);
    gluPerspective(76.0f, 1.0f, 0.0f, 40.0f);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void keyboard(unsigned char key, int x, int y){
    UNUSED(x);
    UNUSED(y);

    std::map<int, std::function<void()>> eventHandler {
        {'w', [&]() {
             if(direction == LEFT || direction == RIGHT){
                moved = true;
                moveSnake(UP);
            }
        }},
        {'s', [&]() {
            if(direction == LEFT || direction == RIGHT){
                moved = true;
                moveSnake(DOWN);
            }
        }},
        {'a', [&]() {
            if(direction == UP || direction == DOWN){
                moved = true;
                moveSnake(LEFT);
            }
        }},
        {'d', [&]() {
            if(direction == UP || direction == DOWN){
                moved = true;
                moveSnake(RIGHT);
            }
        }},
        {27, [&]() { exit(0); }},
        {'q', [&]() { exit(0); }},
    };
    eventHandler[key]();
}

void special(int key, int x, int y){
    UNUSED(x);
    UNUSED(y);

    std::map<int, std::function<void()>> eventHandler {
        {GLUT_KEY_UP, [&]() {
             if(direction == LEFT || direction == RIGHT){
                moved = true;
                moveSnake(UP);
            }
        }},
        {GLUT_KEY_DOWN, [&]() {
            if(direction == LEFT || direction == RIGHT){
                moved = true;
                moveSnake(DOWN);
            }
        }},
        {GLUT_KEY_LEFT, [&]() {
            if(direction == UP || direction == DOWN){
                moved = true;
                moveSnake(LEFT);
            }
        }},
        {GLUT_KEY_RIGHT, [&]() {
            if(direction == UP || direction == DOWN){
                moved = true;
                moveSnake(RIGHT);
            }
        }},
    };
    eventHandler[key]();
}

void reshape(GLsizei width, GLsizei height){
    UNUSED(width);
    UNUSED(height);

    // Make the window non-resizable so we don't have to worry about size changes
    glutReshapeWindow(600, 600);
}

int launchSnakeTest(int argc, char** argv) {
    glutInit(&argc, argv);

    glutInitWindowSize(600, 600);
    glutCreateWindow(title);

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);
    glutSpecialFunc(special);
    glutTimerFunc(move_speed, moveSnakeAuto, 0);

    const int initSize = 3;

    // Specify the coordinates to each part of the snake
    for(int a = 1; a <= initSize; a++){
        std::deque<float> row;

        row.push_back(0.0f);
        row.push_back((map_half_length + 2.0f + (initSize * 2)) - (a * 2));

        part_coords.push_front(row);
    }

    srand(time(NULL));

    initGL();
    glutMainLoop();

    return 0;
}