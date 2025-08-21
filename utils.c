#include "utils.h"
#include <stdlib.h>
#include <time.h>

void set_cursor(int x, int y) {
    COORD pos = { x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void clear_screen() {
    system("cls");
}

int rand_range(int min, int max) {
    return min + rand() % (max - min + 1);
}

void init_random() {
    srand((unsigned int)time(NULL));
}