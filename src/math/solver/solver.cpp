#include "math/solver/solver.hpp"


Solver::Solver(double approximation) : _approximation(approximation) {}

const std::string &Solver::get_report() {
    return this->_report;
}
