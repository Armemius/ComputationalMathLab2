#pragma once

#ifndef COMPUTATIONALMATHLAB2_SYSTEM_SOLVER_HPP
#define COMPUTATIONALMATHLAB2_SYSTEM_SOLVER_HPP

#include "solver.hpp"
#include "math/expression.hpp"

class System_solver : public Solver {
public:
    Expression *_a, *_b;

    explicit System_solver(double approximation, Expression *a, Expression *b);

    ~System_solver() override;

    void solve() override = 0;

    std::vector<std::vector<bool>> get_matrix() override;
};

#endif
