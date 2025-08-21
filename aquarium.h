#ifndef ASCIIAQUARIUM_AQUARIUM_H
#define ASCIIAQUARIUM_AQUARIUM_H

#pragma once
#include "fish.h"

#define MAX_FISH 10

typedef struct Aquarium {
    int width, height;
    int fish_count;
    Fish fish[MAX_FISH];
} Aquarium;

void init_aquarium(Aquarium *aq, int w, int h);
void update_aquarium(Aquarium *aq);
void draw_aquarium(Aquarium *aq);

#endif //ASCIIAQUARIUM_AQUARIUM_H