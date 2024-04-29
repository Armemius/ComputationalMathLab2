#include "math/solver/equation/half_split_method_solver.hpp"

Half_split_method_solver::Half_split_method_solver(double approximation, Expression *a) : Equation_solver(
    approximation, a) {
    const double anchor = _approximate_root();

}

void Half_split_method_solver::solve() {
    const double anchor = this->_approximate_root();
    double range = 5;
    double a = anchor - range, b = anchor + range;
    _report += "## Метод половинного деления \n\r\n\r";
    _report += "### Оценка границ \n\r\n\r";
    _report += "Корень находится в районе точки x=" + std::to_string(anchor) + " \n\r\n\r";
    _report += "Допустимая погрешность: " + std::to_string(_approximation) + " \n\r\n\r";

    std::unordered_map<std::string, double> a_value = {
        {"x", a}
    };
    std::unordered_map<std::string, double> b_value = {
        {"x", b}
    };

    while (_a->process(a_value) * _a->process(b_value) > 0) {
        range /= 2;
        a = anchor - range, b = anchor + range;
        a_value = {
            {"x", a}
        };
        b_value = {
            {"x", b}
        };
    }
    _report += "Пускай a =" + std::to_string(a) + " и b =" + std::to_string(b) + " \n\r\n\r";
    int iteration = 1;
    while (b - a > _approximation) {
        _report += "#### Итерация №" + std::to_string(iteration++)+ " \n\r\n\r";
        double c = (a + b) / 2;
        _report += "a = " + std::to_string(a) + ", b = " + std::to_string(b) + " и с = (a + b) / 2 = " +
                std::to_string(c) + " \n\r\n\r";
        std::unordered_map<std::string, double> c_value = {
            {"x", c}
        };
        if (_a->process(a_value) * _a->process(c_value) > 0) {
            _report += "f(a)f(c) > 0, a = c \n\r\n\r";
            a = c;
            a_value = {
                {"x", a}
            };
        } else {
            _report += "f(a)f(c) < 0, b = c \n\r\n\r";
            b = c;
            b_value = {
                {"x", b}
            };
        }
        _report += "Размер интервала: " + std::to_string(b - a) + " \n\r\n\r";
    }
    _report += "Ответ: " + std::to_string((a+b) / 2);
}
