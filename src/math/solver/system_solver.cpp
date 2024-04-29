#include "math/solver/system_solver.hpp"


System_solver::System_solver(double approximation, Expression *a, Expression *b) : Solver(approximation), _a(a), _b(b) {}

System_solver::~System_solver() {
    delete _a;
    delete _b;
}

std::vector<std::vector<bool>> System_solver::get_matrix() {
    return {};
}
