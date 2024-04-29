#pragma once

#ifndef COMPUTATIONALMATHLAB2_EQUATION_SOLVER_HPP
#define COMPUTATIONALMATHLAB2_EQUATION_SOLVER_HPP

#include "solver.hpp"
#include "math/expression.hpp"

class Equation_solver : public Solver {
protected:
    Expression *_a;
    double _approximate_root() const;
public:
    explicit Equation_solver(double approximation, Expression *a);

    ~Equation_solver() override;

    void solve() override = 0;

    std::vector<std::vector<bool>> get_matrix() override;
};

#endif
