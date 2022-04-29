///////////////////////////////////////////////////////////////////////////////
// Tyler Perkins
// 28-4-22
// Routes implementation
//

#include "routes.hpp"

void setRoutes(crow::SimpleApp& app){
    CROW_ROUTE(app, "/proc/meminfo")([](const crow::request& req){
        if(!auth::checkAuth(req))
            return crow::response(403, "Authentication required");

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

    CROW_ROUTE(app, "/mem")([](const crow::request& req){
        if(!auth::checkAuth(req))
            return crow::response(403, "Authentication required");
        bool status;

        crow::json::wvalue json;
        status = memory::getEasyMem(json);
        return crow::response(status ? 200 : 503, json.dump());

    });

    CROW_ROUTE(app, "/proc/uptime")([](const crow::request& req){
        if(!auth::checkAuth(req))
            return crow::response(403, "Authentication required");
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

    CROW_ROUTE(app, "/uptime")([](const crow::request& req){
        if(!auth::checkAuth(req))
            return crow::response(403, "Authentication required");
        crow::response ret;
        ret.moved_perm("/proc/uptime");
        return ret;
    });

    CROW_ROUTE(app, "/proc/loadavg")([](const crow::request& req){
        if(!auth::checkAuth(req))
            return crow::response(403, "Authentication required");
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

    CROW_ROUTE(app, "/load")([](const crow::request& req){
        if(!auth::checkAuth(req))
            return crow::response(403, "Authentication required");
        crow::response ret;
        ret.moved_perm("/proc/loadavg");
        return ret;
    });

    CROW_ROUTE(app, "/proc/sys/kernel/hostname")([](const crow::request& req){
        if(!auth::checkAuth(req))
            return crow::response(403, "Authentication required");
        bool status;
        std::string accept = req.get_header_value("Accept");

        std::transform(accept.begin(), accept.end(), accept.begin(), ::tolower);

        if(accept == "text/plain"){
            accept.clear();
            status = state::getRawHostname(accept);
            return crow::response(status ? 200 : 503, accept);
        } else {
            crow::json::wvalue json;
            status = state::getHostname(json);
            return crow::response(status ? 200 : 503, json.dump());
        }
    });

    CROW_ROUTE(app, "/hostname")([](const crow::request& req){
        if(!auth::checkAuth(req))
            return crow::response(403, "Authentication required");
        crow::response ret;
        ret.moved_perm("/proc/sys/kernel/hostname");
        return ret;
    });

    CROW_ROUTE(app, "/up")([](const crow::request& req){
        if(!auth::checkAuth(req))
            return crow::response(403, "Authentication required");

        crow::json::wvalue ret;
        ret["message"] = "Alive and well!";
        return crow::response(200, ret.dump());
    });

    //catchall route
    CROW_CATCHALL_ROUTE(app)([](const crow::request& req){
        if(!auth::checkAuth(req))
            return crow::response(403, "Authentication required");
        crow::json::wvalue ret;
        ret["message"] = "Route not understood. Please refer to the documentation";

        return crow::response(404, ret.dump());
    });

}
