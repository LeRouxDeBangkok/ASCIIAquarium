#include "aquarium.h"
#include "utils.h"
#include <windows.h>

int main() {
    init_random();
    Aquarium aq;
    init_aquarium(&aq, 80, 20);

    while (1) {
        update_aquarium(&aq);
        draw_aquarium(&aq);
        Sleep(200);
    }

    return 0;
}