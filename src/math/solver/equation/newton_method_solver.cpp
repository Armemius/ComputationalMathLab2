#include "math/solver/equation/newton_method_solver.hpp"

#include <cmath>
#include <cfloat>

#include "math/variable.hpp"
#include "math/functions/divide.hpp"
#include "math/functions/minus.hpp"

Newton_method_solver::Newton_method_solver(double approximation, Expression *a) : Equation_solver(
    approximation, a) {
}

void Newton_method_solver::solve() {
    double curr = _approximate_root() + 1.0;
    auto prev = curr - 1.0;
    _report += "## Метод Ньютона \n\r\n\r";
    _report += "Корень находится в районе точки x=" + std::to_string(_approximate_root()) + " \n\r\n\r";
    _report += "Допустимая погрешность: " + std::to_string(_approximation) + " \n\r\n\r";
    _report += "Возьмём точку x = " + std::to_string(prev) + " за нулевое приближение \n\r\n\r";
    _report += "И точку x = " + std::to_string(curr) + " для первой итерации \n\r\n\r";
    int iteration = 1;
    while (std::abs(curr - prev) > _approximation) {
        _report += "#### Итерация №" + std::to_string(iteration++) + " \n\r\n\r";
        prev = curr;
        std::unordered_map<std::string, double> value = {
            {"x", curr}
        };
        curr = curr - (_a->process(value) / _a->derivative("x")->process(value));
        _report += "x_i = " + std::to_string(curr) + " x_(i-1) = " + std::to_string(prev) + "\n\r\n\r";
        _report += "Абсолютная разница между двумя последними итерациями: " + std::to_string(std::abs(curr - prev)) + "\n\r\n\r";
    }
    _report += "Ответ: " + std::to_string(curr);
}
