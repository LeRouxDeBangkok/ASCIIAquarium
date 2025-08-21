#ifndef ASCIIAQUARIUM_FISH_H
#define ASCIIAQUARIUM_FISH_H

#pragma once

typedef struct Fish {
    int x, y;
    int dx;
    const char* sprite;
    int length;
} Fish;

void move_fish(Fish* f, int width);

void draw_fish(const Fish* f);

#endif //ASCIIAQUARIUM_FISH_H