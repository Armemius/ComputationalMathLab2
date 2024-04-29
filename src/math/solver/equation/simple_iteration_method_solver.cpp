#include "math/solver/equation/simple_iteration_method_solver.hpp"

#include <cmath>

Simple_iteration_method_solver::Simple_iteration_method_solver(double approximation, Expression *a) : Equation_solver(
    approximation, a) {
}
void Simple_iteration_method_solver::solve() {
    double curr = this->_approximate_root();
    double prev = curr - 1;
    double step = 1;
    double lambda = -std::numeric_limits<double>::infinity();
    _report += "## Метод простой итерации \n\r\n\r";
    _report += "Корень находится в районе точки x=" + std::to_string(_approximate_root()) + " \n\r\n\r";
    _report += "Допустимая погрешность: " + std::to_string(_approximation) + " \n\r\n\r";
    _report += "Возьмём точку x = " + std::to_string(prev) + " за нулевое приближение \n\r\n\r";
    _report += "И точку x = " + std::to_string(curr) + " для первой итерации \n\r\n\r";
    for (double it = curr - 0.5; it <= curr + 0.5; it += step) {
        std::unordered_map<std::string, double> value = {
            {"x", it}
        };
        lambda = std::max(lambda, std::abs(_a->derivative("x")->process(value)));
    }
    lambda = -1 / lambda;
    _report += "Параметр лямбда = " + std::to_string(lambda) + "\n\r\n\r";
    int iteration = 1;
    while (std::abs(curr - prev) > _approximation) {
        _report += "#### Итерация №" + std::to_string(iteration++) + " \n\r\n\r";
        prev = curr;
        std::unordered_map<std::string, double> value = {
            {"x", curr}
        };
        curr = curr + lambda * _a->process(value);
        _report += "x_i = " + std::to_string(curr) + " x_(i-1) = " + std::to_string(prev) + "\n\r\n\r";
        _report += "Абсолютная разница между двумя последними итерациями: " + std::to_string(std::abs(curr - prev)) + "\n\r\n\r";
    }
    _report += "Ответ: " + std::to_string(curr);
}
