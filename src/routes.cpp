///////////////////////////////////////////////////////////////////////////////
// Tyler Perkins
// 28-4-22
// Routes implementation
//

#include "routes.hpp"

void setRoutes(crow::SimpleApp& app){
    CROW_ROUTE(app, "/proc/meminfo")([](const crow::request& req){
        crow::json::wvalue json;

        std::cerr << "Accept: " << req.get_header_value("Accept") << "\n";

        if(memory::getProcMem(json))
            return crow::response(200, json.dump());
        else
            return crow::response(503, json.dump());
    });

    CROW_ROUTE(app, "/mem")([]{
        return "mem";
    });
}
