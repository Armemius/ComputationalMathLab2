#pragma once

#ifndef NEWTON_METHOD_SOLVER_HPP
#define NEWTON_METHOD_SOLVER_HPP

#include "math/solver/equation_solver.hpp"

class Newton_method_solver final : public Equation_solver {
public:
    explicit Newton_method_solver(double approximation, Expression *a);
    void solve() override;
};

#endif
