#include "fish.h"
#include <stdio.h>
#include "utils.h"

void move_fish(Fish *f, int width) {
    f->x += f->dx;
    if (f->x < 0) {
        f->x = 0;
        f->dx = 1;
    } else if (f->x + f->length >= width) {
        f->x = width - f->length;
        f->dx = -1;
    }
}

void draw_fish(const Fish *f) {
    set_cursor(f->x, f->y);
    printf("%s", f->sprite);
}