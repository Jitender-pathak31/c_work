#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define HEIGHT 20
#define WIDTH 40

int snakeTailX[100], snakeTailY[100];
int snakeTailLen;
int gameover, key, score;
int x, y, fruitx, fruity;

void setup() {
    gameover = 0;
    key = 0; // Initialize key
    x = WIDTH / 2;
    y = HEIGHT / 2;

    fruitx = rand() % (WIDTH - 1) + 1; // Ensure fruit is not at (0,0)
    fruity = rand() % (HEIGHT - 1) + 1;
    
    score = 0;
}

void gotoxy(int x, int y){
    COORD coord;
    coord.x = x;
    
}

void draw() {
    system("cls");

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j <= WIDTH; j++) {
            if (j == 0 || j == WIDTH) {
                printf("#");
            } else if (i == y && j == x) {
                printf("0"); // Snake head
            } else if (i == fruity && j == fruitx) {
                printf("*"); // Fruit
            } else {
                int prTail = 0;
                for (int k = 0; k < snakeTailLen; k++) {
                    if (snakeTailX[k] == j && snakeTailY[k] == i) {
                        printf("!"); // Snake tail
                        prTail = 1;
                    }
                }
                if (!prTail) {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }

    for (int i = 0; i < WIDTH + 2; i++) {
        printf("-");
    }
    printf("\nScore: %d", score);
    printf("\nPress W, A, S, D for movement. \nPress X to quit the game.");
}

void input() {
    if (kbhit()) {
        switch (tolower(getch())) {
            case 'a':
                if (key != 2) key = 1; // Left
                break;
            case 'd':
                if (key != 1) key = 2; // Right
                break;
            case 'w':
                if (key != 4) key = 3; // Up
                break;
            case 's':
                if (key != 3) key = 4; // Down
                break;
            case 'x':
                gameover = 1; // Quit
                break;
        }
    }
}

void logic() {
    int prevX = snakeTailX[0];
    int prevY = snakeTailY[0];
    int prev2X, prev2Y;
    snakeTailX[0] = x;
    snakeTailY[0] = y;

    for (int i = 0; i < snakeTailLen; i++) {
        prev2X = snakeTailX[i];
        prev2Y = snakeTailY[i];
        snakeTailX[i] = prevX;
        snakeTailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (key) {
        case 1: x--; break; // Left
        case 2: x++; break; // Right
        case 3: y--; break; // Up
        case 4: y++; break; // Down
        default: break;               
    }

    if (x < 1 || x >= WIDTH || y < 1 || y >= HEIGHT) { // Adjust bounds
        gameover = 1;
    }

    for (int i = 0; i < snakeTailLen; i++) {
        if (snakeTailX[i] == x && snakeTailY[i] == y) {
            gameover = 1; // Collision with self
        }
    }

    if (x == fruitx && y == fruity) {
        fruitx = rand() % (WIDTH - 1) + 1;
        fruity = rand() % (HEIGHT - 1) + 1;
        score += 10;
        snakeTailLen++;
    }
}

int main() {
    setup();

    while (!gameover) {
        draw();
        input();
        logic();
        Sleep(33);
    }

    printf("\nGame Over! Final Score: %d\n", score); // Game over message
    return 0;
}
