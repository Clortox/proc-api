///////////////////////////////////////////////////////////////////////////////
// Tyler Perkins
// 29-4-22
// Auth definition
//

#include "auth.hpp"

bool auth::checkAuth(const crow::request& req){
    if(auth::auth_check::checker == nullptr)
        return true;
    else
        return auth::auth_check::checker->checkAuth(req);
}

auth::auth_check::auth_check(std::string& path){
    std::ifstream f (path);

    if(f.is_open()){
        std::string line;
        while(std::getline(f, line)){
            tokens.insert(line);
        }
    }
    f.close();
}

auth::auth_check::~auth_check(){
    //nothing to clean up
}

bool auth::auth_check::checkAuth(const crow::request& req) const {
    if(tokens.find(req.get_header_value(AUTH_HEADER)) != tokens.end())
        return true;
    else
        return false;
}
