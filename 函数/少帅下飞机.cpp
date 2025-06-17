#include <stdio.h>
#include <windows.h>

#define WIDTH 80
#define STOP_POSITION WIDTH - 1

void drawPlane(int x) {
    system("cls");
    for (int j = 0; j < WIDTH; j++) {
        if (j >= x - 4 && j <= x + 4) {
            printf("▓");
        }
        else if (j == x - 4) {
            printf("/▓飞机");
        }
        else if (j == x + 4) {
            printf("▓\\");
        }
        else if (j == x - 5) {
            printf("?");
        }
        else if (j == x + 5) {
            printf("?");
        }
        else if (j == x - 3) {
            printf("╚");
        }
        else if (j == x + 3) {
            printf("╝");
        }
        else {
            printf(" ");
        }
    }
    printf("\n");
}

void drawWords(int y) {
    system("cls");
    if (y >= 0) {
        for (int i = 0; i < WIDTH; i++) {
            if (i == WIDTH / 2 - 4 && y == 0) {
                printf("士");
            }
            else if (i == WIDTH / 2 - 3 && y == 0) {
                printf("兵");
            }
            else if (i == WIDTH / 2 && y == 0) {
                printf("少");
            }
            else if (i == WIDTH / 2 + 1 && y == 0) {
                printf("帅");
            }
            else if (i == WIDTH / 2 + 4 && y == 0) {
                printf("士");
            }
            else if (i == WIDTH / 2 + 5 && y == 0) {
                printf("兵");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
    if (y >= 1) {
        for (int i = 0; i < WIDTH; i++) {
            if (i == WIDTH / 2 - 4 && y == 1) {
                printf("士");
            }
            else if (i == WIDTH / 2 - 3 && y == 1) {
                printf("兵");
            }
            else if (i == WIDTH / 2 && y == 1) {
                printf("少");
            }
            else if (i == WIDTH / 2 + 1 && y == 1) {
                printf("帅");
            }
            else if (i == WIDTH / 2 + 4 && y == 1) {
                printf("士");
            }
            else if (i == WIDTH / 2 + 5 && y == 1) {
                printf("兵");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
    if (y >= 2) {
        for (int i = 0; i < WIDTH; i++) {
            if (i == WIDTH / 2 - 4 && y == 2) {
                printf("士");
            }
            else if (i == WIDTH / 2 - 3 && y == 2) {
                printf("兵");
            }
            else if (i == WIDTH / 2 && y == 2) {
                printf("少");
            }
            else if (i == WIDTH / 2 + 1 && y == 2) {
                printf("帅");
            }
            else if (i == WIDTH / 2 + 4 && y == 2) {
                printf("士");
            }
            else if (i == WIDTH / 2 + 5 && y == 2) {
                printf("兵");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
    if (y >= 3) {
        for (int i = 0; i < WIDTH; i++) {
            if (i == WIDTH / 2 - 4 && y == 3) {
                printf("士");
            }
            else if (i == WIDTH / 2 - 3 && y == 3) {
                printf("兵");
            }
            else if (i == WIDTH / 2 && y == 3) {
                printf("少");
            }
            else if (i == WIDTH / 2 + 1 && y == 3) {
                printf("帅");
            }
            else if (i == WIDTH / 2 + 4 && y == 3) {
                printf("士");
            }
            else if (i == WIDTH / 2 + 5 && y == 3) {
                printf("兵");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
    if (y >= 4) {
        for (int i = 0; i < WIDTH; i++) {
            if (i == WIDTH / 2 - 4 && y == 4) {
                printf("士");
            }
            else if (i == WIDTH / 2 - 3 && y == 4) {
                printf("兵");
            }
            else if (i == WIDTH / 2 && y == 4) {
                printf("少");
            }
            else if (i == WIDTH / 2 + 1 && y == 4) {
                printf("帅");
            }
            else if (i == WIDTH / 2 + 4 && y == 4) {
                printf("士");
            }
            else if (i == WIDTH / 2 + 5 && y == 4) {
                printf("兵");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int x = 0;
    int y = -1;
    while (x < WIDTH) {
        drawPlane(x);
        x++;
        Sleep(100);
    }
    while (y < 5) {
        drawPlane(STOP_POSITION);
        drawWords(y);
        y++;
        Sleep(200);
    }
    system("pause");
    return 0;
}
