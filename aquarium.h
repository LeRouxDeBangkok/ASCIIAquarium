#ifndef ASCIIAQUARIUM_AQUARIUM_H
#define ASCIIAQUARIUM_AQUARIUM_H

#pragma once
#include "fish.h"

#define MAX_FISH 10
#define MAX_BUBBLES 20

typedef struct Bubble {
    int x, y;
    char symbol;
} Bubble;

typedef struct Aquarium {
    int width, height;
    int fish_count;
    Fish fish[MAX_FISH];
    int bubble_count;
    Bubble bubbles[MAX_BUBBLES];
} Aquarium;

void init_aquarium(Aquarium *aq, int w, int h);
void update_aquarium(Aquarium *aq);
void draw_aquarium(Aquarium *aq);
void update_bubbles(Aquarium* aq);

#endif //ASCIIAQUARIUM_AQUARIUM_H