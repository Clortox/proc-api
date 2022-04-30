///////////////////////////////////////////////////////////////////////////////
// Tyler Perkins
// 28-4-22
// Entry point
//

#include <iostream>
#include <crow.h>
#include "opt/parseopt.hpp"
#include "auth/auth.hpp"

auth::auth_check* auth::auth_check::checker;

#include "routes.hpp"

int main(int argc, char** argv){

    option_flags* flags = parse_options(argc, argv);

    if(!flags->auth_path.empty()){
        auth::auth_check::checker = new auth::auth_check(flags->auth_path);
        CROW_LOG_INFO << "Added authorization using authfile " << flags->auth_path;
    }

    crow::SimpleApp app;

    setRoutes(app);

    app.port(flags->port)
        .server_name(flags->name)
        .concurrency(flags->threads);

    delete flags;

    app.run();
}
