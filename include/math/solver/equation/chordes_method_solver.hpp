#pragma once

#ifndef CHORDES_METHOD_SOLVER_HPP
#define CHORDES_METHOD_SOLVER_HPP

#include "math/solver/equation_solver.hpp"

class Chordes_method_solver final : public Equation_solver {
public:
    explicit Chordes_method_solver(double approximation, Expression *a);
    void solve() override;
};

#endif
