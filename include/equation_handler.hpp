#pragma once

#ifndef COMPUTATIONALMATHLAB2_EQUATION_HANDLER_HPP
#define COMPUTATIONALMATHLAB2_EQUATION_HANDLER_HPP

#include <drogon/drogon.h>
#include "math/parser.hpp"
#include "math/solver/equation/chordes_method_solver.hpp"
#include "math/solver/equation/half_split_method_solver.hpp"
#include "math/solver/equation/newton_method_solver.hpp"
#include "math/solver/equation/secance_method_solver.hpp"
#include "math/solver/equation/simple_iteration_method_solver.hpp"

using namespace drogon;

typedef std::function<void(const HttpResponsePtr &)> Callback;

void equation_handler(const HttpRequestPtr &request, Callback &&callback) {
    const auto &json = *request->jsonObject();
    std::string equation = json["equation"].asString();
    std::string method = json["method"].asString();
    equation.erase(std::remove_if(equation.begin(), equation.end(), ::isspace),
             equation.end());
    Expression *func = parse(equation);

    Solver *solver;
    if (method == "simple-iteration") {
        solver = new Simple_iteration_method_solver(0.01, func);
    } else if (method == "half-splitting-method") {
        solver = new Half_split_method_solver(0.01, func);
    } else if (method == "chordes-method") {
        solver = new Chordes_method_solver(0.01, func);
    } else if (method == "newton-method") {
        solver = new Newton_method_solver(0.01, func);
    } else if (method == "secant-method") {
        solver = new Secance_method_solver(0.01, func);
    }

    solver->solve();

    Json::Value jsonBody;
    auto matrix = solver->get_matrix();
    std::string matrix_encoded = "";
    for (size_t it = 0; it < matrix.size(); ++it) {
        for (size_t jt = 0; jt < matrix.size(); ++jt) {
            matrix_encoded += matrix[it][jt] ? "1" : "0";
        }
    }
    jsonBody["message"] = solver->get_report();
    jsonBody["matrix"] = matrix_encoded;
    callback(HttpResponse::newHttpJsonResponse(jsonBody));
}

void equation_handler_options(const HttpRequestPtr &request, Callback &&callback) {
    std::cout << request->body() << std::endl;
    Json::Value jsonBody;
    jsonBody["message"] = "Sasat!!!";
    auto response = HttpResponse::newHttpJsonResponse(jsonBody);
    callback(response);
}

#endif
