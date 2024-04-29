#pragma once

#ifndef COMPUTATIONALMATHLAB2_HALF_SPLIT_METHOD_SOLVER_HPP
#define COMPUTATIONALMATHLAB2_HALF_SPLIT_METHOD_SOLVER_HPP

#include "math/solver/equation_solver.hpp"

class Half_split_method_solver final : public Equation_solver {
public:
    explicit Half_split_method_solver(double approximation, Expression *a);
    void solve() override;
};

#endif
