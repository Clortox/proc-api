///////////////////////////////////////////////////////////////////////////////
// Tyler Perkins
// 28-4-22
// Routes implementation
//

#include "routes.hpp"

void setRoutes(crow::SimpleApp& app){
    CROW_ROUTE(app, "/proc/meminfo")([](const crow::request& req){
        crow::json::wvalue json;
        bool status;
        std::string accept = req.get_header_value("Accept");

        std::transform(accept.begin(), accept.end(), accept.begin(), ::tolower);

        if(accept == "text/plain"){
            accept.clear();
            status = memory::getRawProcMem(accept);
            return crow::response(status ? 200 : 503, accept);
        } else {
            status = memory::getProcMem(json);
            return crow::response(status ? 200 : 503, json.dump());
        }
    });

    CROW_ROUTE(app, "/proc/uptime")([](const crow::request& req){
        crow::json::wvalue json;
        bool status;
        std::string accept = req.get_header_value("Accept");

        std::transform(accept.begin(), accept.end(), accept.begin(), ::tolower);

        if(accept == "text/plain"){
            accept.clear();
            status = state::getRawUptime(accept);
            return crow::response(status ? 200 : 503, accept);
        } else {
            status = state::getUptime(json);
            return crow::response(status ? 200: 503, json.dump());
        }
    });

    CROW_ROUTE(app, "/mem")([]{
        return "mem";
    });

}
