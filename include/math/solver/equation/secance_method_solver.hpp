#pragma once

#ifndef SECANCE_METHOD_SOLVER_HPP
#define SECANCE_METHOD_SOLVER_HPP

#include "math/solver/equation_solver.hpp"

class Secance_method_solver final : public Equation_solver {
public:
    explicit Secance_method_solver(double approximation, Expression *a);
    void solve() override;
};

#endif
