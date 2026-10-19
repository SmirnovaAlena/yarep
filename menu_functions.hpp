#pragma once

#include "menu.hpp"

namespace IBusko {
    const MenuItem* show_menu(const MenuItem* current);
    const MenuItem* exit(const MenuItem* current);
    const MenuItem* go_back(const MenuItem* current);

    const MenuItem* algebra_sum(const MenuItem* current);
    const MenuItem* algebra_subtract(const MenuItem* current);
    const MenuItem* algebra_multiply(const MenuItem* current);
    const MenuItem* algebra_divide(const MenuItem* current);

    const MenuItem* matan_derivative(const MenuItem* current);
    const MenuItem* matan_integral(const MenuItem* current);
}