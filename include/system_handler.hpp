#pragma once

#ifndef COMPUTATIONALMATHLAB2_SYSTEM_HANDLER_HPP
#define COMPUTATIONALMATHLAB2_SYSTEM_HANDLER_HPP

#include <drogon/drogon.h>

using namespace drogon;

typedef std::function<void(const HttpResponsePtr &)> Callback;

void system_handler(const HttpRequestPtr &request, Callback &&callback) {

    std::cout << request->body() << std::endl;

    Json::Value jsonBody;
    jsonBody["message"] = "Sasi 2!!!";
    auto response = HttpResponse::newHttpJsonResponse(jsonBody);
    response->addHeader("Access-Control-Allow-Origin", "*");
    response->addHeader("Access-Control-Allow-Methods", "GET, POST, PUT, DELETE, OPTIONS");
    response->addHeader("Access-Control-Allow-Headers", "X-Requested-With, Content-Type");
    callback(response);
}

#endif
