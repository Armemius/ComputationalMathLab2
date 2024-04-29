#pragma once

#ifndef SIMPLE_ITERATION_METHOD_SOLVER_HPP
#define SIMPLE_ITERATION_METHOD_SOLVER_HPP

#include "math/solver/equation_solver.hpp"

class Simple_iteration_method_solver final : public Equation_solver {
public:
    explicit Simple_iteration_method_solver(double approximation, Expression *a);
    void solve() override;
};

#endif
