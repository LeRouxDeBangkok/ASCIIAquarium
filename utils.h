#ifndef ASCIIAQUARIUM_UTILS_H
#define ASCIIAQUARIUM_UTILS_H

#pragma once
#include <windows.h>

void set_cursor(int x, int y);
void clear_screen();
int rand_range(int min, int max);
void init_random();

#endif //ASCIIAQUARIUM_UTILS_H