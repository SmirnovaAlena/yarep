#pragma once

namespace IBusko {
    struct MenuItem {
        const char* title;
        const MenuItem* (*func)(const MenuItem* current);
        const MenuItem* parent;
        
        const MenuItem* const* children = nullptr;
        int children_count = 0;
    };
}