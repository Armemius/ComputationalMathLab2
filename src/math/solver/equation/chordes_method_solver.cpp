#include "math/solver/equation/chordes_method_solver.hpp"

#include <cfloat>

#include "math/variable.hpp"

Chordes_method_solver::Chordes_method_solver(double approximation, Expression *a) : Equation_solver(
    approximation, a) {
}

void Chordes_method_solver::solve() {
    double anchor = _approximate_root() - 1.0;
    double curr = anchor + 1.0;
    _report += "## Метод хорд \n\r\n\r";
    _report += "Корень находится в районе точки x=" + std::to_string(_approximate_root()) + " \n\r\n\r";
    _report += "Допустимая погрешность: " + std::to_string(_approximation) + " \n\r\n\r";
    _report += "Возьмём точку x = " + std::to_string(anchor) + " за нулевое приближение \n\r\n\r";
    _report += "И точку x = " + std::to_string(curr) + " для первой итерации \n\r\n\r";
    auto prev = DBL_MAX;
    int iteration = 1;
    while (std::abs(curr - prev) > _approximation) {
        _report += "#### Итерация №" + std::to_string(iteration++)+ " \n\r\n\r";
        prev = curr;
        std::unordered_map<std::string, double> value = {
            {"x", curr}
        };
        std::unordered_map<std::string, double> anchor_value = {
            {"x", anchor}
        };
        curr = anchor - (_a->process(anchor_value) * (curr - anchor)) / (
                   _a->process(value) - _a->process(anchor_value));
        _report += "x_i = " + std::to_string(curr) + " x_(i-1) = " + std::to_string(prev) + "\n\r\n\r";
        _report += "Абсолютная разница между двумя последними итерациями: " + std::to_string(std::abs(curr - prev)) + "\n\r\n\r";
    }
    _report += "Ответ: " + std::to_string(curr);
}
