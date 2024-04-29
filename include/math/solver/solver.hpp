#pragma once

#ifndef COMPUTATIONALMATHLAB2_SOLVER_HPP
#define COMPUTATIONALMATHLAB2_SOLVER_HPP

#include <string>
#include <vector>

#include "math/expression.hpp"

class Solver {
protected:
    std::string _report = "";
    double _approximation;

public:
    explicit Solver(double approximation);

    virtual ~Solver() = default;

    virtual void solve() = 0;

    const std::string &get_report();

    virtual std::vector<std::vector<bool>> get_matrix() = 0;
};

#endif
