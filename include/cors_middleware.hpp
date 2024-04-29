#pragma once

#ifndef COMPUTATIONALMATHLAB2_CORS_MIDDLEWARE_HPP
#define COMPUTATIONALMATHLAB2_CORS_MIDDLEWARE_HPP

#include <drogon/drogon.h>

using namespace drogon;

#include <drogon/drogon.h>

using namespace drogon;

typedef std::function<void(const HttpResponsePtr &)> Callback;

void cors_handler(const HttpRequestPtr &request, Callback &&callback) {
    auto response = HttpResponse::newHttpResponse();
    response->addHeader("Access-Control-Allow-Origin", "*");
    response->addHeader("Access-Control-Allow-Methods", "GET, POST, PUT, DELETE, OPTIONS");
    response->addHeader("Access-Control-Allow-Headers", "X-Requested-With, Content-Type");
    callback(response);
}

#endif
