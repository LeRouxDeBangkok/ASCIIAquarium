#include "aquarium.h"
#include "utils.h"

void init_aquarium(Aquarium *aq, int w, int h) {
    aq->width = w;
    aq->height = h;
    aq->fish_count = MAX_FISH;

    for (int i = 0; i < aq->fish_count; i++) {
        aq->fish[i].x = rand_range(0, w - 1);
        aq->fish[i].y = rand_range(0, h - 1);
        aq->fish[i].dx = (rand_range(0, 1) == 0) ? 1 : -1;
        aq->fish[i].symbol = (rand_range(0, 1) == 0) ? '><' : 'o';
    }
}

void update_aquarium(Aquarium *aq) {
    for (int i = 0; i < aq->fish_count; i++) {
        move_fish(&aq->fish[i], aq->width);
    }
}

void draw_aquarium(Aquarium *aq) {
    clear_screen();
    for (int i = 0; i < aq->fish_count; i++) {
        draw_fish(&aq->fish[i]);
    }
}