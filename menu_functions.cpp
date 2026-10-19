#include "menu_functions.hpp"
#include <cstdlib>
#include <iostream>
#include <limits>

namespace {
    bool read_two_numbers(double& a, double& b) {
        std::cout << "Введите два числа: ";
        if (!(std::cin >> a >> b)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка: нужно ввести два числа." << std::endl;
            return false;
        }
        return true;
    }
}

const IBusko::MenuItem* IBusko::show_menu(const MenuItem* current) {
    std::cout << "Обучайка приветствует тебя, мой юный ученик!" << std::endl;
    
    for (int i = 1; i < current->children_count; ++i) {
        std::cout << current->children[i]->title << std::endl;
    }
    std::cout << current->children[0]->title << std::endl;
    std::cout << "Обучайка > ";

    int user_input = 0;
    if (!(std::cin >> user_input)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Ошибка: нужно ввести число." << std::endl;
        return current;
    }

    if (user_input < 0 || user_input >= current->children_count) {
        std::cout << "Нет такого пункта." << std::endl;
        return current;
    }

    return current->children[user_input];
}

const IBusko::MenuItem* IBusko::exit(const MenuItem*) {
    std::exit(0);
}

const IBusko::MenuItem* IBusko::go_back(const MenuItem* current) {
    if (current->parent != nullptr && current->parent->parent != nullptr) {
        return current->parent->parent;
    }
    if (current->parent != nullptr) {
        return current->parent;
    }
    return current;
}

const IBusko::MenuItem* IBusko::algebra_sum(const MenuItem* current) {
    double a = 0.0;
    double b = 0.0;
    if (read_two_numbers(a, b)) {
        std::cout << a << " + " << b << " = " << (a + b) << std::endl;
    }
    return current->parent;
}

const IBusko::MenuItem* IBusko::algebra_subtract(const MenuItem* current) {
    double a = 0.0;
    double b = 0.0;
    if (read_two_numbers(a, b)) {
        std::cout << a << " - " << b << " = " << (a - b) << std::endl;
    }
    return current->parent;
}

const IBusko::MenuItem* IBusko::algebra_multiply(const MenuItem* current) {
    double a = 0.0;
    double b = 0.0;
    if (read_two_numbers(a, b)) {
        std::cout << a << " * " << b << " = " << (a * b) << std::endl;
    }
    return current->parent;
}

const IBusko::MenuItem* IBusko::algebra_divide(const MenuItem* current) {
    double a = 0.0;
    double b = 0.0;
    if (!read_two_numbers(a, b)) {
        return current->parent;
    }
    
    if (b == 0.0) {
        std::cout << "На ноль делить нельзя." << std::endl;
    } else {
        std::cout << a << " / " << b << " = " << (a / b) << std::endl;
    }
    return current->parent;
}

const IBusko::MenuItem* IBusko::matan_derivative(const MenuItem* current) {
    std::cout << "Дифференциальное исчисление изучает скорость изменения функции." << std::endl;
    std::cout << "Пример: (x^2)' = 2x, (sin x)' = cos x." << std::endl;
    return current->parent;
}

const IBusko::MenuItem* IBusko::matan_integral(const MenuItem* current) {
    std::cout << "Интегральное исчисление собирает целое из частей." << std::endl;
    std::cout << "Пример: integral(2x dx) = x^2 + C." << std::endl;
    return current->parent;
}