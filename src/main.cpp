///////////////////////////////////////////////////////////////////////////////
// Tyler Perkins
// 28-4-22
// Entry point
//

#include <iostream>
#include <crow.h>

int main(int argc, char** argv){
    crow::SimpleApp app;
    CROW_ROUTE(app, "/")([](){
        return "Hello World";
    });

    CROW_ROUTE(app, "/json")([]{
        crow::json::wvalue response({{ "message", "Hello world" }});
        response["kek"] = "nay, cringe";
        return response;
    });

    app.port(5000).run();
}
