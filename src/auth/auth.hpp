///////////////////////////////////////////////////////////////////////////////
// Tyler Perkins
// 29-4-22
// Auth definition
//

#pragma once

#include <crow.h>
#include <unordered_set>
#include <string>
#include <fstream>

constexpr char AUTH_HEADER[] = "Authorization";

namespace auth{
    class auth_check {
    public:
        auth_check(std::string&);
        ~auth_check();

        static auth_check* checker;

        bool checkAuth(const crow::request&) const;

    private:
        std::unordered_set<std::string> tokens;
    };

    bool checkAuth(const crow::request&);
}
