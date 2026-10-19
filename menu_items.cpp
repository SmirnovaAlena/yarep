#include "menu_items.hpp"
#include <cstddef>
#include "menu_functions.hpp"

const IBusko::MenuItem IBusko::ALGEBRA_SUM = {
    "1 - Хочу научиться складывать!", IBusko::algebra_sum, &IBusko::ALGEBRA
};
const IBusko::MenuItem IBusko::ALGEBRA_SUBTRACT = {
    "2 - Хочу научиться вычитать!", IBusko::algebra_subtract, &IBusko::ALGEBRA
};
const IBusko::MenuItem IBusko::ALGEBRA_MULTIPLY = {
    "3 - Хочу научиться умножать!", IBusko::algebra_multiply, &IBusko::ALGEBRA
};
const IBusko::MenuItem IBusko::ALGEBRA_DIVIDE = {
    "4 - Хочу научиться делить!", IBusko::algebra_divide, &IBusko::ALGEBRA
};

const IBusko::MenuItem IBusko::MATAN_DERIVATIVE = {
    "1 - Хочу изучить дифференциальное исчисление!", IBusko::matan_derivative, &IBusko::MATAN
};
const IBusko::MenuItem IBusko::MATAN_INTEGRAL = {
    "2 - Хочу изучить интегральное исчисление!", IBusko::matan_integral, &IBusko::MATAN
};

const IBusko::MenuItem IBusko::STUDY_GO_BACK = {
    "0 - Выйти в главное меню", IBusko::go_back, &IBusko::STUDY
};
const IBusko::MenuItem IBusko::ALGEBRA_GO_BACK = {
    "0 - Вернуться к выбору предметов", IBusko::go_back, &IBusko::ALGEBRA
};
const IBusko::MenuItem IBusko::MATAN_GO_BACK = {
    "0 - Вернуться к выбору предметов", IBusko::go_back, &IBusko::MATAN
};

namespace {
    const IBusko::MenuItem* const algebra_children[] = {
        &IBusko::ALGEBRA_GO_BACK,
        &IBusko::ALGEBRA_SUM,
        &IBusko::ALGEBRA_SUBTRACT,
        &IBusko::ALGEBRA_MULTIPLY,
        &IBusko::ALGEBRA_DIVIDE
    };
    const int algebra_size = sizeof(algebra_children) / sizeof(algebra_children[0]);

    const IBusko::MenuItem* const matan_children[] = {
        &IBusko::MATAN_GO_BACK,
        &IBusko::MATAN_DERIVATIVE,
        &IBusko::MATAN_INTEGRAL
    };
    const int matan_size = sizeof(matan_children) / sizeof(matan_children[0]);

    const IBusko::MenuItem* const study_children[] = {
        &IBusko::STUDY_GO_BACK,
        &IBusko::ALGEBRA,
        &IBusko::MATAN
    };
    const int study_size = sizeof(study_children) / sizeof(study_children[0]);

    const IBusko::MenuItem* const main_children[] = {
        &IBusko::EXIT,
        &IBusko::STUDY
    };
    const int main_size = sizeof(main_children) / sizeof(main_children[0]);
}

const IBusko::MenuItem IBusko::ALGEBRA = {
    "1 - Хочу изучать алгебру!", IBusko::show_menu, &IBusko::STUDY, algebra_children, algebra_size
};

const IBusko::MenuItem IBusko::MATAN = {
    "2 - Хочу изучать математический анализ!", IBusko::show_menu, &IBusko::STUDY, matan_children, matan_size
};

const IBusko::MenuItem IBusko::STUDY = {
    "1 - Хочу учиться математике!", IBusko::show_menu, &IBusko::MAIN, study_children, study_size
};

const IBusko::MenuItem IBusko::EXIT = {
    "0 - Я лучше пойду полежу...", IBusko::exit, &IBusko::MAIN
};

const IBusko::MenuItem IBusko::MAIN = {
    nullptr, IBusko::show_menu, nullptr, main_children, main_size
};