#include "menu.hpp"
#include "menu_items.hpp"

int main() {
    const IBusko::MenuItem* current = &IBusko::MAIN;
    
    do {
        current = current->func(current);
    } while (true);

    return 0;
}