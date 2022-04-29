///////////////////////////////////////////////////////////////////////////////
// Tyler Perkins
// 28-4-22
// Entry point
//

#include <iostream>
#include <crow.h>
#include "opt/parseopt.hpp"

#include "routes.hpp"

int main(int argc, char** argv){

    option_flags* flags = parse_options(argc, argv);

    crow::SimpleApp app;

    setRoutes(app);

    app.port(flags->port)
        .server_name(flags->name)
        .multithreaded();

    delete flags;

    app.run();
}
