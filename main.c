#include "aquarium.h"
#include "utils.h"
#include <windows.h>

int main() {
    init_random();
    Aquarium aq;
    init_aquarium(&aq, 80, 20);

    while (1) {
        draw_aquarium(&aq);
        update_aquarium(&aq);
        update_bubbles(&aq);
        Sleep(200);
    }

    return 0;
}