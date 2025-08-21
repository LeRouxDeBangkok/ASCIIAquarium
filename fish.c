#include "fish.h"
#include <stdio.h>
#include "utils.h"

void move_fish(Fish *f, int width) {
    f->x += f->dx;
    if (f->x < 0) {
        f->x = 0;
        f->dx = 1;
    } else if (f->x >= width) {
        f->x = width - 1;
        f->dx = -1;
    }
}

void draw_fish(const Fish *f) {
    set_cursor(f->x, f->y);
    printf("%c", f->symbol);
}