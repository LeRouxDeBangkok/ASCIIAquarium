#include "aquarium.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fish.h"

const char* BIG_FISH_RIGHT = "<+)))><";
const char* BIG_FISH_LEFT = "><(((+>";

void init_aquarium(Aquarium *aq, int w, int h) {
    aq->width = w;
    aq->height = h;
    aq->fish_count = MAX_FISH;

    bool line_used[100] = {false};

    for (int i = 0; i < aq->fish_count; i++) {
        aq->fish[i].x = rand_range(0, w - 10);
        int y;

        do {
            y = rand_range(0, h-1);
        } while (line_used[y]);
        line_used[y] = true;
        aq->fish[i].y = y;

        if (rand_range(0, 1) == 0) { //small fishes
            if (rand_range(0, 1) == 0) {
                aq->fish[i].dx = 1;
                aq->fish[i].sprite = "><>";
            } else {
                aq->fish[i].dx = -1;
                aq->fish[i].sprite = "<><";
            }
            aq->fish[i].length = 3;
        } else {
            if (rand_range(0, 1) == 0) { //big foosh
                aq->fish[i].dx = 1;
                aq->fish[i].sprite = BIG_FISH_RIGHT;
            } else {
                aq->fish[i].dx = -1;
                aq->fish[i].sprite = BIG_FISH_LEFT;
            }
            aq->fish[i].length = 7;
        }
    }
}

void update_aquarium(Aquarium *aq) {
    for (int i = 0; i < aq->fish_count; i++) {
        move_fish(&aq->fish[i], aq->width);
    }
}

void draw_aquarium(Aquarium *aq) {
    clear_screen(); // better than system("cls")

    for (int i = 0; i < aq->fish_count; i++) {
        set_cursor(aq->fish[i].x, aq->fish[i].y);
        printf("%s", aq->fish[i].sprite);
    }

    fflush(stdout);
}