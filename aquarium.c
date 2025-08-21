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
    aq->bubble_count = MAX_BUBBLES;

    for (int i = 0; i < aq->bubble_count; i++) {
        aq->bubbles[i].x = rand_range(0, aq->width - 1);
        aq->bubbles[i].y = rand_range(0, aq->height - 1);
        aq->bubbles[i].symbol = (rand_range(0, 1) == 0) ? 'o' : '.';
    }

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

void update_bubbles(Aquarium* aq) {
    for (int i = 0; i < aq->bubble_count; i++) {
        aq->bubbles[i].y--;
        if (aq->bubbles[i].y < 0) {
            aq->bubbles[i].y = aq->height - 1;
            aq->bubbles[i].x = rand_range(0, aq->width -1);
            aq->bubbles[i].symbol = (rand_range(0, 1) == 0) ? 'o' : '.';
        }
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
        set_cursor(aq->fish[i].x, aq->fish[i].y);
        printf("%s", aq->fish[i].sprite);
    }

    for (int b = 0; b < aq->bubble_count; b++) {
        set_cursor(aq->bubbles[b].x, aq->bubbles[b].y);
        putchar(aq->bubbles[b].symbol);
    }

    fflush(stdout);
}