///////////////////////////////////////////////////////////////////////////////
// Tyler Perkins
// 28-4-22
// Routes implementation
//

#include "routes.hpp"

void setRoutes(crow::SimpleApp& app){
    CROW_ROUTE(app, "/proc/meminfo")([]{
        crow::json::wvalue json;
        memory::getProcMem(json);

        return json;
    });

    CROW_ROUTE(app, "/mem")([]{
        return "mem";
    });
}
