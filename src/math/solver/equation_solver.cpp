#include "math/solver/equation_solver.hpp"

#include <cmath>

#include "math/variable.hpp"
#include "math/functions/minus.hpp"

Equation_solver::Equation_solver(double approximation, Expression *a) : Solver(approximation), _a(a) {}

Equation_solver::~Equation_solver() {
    delete _a;
}

std::vector<std::vector<bool>> Equation_solver::get_matrix() {
    auto *expression = new Minus(new Var("y"), _a);

    constexpr double DIMENSION = 2000;

    auto res = std::vector(DIMENSION, std::vector(DIMENSION, false));

    for (int it = 0; it < DIMENSION; ++it) {
        for (int jt = 0; jt < DIMENSION; ++jt) {
            std::unordered_map<std::string, double> values = {
                {"x", (it - DIMENSION / 2) * 20 / DIMENSION},
                {"y", (DIMENSION / 2 - jt) * 20 / DIMENSION}
            };
            // std::cout << (it - DIMENSION / 2) * 10 / DIMENSION << " " << (DIMENSION / 2 - jt) * 10 / DIMENSION << " " << expression->process(values) << std::endl;
            res[it][jt] = std::abs(expression->process(values)) < 0.01;
        }
    }

    return res;
}

double Equation_solver::_approximate_root() const {
    double range = 1;

    while (range < 1000) {
        constexpr double step = 0.05;
        for (double it = -range / 2.0; it < range / 2; it += step) {
            std::unordered_map<std::string, double> values_prev = {
                {"x", it - step / 2}
            };
            std::unordered_map<std::string, double> values_next = {
                {"x", it + step / 2}
            };
            if (_a->process(values_prev) * _a->process(values_next) < 0) {
                return std::round(it);
            }
        }
        range *= 2;
    }
    throw std::invalid_argument("Невозможно найти приблизительную границу для метода");
}
