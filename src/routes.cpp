///////////////////////////////////////////////////////////////////////////////
// Tyler Perkins
// 28-4-22
// Routes implementation
//

#include "routes.hpp"

void setRoutes(crow::SimpleApp& app){
    CROW_ROUTE(app, "/proc/meminfo")([](const crow::request& req){
        bool status;
        std::string accept = req.get_header_value("Accept");

        std::transform(accept.begin(), accept.end(), accept.begin(), ::tolower);

        if(accept == "text/plain"){
            accept.clear();
            status = memory::getRawProcMem(accept);
            return crow::response(status ? 200 : 503, accept);
        } else {
            crow::json::wvalue json;
            status = memory::getProcMem(json);
            return crow::response(status ? 200 : 503, json.dump());
        }
    });

    CROW_ROUTE(app, "/mem")([](){
        bool status;

        crow::json::wvalue json;
        status = memory::getEasyMem(json);
        return crow::response(status ? 200 : 503, json.dump());

    });

    CROW_ROUTE(app, "/proc/uptime")([](const crow::request& req){
        bool status;
        std::string accept = req.get_header_value("Accept");

        std::transform(accept.begin(), accept.end(), accept.begin(), ::tolower);

        if(accept == "text/plain"){
            accept.clear();
            status = state::getRawUptime(accept);
            return crow::response(status ? 200 : 503, accept);
        } else {
            crow::json::wvalue json;
            status = state::getUptime(json);
            return crow::response(status ? 200: 503, json.dump());
        }
    });

    CROW_ROUTE(app, "/uptime")([](){
        crow::response ret;
        ret.moved_perm("/proc/uptime");
        return ret;
    });

    CROW_ROUTE(app, "/proc/loadavg")([](const crow::request& req){
        bool status;
        std::string accept = req.get_header_value("Accept");

        std::transform(accept.begin(), accept.end(), accept.begin(), ::tolower);

        if(accept == "text/plain"){
            accept.clear();
            status = state::getRawLoadAvg(accept);
            return crow::response(status ? 200 : 503, accept);
        } else {
            crow::json::wvalue json;
            status = state::getLoadAvg(json);
            return crow::response(status ? 200 : 503, json.dump());
        }
    });

    CROW_ROUTE(app, "/load")([](){
        crow::response ret;
        ret.moved_perm("/proc/loadavg");
        return ret;
    });

}
