#include <iostream>
#include <drogon/drogon.h>
#include "math/parser.hpp"
#include "cors_middleware.hpp"
#include "equation_handler.hpp"
#include "system_handler.hpp"

using namespace drogon;

int main() {
    app()
            .registerHandler("/equation", &cors_handler, {Options})
            .registerHandler("/equation", &equation_handler, {Post})
            .registerHandler("/system", &cors_handler, {Options})
            .registerHandler("/system", &system_handler, {Post})
            .addListener("0.0.0.0", 3000)
            .enableServerHeader(false)
            .run();
    return EXIT_SUCCESS;
}
